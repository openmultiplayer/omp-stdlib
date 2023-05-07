open.mp is the culmination of years of gradual improvements, fixes, and hard-learnt best practices for pawn code and SA:MP.  It is the direct continuation of several projects all with the same aim - making online San Andreas better for (in order of importance): players (the largest group), newbies (who need help and support), and experienced coders (who can fend for themselves).  As a result the whole system should be smoother and less frustrating for those just learning, but may be a slight shock to existing scripters who have not kept up-to-date with these developments.  This file detais these changes for that latter group.

 Compiler Changes
------------------

open.mp officially uses version 3.10.11 of the pawn compiler, released along-side the server.  Older compilers may work, and old scripts on the old compiler obviously won't change, but these cases aren't tested.

### Improved Warnings

The new compiler adds and uncomments several new warnings which may trigger on existing code.  There are a few important things to get out of the way first, which often trip up even those supposedly "experienced" devs:

1. ***Warnings are not errors.***

The compiler has several ways it can report issues, the main two being *errors* and *warnings*.  While warnings do not normally prevent compilation you can upgrade them to errors with the `-E` flag.

An *error* indicates a mistake typing code, thus indicates that the code cannot be compiled.  Missing brackets are errors because there's no way to know where the expression ends.  `new a = 5 * ;` is an error, because there's nothing following the `*`.  `print(hello world);` is an error because strings need `""`s.  Errors prevent mistakes that cause the code to not run at all - your code will not compile at all.

A *warning* indicates that code is syntactically correct (i.e. complete in terms of characters typed), but might still be wrong when run.  `new a = Multiply(5);` might seem simlar to the `5 *` error above, but it is only a warning because while the function is missing a parameter, the code "looks" correct.  `new f = fopen("file");` is a warning because `fopen` returns `File:` tagged data but `f` is untagged (`_:`); while the types expected are different the assignment is written correctly.  Warnings try to prevent mistakes that will cause the code to not do what you expect in some cases - your code will still compile.

2. ***Warnings are not breaking.***

A warning is just a message.  Too many people think that a warning means the code hasn't compiled, or will do something different when run.  They do not.  You can have a thousand warnings and still get a `.amx`.  Only errors break the build.  If you get warnings they indicate things that *could* be problems, but your code will still compile and run.  New compiler versions add new warnings for more identified problems, and new include versions add better information to help the compiler do its job.

When you update your compiler or includes new warnings that were not previously present may appear, even on code that you personally know works correctly.  Why warn on code you know works?  Because while you might, not everyone does, and similar code you write may be wrong in the future.  This is why includes and defines are updated as well - to allow you to write code that you know is correct *and* the compiler knows is correct; making it very hard for you or anyone else to write bad code.

### Const-Correctness

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

Functions that are `const` can also take variables which may be modified.  `const` means the function promises not modify the variable (`GetPlayerName` in the SA:MP includes incorrectly used `const` and broke this promise), but that doesn't mean you can't pass variables that don't mind being modified - there's no such thing as a variable that *must* be modified:

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

### Include Guards

This is the only true *breaking* change in the new compiler, a change that may prevent old code that used to work from continuing to work (remember, new warnings don't stop code working).  On older compilers the following code:

```pawn
#include <my_include>
```

Imported all the code from inside the `my_include.inc` if it wasn't previously included.  It is equivalent to:

```pawn
#if !defined _inc_my_include
	#define _inc_my_include
	
	// `my_include` code goes here.
#endif
```

These `_inc_filename` symbols were automatically defined for every include and automatically checked for when a file was included a second time.  The new compiler by default no longer generates these automatic include guards, but as the only breaking change this is the only change that can be reverted by using the `-Z` flag.  However, most includes (including the original SA:MP includes) have their own include guards anyway and most code is no longer affected by this change.

### Longer Symbols

The default SA:MP compiler can only have symbols with names up to 31 characters.  While increasing this in the compiler is trivial the SA:MP server has the same limit defined and that is harder to increase (there is a plugin to do it, but it isn't common).  Many suggestions were made, such as modifying the server or increasing the limit only for internal names (i.e. not `public` and `native` functions), but none of these transpired.  With the advent of a new server this problem can finally be resolved once and for all by just upping the limit in the server as well.  So it has been - to 61.

An AMX file should contain (at the start of the nametable) the maximum size of symbols as defined in the compiler; on the old compiler this was `0x001F` and would now be `0x003F`.  This value is checked by the server when the script is loaded to ensure it is in range, sadly under these semantics old code with no longer names compiled on the new compiler would no longer load in the SA:MP server.  This was fixed by having the nametable header contain the length of the longest found symbol, not the longest allowed symbol.  Code with no extended visible functions (meaning functions used by the server like callbacks) can still use the updated compiler for the old server, and only newer code targetting the open.mp server will fail to load on legacy systems.

### Other Features

Other new compiler features are documented on [the community compiler repo](https://github.com/pawn-lang/compiler/).  They are briefly listed here for reference, but they do not affect existing code at all.

* `#warning` - Like `#error` for user-generated warnings.
* `#pragma option` - Specify flags like `-a` directly in code.
* `#pragma naked` - Skip `PROC` and `RETN` in the current function.
* `#pragma compat` - Same as using `-Z`.
* `#pragma warning` - Configure warnings.
* `#pragma unwritten` - Hide warnings for variables never set.
* `#pragma nodestruct` - Don't generate `operator~` destructor code.
* `__line` - The current line number in a macro.
* `__file` - The current file name in a macro.
* `__date` - The date of the start of the compilation in a macro.
* `__time` - The time of the start of the compilation in a macro.
* `__compat` - `-Z` was used.
* `__optimisation` - The optimisation level (`0`, `1`, or `2`) from `-O`.
* `__PawnBuild` - `11` for compiler version `3.10.11`.
* `static enum` - Scope enums to a single file.
* `const static` - Compile-time constant scoped to a single file (unlike `static const`).
* `new arr[2][5] = { { 0, 1, ...}, ... }` - `...` now works in 2D arrays.
* `new arr[2][3][4][5]` - 4d arrays.
* `__emit` - Similar to `#emit` but safer and a proper expression.
* `__Pawn` - Now `0x030A`.
* `__addressof` - Get a function address at compile-time.
* `__nameof` - Convert a symbol name to a string if it exists.
* `new a = a;` - Disallowed.
* Multi-line strings.
* Suggestions for unknown symbols.
* Countless bug fixes.
* Optional recursion detection (`-R`).
* `new a = 5; a = 6;` - Warning 240: Previously assigned value is never used.
* `new a = b >> -5;` - Warning 241: Negative or too big shift count.
* `enum X (<<= 4) { E = 0x80000000, F }` - Warning 242: Shift overflow in enum element declaration.
* `switch (5)` - Warning 243: Redundant code: switch control expression is constant.
* `switch (x) { case E:{} }` - Warning 244: Enum element not handled in switch.
* `enum X (<<= 1) { E, F}` - Warning 245: Enum increment has no effect on zero value.
* `enum X (*= 10) { E = 0x40000000, F}` - Warning 246: multiplication overflow in enum element declaration.
* `new bool:a = false; ++a;` - Warning 247: use of operator.
* `if (a, b)` - Warning 248: possible misuse of comma operator.
* `__static_check(false);` - Warning 249: check failed.
* `__static_assert(false);` - Error 110: assertation failed.
* `for (new i = 0; i != 10; ) {}` - Warning 250: variable used in loop condition not modified in loop body.
* `for (new i = 0, j = 10; i != j; ) {}` - Warning 251: none of the variables used in loop condition are modified in loop body.

You will note that all these new features either use existing keywords, `#`, or a `__` prefix.  This last one is a well established convention in many languages reserved for compiler and system includes to be able to add new items without fear of conflicts.  The open.mp includes, as the core system library, continue this convention and use `__` prefixes liberally and without appology.

 Include Changes
-----------------

### More Tags

open.mp includes introduce many more tags to functions and callbacks.  These are useful in the long run, but slightly annoying to upgrade to.  There are three symbols:  `NO_TAGS`, `WEAK_TAGS`, and `STRONG_TAGS`; that you can define before including `<open.mp>`, each one enabling progressively more checks:

```pawn
#define STRONG_TAGS
#include <open.mp>
```

To encourage some adoption, the default is `WEAK_TAGS`.  Most old code uses will simply give a warning when the wrong tag is found:

```pawn
// Gives a warning:
SetPlayerControllable(playerid, 1);

// Should be:
SetPlayerControllable(playerid, true);
```

Generally arameters that only accept a limited range of values (for example, object attachment bones) are now all enumerations so that passing invalid values gives a warning:

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

You can enable `void:` tag warnings with a define before including `open.mp`, this is only disabled by default because doing so adds a tiny bit of overhead to the relevant native functions.  However, it is recommended as functions that return no defined value can by definition not be relied on (or at least enable the warning, fix the uses, then disable it again, periodically re-enabling to check no undefined value uses have snuck back in).  It is a little confusing that the warning, while correctly at the call site, will say that the function in question should return a value, whereas in fact the function should *not* return a value and true problem is code trying to use that non-existent return value:

```pawn
#define VOID_TAGS
#include <open.mp>
```

For parameters the default is to make these new tags *weak*, meaning that you get warnings when passing untagged values to tagged parameters, but not the other way around.  This applies to function returns so saving a tag result in an untagged variable will not give a warning.  This second group can also be upgraded by specifying the use of *strong* tags instead:

```pawn
#define STRONG_TAGS
#include <open.mp>
```

Alternatively, if you really hate help:

```pawn
#define NO_TAGS
#include <open.mp>
```

The only breaking change introduced by these new tags are on callbacks.  For some reason tag mismatch warnings in function prototypes are an error, not a warning (probably because of code generation issues related to overloaded operators).  The best way to deal with these is to ensure that the `public` part of the callback will compile regardless of tag settings by falling back to `_:` when none is specified:

```pawn
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
forward OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
```

See the end of this document for a full list of all updated callbacks.  This is the main problem change, but it is important to note that the following code will work with any include, with or without the new tags:

```pawn
#if !defined CLICK_SOURCE
	#define CLICK_SOURCE: _:
#endif
public OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source)
{
	return 1;
}
```

Thus writing backwards-compatible code remains possible.  Forward for ALS as normal:

```pawn
#if !defined PLAYER_STATE
	// Use the default tag (none, `_:`) when the improved includes aren't found.
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
	return Hooked_OnPlayerStateChange(playerid, newstate, oldstate);
}

forward Hooked_OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);
```

There is a tool to automatically upgrade all `forward`, `public`, `hook`, `@hook`, and `HOOK__` callbacks:

```
callback-upgrade ./source-dir
```

The argument `--help` will show more information and `--report` will show the changes needed without applying them automatically.

#### Tag Warning Example

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

### Pawndoc

The compiler has always been able to generate documentation from comments, and this is now officially supported within the official includes.  (Almost) every function has a documentation comment before it (denoted by `///` and `/** */` as opposed to `//` and `/* */`); which includes information on parameters, usage, and which library the function is defined in.  When a mode is compiled with the `-r` flag a `modename.xml` file is generated along-side the other output with all this information collated.  An included file called `pawndoc.xsl` can be used to pretty-print this XML as HTML or markdown for further use.  The included XSL has more features for things like macros, enums, and grouping library declarations together.  See [the pawndoc repo](https://github.com/pawn-lang/pawndoc) for more information.

The documentation generation and grouping by file are especially useful for library writers, who can put all the information canonically in a single place then extract just their parts of interest with ease.

### Deprecation And Unimplemented

Any functions that were once in SA:MP but have since been removed (either by later SA:MP versions or open.mp itself) are declared as:

```pawn
forward void:SetDeathDropAmount(amount);
```

The `forward` on its own (i.e. with no implementation function) ensures that a special error message is given when code attempts to call it.  Rather than `Undefined symbol "SetDeathDropAmount"` the compiler gives `"SetDeathDropAmount" is not implemented`, which is far more specific error and makes it clear that the issue is not a typo or other mistake.  These unimplemented functions may give hints on alternative solutions to do the same thing:

```pawn
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
forward void:EnableTirePopping(bool:enable);
```

Some functions are deprecated but not removed, meaning they still work but using them isn't recommended and they may disappear at some point in the future.  For example:

```pawn
#pragma deprecated This function is fundamentally broken.  See below.
native GetPlayerPoolSize();
```

Some will suggest alternative methods to do the same thing:

```pawn
#pragma deprecated Use `GetConsoleVarAsString`.
native GetServerVarAsString(const cvar[], buffer[], len = sizeof (buffer));
```

Some are just replaced with new versions with better names:

```pawn
native DB_GetRowCount(DBResult:result);

#pragma deprecated Use `DB_GetRowCount`
native db_num_rows(DBResult:result);
```

Or names that are spelt correctly:

```pawn
native bool:TextDrawColour(Text:textid, textColour);

#pragma deprecated Use `TextDrawColour`
native bool:TextDrawColor(Text:textid, textColour);
```

Or less terse names thanks to the increased symbol limit:

```pawn
#pragma deprecated Use `SetPlayer3DTextLabelDrawDistance`
native bool:SetPlayer3DTextLabelDrawDist(playerid, PlayerText3D:textid, Float:drawDistance);

#if __namemax > 31
	native bool:SetPlayer3DTextLabelDrawDistance(playerid, PlayerText3D:textid, Float:drawDistance);
#endif
```

This final example will only compile the longer name when using the 3.10.11 compiler, but the deprecation warning will always exist even on compilers with a lower limit (because you should update).

 Function Changes
------------------

A list of function behaviour changes between SA:MP and open.mp.  Most of these changes were previously in the precursor to open.mp - fixes.inc.  This does not include general bug fixes except when the fix is especially notable.  This list may not be exhaustive, but attempts to cover the most common changes.  Feel free to submit a PR if you find more:

* `random` now works for negative numbers.  Calling `random(-5)` will return any of `0`, `-1`, `-2`, `-3`, or `-4`.  As with `random(5)` the specified number will not be returned, if instead you want the upper limit (i.e. `0`) skipped just do `random(-5) - 1`.
* `GetPlayerPoolSize` returns `-1` when there are no players (thus no upper ID).  This function is also now deprecated because so many people were using it wrong that fixing it safely became impossible.
* `GetVehiclePoolSize` returns `-1` when there are no vehicles (thus no upper ID).  This function is also now deprecated because so many people were using it wrong that fixing it safely became impossible.
* `GetActorPoolSize` returns `-1` when there are no actors (thus no upper ID).  This function is also now deprecated because so many people were using it wrong that fixing it safely became impossible.
* `ClearAnimations` no longer removes players from vehicles, only stops animations returned by `GetPlayerAnimationIndex`.
* `RemovePlayerFromVehicle` has an optional `force` parameter is stop all driving and entering vehicles instantly.
* `OnPlayerDisconnect` is called with `reason = 4` when the script ends to distinguish it from players leaving the server.
* `OnPlayerConnect` is called when filterscripts start, in line with the behaviour in gamemodes.
* `GetVehicleComponentInSlot`, `AddVehicleComponent`, `RemoveVehicleComponent`, and `OnVehicleMod` have two additional slots, bringing the total number of component slots up to 16.  `CARMODTYPE_FRONT_BULLBAR` is used for components `1100`, `1115`, `1116`, `1123`, and `1125`; `CARMODTYPE_REAR_BULLBAR` is used for components `1109` and `1110`; which were all previously in slots `CARMODTYPE_FRONT_BUMPER` and `CARMODTYPE_REAR_BUMPER`.  This is because those slots could contain two mods at once, both shown but only one accessible.
* Gang zones are clamped to the nearest whole co-ordinate and the parameters are automatially sorted to prevent visual glitches.
* A default class is used when no player classes are ever specified.
* Animation libraries no longer need to be loaded before first use.
* $100 is no longer deducted from players on death.
* `GameTextForPlayer` and `GameTextForAll` have been reimplemented with more styles and fixed times.
* Blunts and bottles no longer appear randomly on spawn.
* Colour `-1` on vehicles is now synced so all players have the same random colour.

 Appendix
----------

### All SA:MP Callback Changes

* `OnPlayerStateChange`

```pawn
#if !defined PLAYER_STATE
	#define PLAYER_STATE: _:
#endif
public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
}
```

* `OnPlayerClickPlayer`

```pawn
#if !defined CLICK_SOURCE
	#define CLICK_SOURCE: _:
#endif
public OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source)
{
}
```

* `OnPlayerEditObject`

Ideally the names of the parameters would be changed here as well to something less Hungarian, but one thing at a time...

```pawn
#if !defined EDIT_RESPONSE
	#define EDIT_RESPONSE: _:
#endif
public OnPlayerEditObject(playerid, playerobject, objectid, EDIT_RESPONSE:response, Float:fX, Float:fY, Float:fZ, Float:rotationX, Float:rotationY, Float:rotationZ)
{
}
```

* `OnPlayerEditAttachedObject`

```pawn
#if !defined EDIT_RESPONSE
	#define EDIT_RESPONSE: _:
#endif
public OnPlayerEditAttachedObject(playerid, EDIT_RESPONSE:response, index, modelid, boneid, Float:fOffsetX, Float:fOffsetY, Float:fOffsetZ, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fScaleX, Float:fScaleY, Float:fScaleZ)
{
}
```

* `OnPlayerSelectObject`

```pawn
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
public OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
{
}
```

* `OnPlayerWeaponShot`

```pawn
#if !defined WEAPON
	#define WEAPON: _:
#endif
#if !defined BULLET_HIT_TYPE
	#define BULLET_HIT_TYPE: _:
#endif
public OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ)
{
}
```

* `OnPlayerKeyStateChange`

```pawn
#if !defined KEY
	#define KEY: _:
#endif
public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{
}
```

* `OnPlayerRequestDownload`

```pawn
#if !defined DOWNLOAD_REQUEST
	#define DOWNLOAD_REQUEST: _:
#endif
public OnPlayerRequestDownload(playerid, DOWNLOAD_REQUEST:type, crc)
{
}
```

* `OnPlayerTakeDamage`

```pawn
#if !defined WEAPON
	#define WEAPON: _:
#endif
public OnPlayerTakeDamage(playerid, issuerid, Float:amount, WEAPON:weaponid, bodypart)
{
}
```

* `OnPlayerGiveDamage`

```pawn
#if !defined WEAPON
	#define WEAPON: _:
#endif
public OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart)
{
}
```

* `OnPlayerGiveDamageActor`

```pawn
#if !defined WEAPON
	#define WEAPON: _:
#endif
public OnPlayerGiveDamageActor(playerid, damaged_actorid, Float:amount, WEAPON:weaponid, bodypart)
{
}
```

* `OnPlayerDeath`

```pawn
#if !defined WEAPON
	#define WEAPON: _:
#endif
public OnPlayerDeath(playerid, killerid, WEAPON:reason)
{
}
```

The `WEAPON:` enum has a few extra `REASON_` values to support this use-case,  Namely `REASON_VEHICLE`, REASON_DROWN`, `REASON_COLLISION`, `REASON_SPLAT`, `REASON_CONNECT`, `REASON_DISCONNECT, and `REASON_SUICIDE`.

### All Streamer Callback Changes

* `Streamer_OnItemStreamIn`

```pawn
#if !defined STREAMER_TYPE
	#define STREAMER_TYPE: _:
#endif
public Streamer_OnItemStreamIn(STREAMER_TYPE:type, STREAMER_ALL_TAGS:id, forplayerid)
{
}
```

* `Streamer_OnItemStreamOut`

```pawn
#if !defined STREAMER_TYPE
	#define STREAMER_TYPE: _:
#endif
public Streamer_OnItemStreamOut(STREAMER_TYPE:type, STREAMER_ALL_TAGS:id, forplayerid)
{
}
```

 Further Reading
-----------------

https://github.com/pawn-lang/samp-stdlib/tree/consistency-overhaul - The SA:MP includes updated with const-correctness and more tags.
https://github.com/samp-incognito/samp-streamer-plugin/pull/435 - A streamer plugin PR with more information on this tag system.
[https://github.com/pawn-lang/compiler/wiki/What's-new#const-correctness](https://github.com/pawn-lang/compiler/wiki/What's-new#const-correctness) - Compiler changes, incorrectly lists const-correctness as a "breaking" change.
https://github.com/pawn-lang/compiler/wiki/Const-Correctness - More information on const-correctness and updating code.
https://github.com/pawn-lang/sa-mp-fixes/ - Origin of many fixes, including several trivial ones integrated in to open.mp but not listed here.
https://github.com/pawn-lang/compiler/raw/master/doc/pawn-lang.pdf - For more information on strong and weak tags.
https://github.com/openmultiplayer/upgrade - A tool that can automate a lot of tag- and const-correctness upgrades.

