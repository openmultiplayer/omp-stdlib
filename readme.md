These includes are the culmination of years of gradual improvements and hard-learnt best practices for pawn code.  As a result using them may be a slight shock to anyone who has not kept up-to-date with these developments, but this file is here to help you though the transition.  There are a few important things to get out of the way first, which often trip up newbies:

1. ***Warnings are not errors.***

The compiler has several ways it can report issues, the main two being *errors* and *warnings*.

An *error* indicates a mistake typing code, thus indicates that the code cannot be compiled.  Missing brackets are errors because there's no way to know where the expression ends.  `new a = 5 * ;` is an error, because there's nothing following the `*`.  `print(hello world);` is an error because strings need `""`s.  Errors prevent mistakes that cause the code to not run at all - your code will not compile at all.

A *warning* indicates that code is syntactically correct (i.e. complete in terms of characters typed), but might still be wrong when run.  `new a = Multiply(5);` might seem simlar to the `5 *` error above, but it is only a warning because while the function is missing a parameter, the code "looks" correct.  `new f = fopen("file");` is a warning because `fopen` returns `File:` tagged data but `f` is untagged (`_:`); while the types expected are different the assignment is written correctly.  Warnings try to prevent mistakes that will cause the code to not do what you expect in some cases - your code will still compile.

2. *** Warnings are not breaking.***

A warning is just a message.  Too many people think that a warning means the code hasn't compiled, or will do something different when run.  They do not.  You can have a thousand warnings and still get a `.amx`.  Only errors break the build.  If you get warnings they indicate things that *could* be problems, but your code will still compile and run.  New compiler versions add new warnings for more identified problems, and new include versions add better information to help the compiler do its job.

When you update your compiler or includes new warnings that were not previously present may appear, even on code that you personally know works correctly.  Why warn on code you know works?  Because while you might, not everyone does, and similar code you write may be wrong in the future.  This is why includes and defines are updated as well - to allow you to write code that you know is correct *and* the compiler knows is correct; making it very hard for you or anyone else to write bad code.

Lets look at a concrete example:

```pawn
if (GetPVarType(playerid, "MY_DATA") == 1)
{
	printf("Found an int");
}
```

This code is correct, and will give the correct answer, so why add warnings?

```pawn
switch (GetPVarType(playerid, "MY_DATA"))
{
case 0:
	printf("Unknown type");
case 1:
	printf("Found an int");
case 2:
	printf("Found a float");
case 3:
	printf("Found a string");
case 4:
	printf("Found a boolean");
}
```

This code is subtly wrong, take a moment to try and work out how - the compiler will not help you.

It could take a lot of testing and debugging to find the problem here without a lot of familiarity with the functions in question, fortunately the open.mp includes now return a `VARTYPE:` tag from `GetPVarType` and this code will give tag-mismatch warnings.  Once we try and fix the warnings using the defined constants the mistakes become instantly obvious:

```pawn
switch (GetPVarType(playerid, "MY_DATA"))
{
case VARTYPE_NONE:
	printf("Unknown type");
case VARTYPE_INT:
	printf("Found an int");
case VARTYPE_STRING:
	printf("Found a float");
case VARTYPE_FLOAT:
	printf("Found a string");
case VARTYPE_BOOL:
	printf("Found a boolean");
}
```

The string/float mixup still needs some manual review, but it is now far more obvious that those two are the wrong way around.  In fact there's a good chance that the person updating the code would have used them the correct way round without even realising that they have now fixed a prior bug.  The `VARTYPE_BOOL:` line will give an error that the symbol doesn't exist because there is no type `4`.  The old code quite happily compiled without issues and had an impossible branch.  The effects aren't serious in this example, but they could be.  But, again, the old code will still compile and run.  More warnings help to highlight issues, they do not introduce new ones.

## Usage

## `const`- And Tag-Correctness

Many functions have had their types improved to increase the number of bugs detected at compile-time.  These changes may in some cases result in new warnings, but there are multiple ways to deal with warnings.  Unlike errors, which entirely prevent the script from compiling, warnings are only hints about potential bugs to deal with as and when you please (unless, of course, you are compiling with `-E` to turn all warnings in to errors).  Unfortunately these changes cannot be easilly applied to callbacks because changes there frequently give errors instead of warnings, which would make these breaking changes rather than just new diagnostics.

Parameters that only accept a limited range of values (for example, object attachment bones) are now all enumerations so that passing invalid values gives a warning:

```pawn
TextDrawAlignment(textid, TEXT_DRAW_ALIGN_LEFT); // Fine
TextDrawFont(textid, 7); // Warning
```

Functions that take or return just `true`/`false` all have `bool:` tags.  More functions that might be expected return booleans; most player functions return `true` when they succeed and `false` when the player is not connected, sometimes skipping the need for `InPlayerConnected`:

```pawn
new Float:x, Float:y, Float:z;
// If the player is connected get their position.
if (GetPlayerPos(playerid, x, y, z))
{
	// Timer repeats are on or off.
	SetTimer("TimerFunc", 1000, false);
}
```

Functions that don't return any useful value have `void:` tags to indicate this fact.  The compiler doesn't enforce this by default, it is purely for informational purposes:

```pawn
new useless = ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
```

You can enable `void:` tag warnings with a define before including `open.mp`, this is only disabled by default because doing so adds a tiny bit of overhead to the relevant native functions.  However, it is recommended as functions that return no defined value can by definition not be relied on (or at least enable the warning, fix the uses, then disable it again, periodically re-enabling to check no undefined value uses have snuck back in):

```pawn
#define VOID_TAGS
#include <open.mp>
```

## Major Changes

* `random` now works for negative numbers.  Calling `random(-5)` will return any of `0`, `-1`, `-2`, `-3`, or `-4`.  As with `random(5)` the specified number will not be returned, if instead you want the upper limit (i.e. `0`) skipped just do `random(-5) - 1`.

* 

