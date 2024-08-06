#if defined _core_included
	#endinput
#endif
#define _core_included

/**
 * <library name="core" summary="Core functions.">
 *   <license>
 *     (c) Copyright 1998-2005, ITB CompuPhase
 *     This file is provided as is (no warranties).
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

/// <p/>

#pragma library Core

/**
 * <library>core</library>
 * <summary>Returns the amount of memory available for the heap/stack in bytes.</summary>
 * <remarks>In absence of recursion, the pawn parser can also give an estimate of the required stack/heap
 * space.</remarks>
 * <returns>The free space on the heap in bytes.  The stack and the heap occupy a shared memory area,
 * so this value indicates the number of bytes that is left for either the stack or the heap.</returns>
 */
native heapspace();

/**
 * <library>core</library>
 * <summary>This function returns the ID of a public function by its name.</summary>
 * <param name="name">The name of the public function to get the ID of</param>
 * <seealso name="CallLocalFunction"/>
 * <seealso name="CallRemoteFunction"/>
 * <returns>The ID of the function (IDs start at <b><c>0</c></b>). <b><c>-1</c></b> if the function
 * doesn't exist.</returns>
 */
native funcidx(const name[]);

/**
 * <library>core</library>
 * <summary>Get the number of arguments passed to a function.</summary>
 * <seealso name="getarg"/>
 * <seealso name="setarg"/>
 * <returns>The number of arguments passed.</returns>
 */
native numargs();

/**
 * <library>core</library>
 * <summary>Get an argument that was passed to a function.</summary>
 * <param name="arg">The argument sequence number.  Use <b><c>0</c></b> for first argument</param>
 * <param name="index">The index (in case the argument is an array) (optional=<b><c>0</c></b>)</param>
 * <seealso name="numargs"/>
 * <seealso name="setarg"/>
 * <returns>The value of the argument.</returns>
 */
native getarg(arg, index = 0);

/**
 * <library>core</library>
 * <summary>Set an argument that was passed to a function.</summary>
 * <param name="arg">The argument sequence number.  Use <b><c>0</c></b> for first argument</param>
 * <param name="index">The index (if the argument is an array) (optional=<b><c>0</c></b>)</param>
 * <param name="value">The value to set the argument to</param>
 * <seealso name="getarg"/>
 * <seealso name="numargs"/>
 * <returns><b><c>1</c></b> on success and <b><c>0</c></b> if the argument or the index are invalid.</returns>
 */
native bool:setarg(arg, index = 0, value);

/**
 * <library>core</library>
 * <summary>This function changes a single character to lowercase.</summary>
 * <param name="c">The character to change to lowercase</param>
 * <remarks>Support for accented characters is platform-dependent.</remarks>
 * <returns>The lower case variant of the input character, if one exists, or the unchanged character
 * code of c if the letter c has no lower case equivalent.</returns>
 */
native tolower(c);

/**
 * <library>core</library>
 * <summary>This function changes a single character to uppercase.</summary>
 * <param name="c">The character to change to uppercase</param>
 * <remarks>Support for accented characters is platform-dependent.</remarks>
 * <returns>The upper case variant of the input character, if one exists, or the unchanged character
 * code of c if the letter c has no upper case equivalent.</returns>
 */
native toupper(c);

/**
 * <library>core</library>
 * <summary>Swap bytes in a cell</summary>
 * <param name="c">The value for which to swap the bytes.</param>
 * <returns>A value where the bytes are swapped (the lowest byte becomes the highest byte)</returns>
 */
native swapchars(c);

/**
 * <library>core</library>
 * <summary>Get a pseudo-random number.</summary>
 * <param name="max">The range of values (from <b><c>0</c></b> to <b><c>max-1</c></b>) that can be returned</param>
 * <remarks>Using a value smaller than <b><c>1</c></b> gives weird values.</remarks>
 * <remarks>The standard random number generator of pawn is likely a linear congruential pseudo-random
 * number generator with a range and a period of 2^31.  Linear congruential pseudo-random number generators
 * suffer from serial correlation (especially in the low bits) and it is unsuitable for applications
 * that require high-quality random numbers.</remarks>
 * <returns>A random number ranging from <b><c>0</c></b> to <b><c>max-1</c></b>.</returns>
 */
native random(max);

/**
 * <library>core</library>
 * <summary>Return the lowest of two numbers</summary>
 * <param name="value1">The two values for which to find the lowest number</param>
 * <param name="value2">The two values for which to find the lowest number</param>
 * <seealso name="clamp"/>
 * <seealso name="max"/>
 * <returns>The lower value of value1 and value2</returns>
 */
native min(value1, value2);

/**
 * <library>core</library>
 * <summary>Return the highest of two numbers</summary>
 * <param name="value1">The two values for which to find the highest number</param>
 * <param name="value2">The two values for which to find the highest number</param>
 * <seealso name="clamp"/>
 * <seealso name="min"/>
 * <returns>The higher value of value1 and value2</returns>
 */
native max(value1, value2);

/**
 * <library>core</library>
 * <summary>Force a value to be inside a range.</summary>
 * <param name="value">The value to force in a range</param>
 * <param name="min">The low bound of the range (optional=<b><c>cellmin</c></b>)</param>
 * <param name="max">The high bound of the range (optional=<b><c>cellmax</c></b>)</param>
 * <returns>value, if it is in the range min-max, min, if value is lower than min or max, if value is
 * higher than max.</returns>
 */
native clamp(value, min = cellmin, max = cellmax);

/**
 * <library>core</library>
 * <summary>Get a specific property from the memory, the string is returned as a packed string!.</summary>
 * <param name="id">The <a href="https://en.wikipedia.org/wiki/Virtual_machine">virtual machine</a> to
 * use, you should keep this zero (optional=<b><c>0</c></b>)</param>
 * <param name="name">The property's name, you should keep this "" (optional=<b><c>""</c></b>)</param>
 * <param name="value">The property's unique ID, Use the hash-function to calculate it from a string
 * (optional=<b><c>cellmin</c></b>)</param>
 * <param name="string">The variable to store the result in, passed by reference (optional=<b><c>""</c></b>)</param>
 * <seealso name="Setproperty"/>
 * <seealso name="Deleteproperty"/>
 * <seealso name="Existproperty"/>
 * <returns>The value of a property when the name is passed in; fills in the string argument when the
 * value is passed in.  If the property does not exist, this function returns zero.</returns>
 */
native getproperty(id = 0, const name[] = "", value = cellmin, string[] = "");

/**
 * <library>core</library>
 * <summary>Add a new property or change an existing property.</summary>
 * <param name="id">The virtual machine to use, you should keep this zero (optional=<b><c>0</c></b>)</param>
 * <param name="name">Used in combination with value when storing integers; don't use this if you want
 * to store a string(optional=<b><c>""</c></b>)</param>
 * <param name="value">The integer value to store or the property's unique ID if storing a string.
 * Use the hash-function to calculate it from a string (optional=<b><c>cellmin</c></b>)</param>
 * <param name="string">The value of the property, as a string.  Don't use this if you want to store
 * an integer (optional=<b><c>""</c></b>)</param>
 * <seealso name="Getproperty"/>
 * <seealso name="Deleteproperty"/>
 * <seealso name="Existproperty"/>
 */
native setproperty(id = 0, const name[] = "", value = cellmin, const string[] = "");

/**
 * <library>core</library>
 * <summary>Delete an earlier set property (<a href="#setproperty">setproperty</a>).</summary>
 * <param name="id">The <a href="https://en.wikipedia.org/wiki/Virtual_machine">virtual machine</a> to
 * use.  You should keep this as zero (optional=<b><c>0</c></b>)</param>
 * <param name="name">The property's name, you should keep this blank (optional=<b><c>""</c></b>)</param>
 * <param name="value">The property's unique ID.  Use the hash-function to calculate it from a string
 * (optional=<b><c>cellmin</c></b>)</param>
 * <seealso name="Setproperty"/>
 * <seealso name="Getproperty"/>
 * <seealso name="Existproperty"/>
 * <returns>The value of the property.  If the property does not exist, the function returns <b><c>0</c></b>.</returns>
 */
native deleteproperty(id = 0, const name[] = "", value = cellmin);

/**
 * <library>core</library>
 * <summary>Check if a property exist.</summary>
 * <param name="id">The <a href="https://en.wikipedia.org/wiki/Virtual_machine">virtual machine</a> to
 * use, you should keep this zero (optional=<b><c>0</c></b>)</param>
 * <param name="name">The property's name, you should keep this (optional=<b><c>""</c></b>)</param>
 * <param name="value">The property's unique ID.  Use the hash-function to calculate it from a string
 * (optional=<b><c>cellmin</c></b>)</param>
 * <seealso name="Setproperty"/>
 * <seealso name="Getproperty"/>
 * <seealso name="Deleteproperty"/>
 * <returns><b><c>1</c></b> if the property exists and <b><c>0</c></b> otherwise.</returns>
 */
native bool:existproperty(id = 0, const name[] = "", value = cellmin);

/* */ native __unpackpubvar(dest[], const source[], maxlength = sizeof (dest)) = strunpack;

static stock __findpubvar(const __name[])
{
	// Scans the AMX header to find a public variable and returns the address of the entry, or `0`
	// if there isn't one.  Can't use `static` here because we rely on the string being all `\0`s.
	new __unpacked[64], __offset = 0;
	const __cellbytes = cellbits / charbits;
	// In 32-bit scripts this is `64`, but in 64-bit scripts it is only `96`.  Part of the header
	// entry is always 32-bit, regardless of the cell bit width.  We need it in bytes.
	const __defsize = __cellbytes + 4;
	// Ensure the input is unpacked for easier (to code) comparisons.
	__unpackpubvar(__unpacked, __name);
	new __start, __end;
	// Now we start doing assembly magic to dig through the AMX header itself.
	// Get the offset from the start of the file to the start of the data segment (DAT).
	#emit LCTRL        1
	// Invert it to get the start of the file relative to DAT.
	#emit NEG
	// Store this offset.  We'll need it a lot.
	#emit MOVE.alt
	#emit STOR.S.pri   __offset
	// Get the offset to the pubvars pointer.
	#emit ADD.C        44 // Doesn't change with `cellbits`.
	#emit STOR.S.pri   __start
	#emit ADD.C        4 // Doesn't change with `cellbits`.
	#emit STOR.S.pri   __end
	#emit LREF.S.pri   __start
	// Make this pointer relative to `DAT`.
	#emit ADD
	// Point to the name pointer in the entry to begin with.
	#emit ADD.C        __cellbytes
	#emit STOR.S.pri   __start
	// Get the offset to the tags pointer.
	#emit LREF.S.pri   __end
	#emit ADD
	#emit ADD.C        __cellbytes
	#emit STOR.S.pri   __end
	// Loop through the list of public variables and compare their names.
	new __s0, __s1, __s2;
	// This could be made a binary search, but it would complicate the code a lot, and isn't worth
	// it given how rare public variables are.  I actually wrote a more complex version that could
	// compare two packed C strings, but shorter is better here.
	while (__start != __end)
	{
		// Load the pointer.
		#emit LREF.S.pri   __start
		// Add the `DAT` offset.
		#emit LOAD.S.alt   __offset
		#emit ADD
		// Save the pointer.
		#emit STOR.S.pri   __s0
		__s1 = 0;
		for ( ; ; )
		{
			#emit LREF.S.pri   __s0
			#emit STOR.S.pri   __s2
			if (__unpacked[__s1] != __s2 & 0xFF)
			{
				break;
			}
			if (__unpacked[__s1] == '\0')
			{
				// The end of the string.
				return __start - __cellbytes;
			}
			++__s0;
			++__s1;
		}
		// This wasn't a match.  Try the next one.
		__start += __defsize;
	}
	return 0;
}

/**
 * <library>core</library>
 * <summary>Gets a specific public variable from the current script.</summary>
 * <param name="name">The public variable's name.</param>
 * <seealso name="setpubvar"/>
 * <seealso name="existpubvar"/>
 * <seealso name="numpubvars"/>
 * <returns>Naught if the variable doesn't exist (use <c>existpubvar</c> first).</returns>
 */
/*
native getpubvar(const name[]);
*/
stock getpubvar(const __name[])
{
	const __cellbytes = cellbits / charbits;
	new __entry = __findpubvar(__name);
	if (__entry)
	{
		// Get the pointer to the data.
		#emit LREF.S.pri   __entry
		#emit STOR.S.pri   __entry
		// Get the old data (fortunately the pointer is relative to `DAT`).
		#emit LREF.S.pri   __entry
		// Return the value in `pri`.
		#emit STACK        __cellbytes
		#emit RETN
	}
	return 0;
}

/**
 * <library>core</library>
 * <summary>Sets a specific public variable in the current script.</summary>
 * <param name="name">The public variable's name.</param>
 * <param name="value">The value to store in the public variable.</param>
 * <seealso name="getpubvar"/>
 * <seealso name="existpubvar"/>
 * <seealso name="numpubvars"/>
 * <returns>The previous value of the variable.</returns>
 */
/*
native setpubvar(const name[], value);
*/
stock setpubvar(const __name[], __value)
{
	const __cellbytes = cellbits / charbits;
	new __entry = __findpubvar(__name);
	if (__entry)
	{
		// Get the pointer to the data.
		#emit LREF.S.pri   __entry
		#emit STOR.S.pri   __entry
		// Get the old data (fortunately the pointer is relative to `DAT`).
		#emit LREF.S.pri   __entry
		// Store the new data.
		#emit LOAD.S.alt   __value
		#emit SREF.S.alt   __entry
		// Return the value in `pri`.
		#emit STACK        __cellbytes
		#emit RETN
	}
	return 0;
}

/**
 * <library>core</library>
 * <summary>Checks if a specific public variable exists in the current script.</summary>
 * <param name="name">The public variable's name.</param>
 * <seealso name="getpubvar"/>
 * <seealso name="setpubvar"/>
 * <seealso name="numpubvars"/>
 * <returns>Does the variable exist?</returns>
 */
/*
native bool:existpubvar(const name[]);
*/
stock bool:existpubvar(const __name[])
{
	return __findpubvar(__name) != 0;
}

/**
 * <library>core</library>
 * <summary>Counts how many public variables there are in the script.</summary>
 * <seealso name="getpubvar"/>
 * <seealso name="setpubvar"/>
 * <seealso name="existpubvar"/>
 * <returns>The number of public variables declared.</returns>
 */
/*
native numpubvars();
*/
stock numpubvars()
{
	const __cellbytes = cellbits / charbits;
	// In 32-bit scripts this is `64`, but in 64-bit scripts it is only `96`.  Part of the header
	// entry is always 32-bit, regardless of the cell bit width.  We need it in bytes.
	const __defsize = __cellbytes + 4;
	new __start, __end;
	// Now we start doing assembly magic to dig through the AMX header itself.
	// Get the offset from the start of the file to the start of the data segment (DAT).
	#emit LCTRL        1
	// Invert it to get the start of the file relative to DAT.
	#emit NEG
	// Get the offset to the pubvars pointer.
	#emit ADD.C        44 // Doesn't change with `cellbits`.
	#emit STOR.S.pri   __start
	// Get the offset to the tags pointer.
	#emit ADD.C        4 // Doesn't change with `cellbits`.
	#emit STOR.S.pri   __end
	// Load both values.
	#emit LREF.S.alt   __start
	#emit LREF.S.pri   __end
	#emit SUB
	#emit STOR.S.pri   __end
	return __end / __defsize;
}
