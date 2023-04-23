64-bit Pawn Coding
==================

With the release of open.mp came the option to run your server in 64-bit.  By default the pawn component in this new server is still 32-bit, as basically every script ever is implicitly written with this limitation in mind; however, it is possible to also have pawn compiled to load and run scripts written with a 64-bit VM.  We *must* point out that this mode of operation is very very "you're on your own" territory - no plugins are ported to 64-bit, the components have not been tested much at all, and many pawn libraries also don't work.  If you're willing to accept these extreme restrictions, or if you're a writer of one of those unported pawn libraries, read on.

Firstly - what's the problem?  Why won't normal code work?  Well it actually might.  If your code is purely functions and maths you're probably good, the code might even work better because there's less chance of an overflow.  Simple (and fairly complex) code such as the following, recompiled for 64-bit, will function just fine:

```pawn
new num = 7;
new rand = random(num);
new total = rand * 1001;
```

The problem only comes when you have code that deals with the bits and bytes of cells directly.  If your code has `&`, `|`, `>>`, `>>>`, or `<<` you're more likely to need to edit something.  If your code has `#emit`, you'll almost certainly have to change a lot.

Negative Numbers
----------------

Because numbers are twice as wide the negative sign bit has moved; it is no longer the 31st bit but the 63rd bit.  A negative test may have been written as:

```pawn
bool:IsNegative1(num)
{
	return num & 0x80000000;
}
```

Or:

```pawn
bool:IsNegative2(num)
{
	return num >>> 31;
}
```

It should be noted that this is a fairly arbitrary example, and the standard negative test using normal mathematical operations will continue working perfectly:

```pawn
bool:IsNegative3(num)
{
	return num < 0;
}
```

Having said that, the alternate versions can be fixed by using in-built constants, namely `cellmin` (either `0x80000000` or `0x8000000000000000` depending on the compiler) and `cellbits` (either `32` or `64` depending on the compiler):

```pawn
bool:IsNegative1(num)
{
	return num & cellmin;
}

bool:IsNegative2(num)
{
	return num >>> (cellbits - 1);
}
```

Similarly isolating the numeric component of a number can be done with `cellmin` or `cellmax`:

```pawn
bool:NumericComponent1(num)
{
	return num & cellmax;
}

bool:NumericComponent1(num)
{
	return num & ~cellmin;
}
```

Hexadecimal
-----------

A hex number such as `0x1234FEDC` is a number defined in terms of individual bits, and as the number of bits has changed some hex values will need to change as well.  `-1` in 32-but hex is `0xFFFFFFFF`, in 64-bit hex it becomes `0xFFFFFFFFFFFFFFFF`.  You could do this with `#if`:

```pawn
#if cellbits == 64
	new MINUS_1 = 0xFFFFFFFFFFFFFFFF;
#else
	new MINUS_1 = 0xFFFFFFFF;
#endif
```

You could use some technique for extending the sign in to the top bits:

```pawn
#if cellbits == 64
	#define SIGN_EXTEND(%0) ((%0) | ((%0) >> 31 << 63 >> 31))
#else
	#define SIGN_EXTEND(%0) ((%0))
#endif

new MINUS_1 = SIGN_EXTEND(0xFFFFFFFF);
```

Or it might not matter.  For example colours often use hex because it is easy to distinguish between the red, green, blue, and alpha components; each of which is one byte.  `0xFF0000AA` is a semi-transparent red, with no blue or green.  Although this is technically a negative number in 32-bit only these four bytes are ever used to specify the colour in the server itself so it doesn't matter if the negative bit is extended or not.  Thus no change is needed.

It is quite common that you only need a 32-bit number even when running on a 64-bit server; such as the colour example above, and several other server data types that reflect protocol data of a fixed size.  Thus YSI has a mask for exactly this case:

```pawn
#if cellbits == 64
	#define __32(%0) ((%0)&0xFFFFFFFF)
#else
	#define __32(%0) (%0)
#endif
```

Using:

```pawn
new colour = __32(someColourSourceThatMayBeSigned);
```

Will mask out the unused bits only when appropriate.

This information equally applies to binary (`0b100101`) numbers.

Bit Maps
--------

A lot of code uses a single cell to store thirty-two individual booleans together at once, and arrays of said packs to store even more bits.  While there are both pros- and cons- to this technique, it must be covered.  The first option is - just ignore the problem.  Generally this code should continue to work fine (unless it is very poorly written), simply wasting half the available bits and using twice as much memory as required.  Maybe that's an acceptable loss, but maybe not given that the point of these arrays was to save as much memory as possible.

The core algorithm of a large bit array is:

```pawn
SetBit(array[], bit, bool:value)
{
	if (value)
	{
		array[bit >>> 5] |= (1 << (bit & 0x1F));
	}
	else
	{
		array[bit >>> 5] &= ~(1 << (bit & 0x1F));
	}
}
```

`32` appears multiple times in this code - if you look VERY VERY closely:

```pawn
SetBit(array[], bit, bool:value)
{
	if (value)
	{
		array[bit >>> log2(32)] |= (1 << (bit & (32 - 1)));
	}
	else
	{
		array[bit >>> log2(32)] &= ~(1 << (bit & (32 - 1)));
	}
}
```

So to fix this code we need to replace those `32`s with `64`s.  Unlike `cellmin` there's no default define for the log-base-two of the current bit width, so we must make one:

```pawn
#if cellbits == 64
	const celllog = 6;
#elseif cellbits == 32
	const celllog = 5;
#elseif cellbits == 16
	const celllog = 4;
#else
	#error Unknown cell bit width.
#endif

SetBit(array[], bit, bool:value)
{
	if (value)
	{
		array[bit >>> celllog] |= (1 << (bit & (cellbits - 1)));
	}
	else
	{
		array[bit >>> celllog] &= ~(1 << (bit & (cellbits - 1)));
	}
}
```

`(cellbits - 1)`, explicitly with the brackets, is a compile-time constant and will be optimised out.

Cell Bytes
----------

Rather than relying on the number of bits in a cell it is common (in my personal experience *more* common) to write code that relies on the number of bytes in a cell.  Clearly this is just `cellbits / 8` (or `cellbits / charbits` if you want to be *really* future-proof), but this is such a common value that many libraries now define this as a constant:

```pawn
#if !defined cellbytes
	const cellbytes = cellbits / charbits;
#endif
```

How many packed string characters can you store in an array?

```pawn
GetPackedMax(array[], size = sizeof (array))
{
	#pragma unused array
	return size * cellbytes - 1;
}
```

The reverse of that operation - how many cells you need to store a nunmber of characters could be written in terms of `cellbytes` (with a rounding up division):

```pawn
GetPackedRequirements(characters)
{
	return (characters - 1) / cellbytes + 1;
}
```

But the compiler already has an in-built, rarely used, keyword `char` for exactly this operation:

```pawn
GetPackedRequirements(characters)
{
	return characters char;
}
```

The remaining examples, and the reason for `cellbytes` being useful, all rely on `#emit`.

`#emit`
-------

The previous sections were all fairly minor uses of cell sizes, and may possibly continue working suboptimially without any intervention.  This section is absolutely not that, and all but the most absolutely trivial assembly operations will crash and burn.  The simple reason is that pawn is designed and intended to work on the `cell` as a singular unit - `sizeof` returns a number in terms of cells, all tags are still just cells, and even strings use one cell per character by default.  Assembly on the other hand doesn't, it uses bytes for everything, a translation that the compiler usually handles.  Note that this section assumes some familiarity with writing p-code and is not intended as a beginner tutorial to the subject, but a transition for those already familiar with it.

The number of arguments passed to a function is stored on the stack after the previous frame pointer and return address.  To emulate `numargs` previously looked like:

```pawn
new args;

#emit LOAD.S.pri    8 // Two cells, eight bytes, from the frame pointer.
#emit SHR.C.pri     2 // Divide by four to get a count in cells.

#emit STOR.S.pri    args
```

A first attempt to make this code flexible might look like:

```pawn
#if cellbits == 64
	#define ARG_COUNT_OFFSET 16
	#define ARG_COUNT_SHIFT  3
#else
	#define ARG_COUNT_OFFSET 8
	#define ARG_COUNT_SHIFT  2
#endif

new args;

#emit LOAD.S.pri    ARG_COUNT_OFFSET
#emit SHR.C.pri     ARG_COUNT_SHIFT

#emit STOR.S.pri    args
```

That seems good, but thanks to compiler bugs defines don't work in assembly.  So you try the next obvious method:

```pawn
new args;

#if cellbits == 64
	#emit LOAD.S.pri    16
	#emit SHR.C.pri     3
#else
	#emit LOAD.S.pri    8
	#emit SHR.C.pri     2
#endif

#emit STOR.S.pri    args
```

But again, thanks to compiler issues this doesn't work either - `#emit` ignores `#if` entirely and all branches will be output, making this code compile as:

```pawn
new args;

#emit LOAD.S.pri    16
#emit SHR.C.pri     3

#emit LOAD.S.pri    8
#emit SHR.C.pri     2

#emit STOR.S.pri    args
```

But for some bizzare reason, while `#define` and `#if` don't work with `#emit`, `const` does:

```pawn
#if cellbits == 64
	const ARG_COUNT_OFFSET = 16;
	const ARG_COUNT_SHIFT  = 3;
#else
	const ARG_COUNT_OFFSET = 8;
	const ARG_COUNT_SHIFT  = 2;
#endif

new args;

#emit LOAD.S.pri    ARG_COUNT_OFFSET
#emit SHR.C.pri     ARG_COUNT_SHIFT

#emit STOR.S.pri    args
```

As a side note, this quirk also provides a solution to another long-standing compiler issue where even `-` doesn't work with `#emit` and gives an error:

```pawn
// Doesn't work, compile-time error.
#emit CONST.pri     -4
```

```pawn
// Work, but only 32-bit, and hard to understand.
#emit CONST.pri     0xFFFFFFFC
```

```pawn
// Doesn't work again, while attempting to be more readable.
#define MINUS_4 0xFFFFFFFC
#emit CONST.pri     MINUS_4
```

```pawn
// Works everywhere and readable.
const MINUS_4 = -4;
#emit CONST.pri     MINUS_4
```

Even maths will work in `const`, while it absolutely wouldn't in `#emit`:

```pawn
const ARG_COUNT_OFFSET = 2 * cellbytes;
#if cellbits == 64
	const ARG_COUNT_SHIFT  = 3;
#else
	const ARG_COUNT_SHIFT  = 2;
#endif

new args;

#emit LOAD.S.pri    ARG_COUNT_OFFSET
#emit SHR.C.pri     ARG_COUNT_SHIFT

#emit STOR.S.pri    args
```

YSI contains a large number of these constants for calculating cell/byte offsets:

https://github.com/pawn-lang/YSI-Includes/blob/5.x/YSI_Core/y_core/y_emit.inc

As well as having had most assembly now ported to use them, thus serving as an excellent source of examples:

https://github.com/pawn-lang/YSI-Includes/blob/f0f51cd9fc41ed2c7af49833ead7cd3ab7367b50/YSI_Coding/y_ctrl/y_ctrl_impl.inc#L195-L223
https://github.com/pawn-lang/YSI-Includes/blob/f0f51cd9fc41ed2c7af49833ead7cd3ab7367b50/YSI_Coding/y_hooks/y_hooks_impl.inc#L337-L344
https://github.com/pawn-lang/YSI-Includes/blob/f0f51cd9fc41ed2c7af49833ead7cd3ab7367b50/YSI_Core/y_testing/y_testing_entry.inc#L519-L544

This code also uses the fact that `const` works with assembly to make code like `LCTRL 6` easier to read by swapping it to `LCTRL __cip`, but that's side-point.

Example
-------

Another example of converting some old `#emit` code to be 32- and 64-bit compatable.  This is a reimplementation of the native `setarg`:

```pawn
native setarg(arg, value);
```

The regular assembly would look like:

```pawn
setarg(arg, value)
{
	// Get the parameter to be modified.  Normally we would just use
	// `LOAD.S.pri arg`, but that doesn't demonstrate the technique.
	#emit LOAD.S.pri  12

	// Adjust the loaded parameter number to a byte offset.
	#emit SHL.C.pri   2

	// Add the offset to the start of parameters.
	#emit ADD.C       12

	// Get the address of the previous function's stack.
	#emit LOAD.S.alt  0

	// Add the frame base address to the parameter byte offset.
	#emit ADD

	// Load the data to write to the address.  Again, we would normally just use
	// `value` here not `16`.
	#emit LOAD.S.alt  16

	// Swap `pri` and `alt` to put data and address in the correct registers.
	#emit XCHG

	// And write the data.
	#emit STOR.I
}
```

Very often you can see what needs changing because they're raw numbers that are a multiple of four.  We can replace these raw numbers with constants (and to clarify they must use `const` not `new` or `stock const` or anything else or the assembly will get the address of the variable, not the value of the variable).  Although it isn't a multiple of four the `2` in the code must also be changed because it is a shift that is equivalent to `* 4` (so again, if you squint really really hard `<< 2` becomes `* 4` and in fact is the number you're looking for):

```pawn
setarg(arg, value)
{
	const arg_address = 12;
	const mul_by_4 = 2;
	const params_offset = 12;
	const value_address = 16;

	// Get the parameter to be modified.
	#emit LOAD.S.pri  arg_address

	// Adjust the loaded parameter number to a byte offset.
	#emit SHL.C.pri   mul_by_4

	// Add the offset to the start of parameters.
	#emit ADD.C       params_offset

	// Get the address of the previous function's stack.
	#emit LOAD.S.alt  0

	// Add the frame base address to the parameter byte offset.
	#emit ADD

	// Load the data to write to the address.
	#emit LOAD.S.alt  value_address

	// Swap `pri` and `alt` to put data and address in the correct registers.
	#emit XCHG

	// And write the data.
	#emit STOR.I
}
```

We can then change these values to be in terms of `cellbytes` instead of pure numbers, which arguably makes them clearer to read as they are now just cell counts:

```pawn
	const arg_address = 3 * cellbytes;
	#if cellbits == 64
		const mul_by_4 = 3;
	#else
		const mul_by_4 = 2;
	#endif
	const params_offset = 3 * cellbytes;
	const value_address = 4 * cellbytes;
```

There's still one `#if` in there because you can't directly do `log2` in the preprocessor.  But we can go one step further and use the pre-defined constants from YSI:

```pawn
setarg(arg, value)
{
	// Get the parameter to be modified.
	#emit LOAD.S.pri  __param0_offset
	// Adjust the loaded parameter number to a byte offset.
	#emit SHL.C.pri   __cell_shift
	// Add the offset to the start of parameters.
	#emit ADD.C       __params_offset
	// Get the address of the previous function's stack.
	#emit LOAD.S.alt  0
	// Add the frame base address to the parameter byte offset.
	#emit ADD
	// Load the data to write to the address.
	#emit LOAD.S.alt  __param1_offset
	// Swap `pri` and `alt` to put data and address in the correct registers.
	#emit XCHG
	// And write the data.
	#emit STOR.I
}
```

Note that while `__param0_offset` and `__params_offset` are logically the same number, they are used for different things here so treated differently - one is actually getting the first parameter, the other is just the offset to the start of the parameter block.  And the final version, actually using the real parameter names too, would be:
we can go one step further and use the pre-defined constants from YSI:

```pawn
setarg(arg, value)
{
	#emit LOAD.S.pri  arg
	#emit SHL.C.pri   __cell_shift
	#emit ADD.C       __params_offset
	#emit LOAD.S.alt  0
	#emit ADD
	#emit LOAD.S.alt  value
	#emit XCHG
	#emit STOR.I
}
```

Rewritng
--------

Finally, if all else fails, you may just need to rewrite some code.  But this should be a rare last resort, reserved only for code that is very tightly and explicitly tied to bit widths.  Despite all the assembly in YSI the only place where this is required is in *y_cell*, which is a library dedicated to returning information about the bits in a cell.  It is thus quite clearly dependent on the bits in a cell, and even then only some of the functions need converting.

Some parts are just using `#if`, as with several of the examples seen above:

```pawn
/**
 * <library>y_cell</library>
 */
#if cellbits == 32
	const YSI_g_cFEs = -0x01010101; // 0xFEFEFEFE
#else
	const YSI_g_cFEs = -0x0101010101010101; // 0xFEFEFEFEFEFEFEFE
#endif

/**
 * <library>y_cell</library>
 */
#if cellbits == 32
	const YSI_g_c80s = 0x80808080;
#else
	const YSI_g_c80s = 0x8080808080808080;
#endif

/**
 * <library>y_cell</library>
 */
#if cellbits == 32
	const YSI_g_c20s = ~0x20202020;
#else
	const YSI_g_c20s = ~0x2020202020202020;
#endif
```

But where actual assembly changes between the machine sizes another trick is used.  Since `#if` doesn't work with assembly, separate files are used instead:

```pawn
#if cellbits == 32
	#include "y_cell32"
#else
	#include "y_cell64"
#endif
#include "y_cell_impl"
```

And two separate files exist for the very different implementations of a few select special functions:

https://github.com/pawn-lang/YSI-Includes/blob/5.x/YSI_Core/y_core/y_cell32.inc
https://github.com/pawn-lang/YSI-Includes/blob/5.x/YSI_Core/y_core/y_cell64.inc

Conclusion
----------

In short, `const` is your friend, both custom and in-built values.  You can get a very long way to having portable code just using `cellbits` and `cellmin` directly in your code.  Where that's not enough a few simple `#if`s at the top of your code to define some generic macros that can be used in code will do a lot to cover the remaining cases.  Very rarely should you actually need to write new code.

