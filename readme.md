## Improved Warnings

These includes are the culmination of years of gradual improvements and hard-learnt best practices for pawn code.  As a result using them may be a slight shock to anyone who has not kept up-to-date with these developments, but this file is here to help you though the transition.  There are a few important things to get out of the way first, which often trip up newbies:

1. ***Warnings are not errors.***

The compiler has several ways it can report issues, the main two being *errors* and *warnings*.

An *error* indicates a mistake typing code, thus indicates that the code cannot be compiled.  Missing brackets are errors because there's no way to know where the expression ends.  `new a = 5 * ;` is an error, because there's nothing following the `*`.  `print(hello world);` is an error because strings need `""`s.  Errors prevent mistakes that cause the code to not run at all - your code will not compile at all.

A *warning* indicates that code is syntactically correct (i.e. complete in terms of characters typed), but might still be wrong when run.  `new a = Multiply(5);` might seem simlar to the `5 *` error above, but it is only a warning because while the function is missing a parameter, the code "looks" correct.  `new f = fopen("file");` is a warning because `fopen` returns `File:` tagged data but `f` is untagged (`_:`); while the types expected are different the assignment is written correctly.  Warnings try to prevent mistakes that will cause the code to not do what you expect in some cases - your code will still compile.

2. *** Warnings are not breaking.***

A warning is just a message.  Too many people think that a warning means the code hasn't compiled, or will do something different when run.  They do not.  You can have a thousand warnings and still get a `.amx`.  Only errors break the build.  If you get warnings they indicate things that *could* be problems, but your code will still compile and run.  New compiler versions add new warnings for more identified problems, and new include versions add better information to help the compiler do its job.

When you update your compiler or includes new warnings that were not previously present may appear, even on code that you personally know works correctly.  Why warn on code you know works?  Because while you might, not everyone does, and similar code you write may be wrong in the future.  This is why includes and defines are updated as well - to allow you to write code that you know is correct *and* the compiler knows is correct; making it very hard for you or anyone else to write bad code.

## Tag Warning Example

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

## More Tags

Parameters that only accept a limited range of values (for example, object attachment bones) are now all enumerations so that passing invalid values gives a warning:

```pawn
TextDrawAlignment(textid, TEXT_DRAW_ALIGN_LEFT); // Fine
TextDrawFont(textid, 7); // Warning
```

Functions that take or return just `true`/`false` all have `bool:` tags.  More functions than might be expected return booleans; most player functions return `true` when they succeed and `false` when the player is not connected, sometimes skipping the need for `IsPlayerConnected`:

```pawn
new Float:x, Float:y, Float:z;
// If the player is connected get their position.
if (GetPlayerPos(playerid, x, y, z))
{
	// Timer repeats are on or off, so booleans.
	SetTimer("TimerFunc", 1000, false);
}
```

Native functions that don't return any useful value have `void:` tags to indicate this fact.  The compiler doesn't enforce this by default, it is purely for informational purposes:

```pawn
new useless = ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
```

You can enable `void:` tag warnings with a define before including `open.mp`, this is only disabled by default because doing so adds a tiny bit of overhead to the relevant native functions.  However, it is recommended as functions that return no defined value can by definition not be relied on (or at least enable the warning, fix the uses, then disable it again, periodically re-enabling to check no undefined value uses have snuck back in):

```pawn
#define VOID_TAGS
#include <open.mp>
```

## Const-Correctness

Some functions, like `SendRconCommand`, take strings; some functions, like `GetPlayerName`, modify strings.  These are different operations with different considerations.  Consider the following code:

```pawn
GetPlayerName(playerid, "Bob");
```

This code doesn't make any sense.  "Bob" is a string literal, you can't store someone's name in to the word `"Bob"`, it would be like trying to do:

```pawn
"Bob" = GetPlayerName(playerid);
```

`"Bob"` is a *constant*, it is a value fixed by the compiler that can't be modified at runtime.  `GetPlayerName` modifies its values at runtime, so cannot take a constant only a variable.  For this reason it is declared as:

```pawn
native GetPlayerName(playerid, name[], size = sizeof (name));
```

But what of `SendRconCommand`?  The following *is* valid:

```pawn
SendRconCommand("loadfs objects");
```

`SendRconCommand` does not return a string, it doesn't modify the value passed in.  If it were declared in the same way as `GetPlayerName` it would have to take a variable that could be modified:

```pawn
native SendRconCommand(cmd[]);
new cmd[] = "loadfs objects";
// `cmd` must be modifiable because `SendRconCommand` doesn't say it won't.
SendRconCommand(cmd);
```

This is cumbersome and pointless.  Again, we know that `SendRconCommand` cannot change the data given, so we tell the compiler this as well.  Anything between `""`s is a *constant*, so make `SendRconCommand` accept them with `const`:

```pawn
native SendRconCommand(const cmd[]);
// Allowed again because we know this call won't modify the string.
SendRconCommand("loadfs objects");
```

This is called *const correctness* - using `const` when data will not be modified, and not using `const` when the parameter will be modified.  This is mainly only useful for strings and arrays (differentiated in the includes by the use of a `string:` tag) as they are pass-by-reference, but when in doubt use the rules on normal numbers as well.

Functions that are `const` can also take variables which may be modified.  `const` means the function promises not modify the variable (`GetPlayerName` in the SA:MP includes incorrectly used `const` and broke this promise), but that doesn't mean you can't pass varaibles that don't mind being modified - there's no such thing as a variable that *must* be modified:

```pawn
native SendRconCommand(const string:cmd[]);
new cmd[32];
format(cmd, _, "loadfs %s", scriptName);
// `cmd` is allowed to be modified, but `SendRconCommand` won't do so.
SendRconCommand(cmd);
```

As a side note, the following code is now also a warning:

```pawn
Func(const &var)
{
	printf("%d", var);
}
```

`const` means a variable can't be modified, while `&` means it can.  Since modifiying a normal variable is the only reason to pass it by reference adding `const` to the declaration is, as with all warnings, probably a mistake.
 
For more information on const-correctness see:

https://github.com/pawn-lang/compiler/wiki/What's-new#const-correctness
https://github.com/pawn-lang/compiler/wiki/Const-Correctness

## Major Changes

* `random` now works for negative numbers.  Calling `random(-5)` will return any of `0`, `-1`, `-2`, `-3`, or `-4`.  As with `random(5)` the specified number will not be returned, if instead you want the upper limit (i.e. `0`) skipped just do `random(-5) - 1`.

* 

