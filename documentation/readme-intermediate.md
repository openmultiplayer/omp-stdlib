open.mp is the culmination of years of gradual improvements, fixes, and hard-learnt best practices for pawn code and SA:MP.  It is the direct continuation of several projects all with the same aim - making online San Andreas better for.  As a result the whole system should be smoother and less frustrating for those just learning, but may be a slight shock to existing scripters who have not kept up-to-date with these developments.  Fortunately these changes are easily adapted to.

 Compiler Changes
------------------

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

Of course, you can still pass modifiable variables to `const` functions and safely know that they won't be modified:

```pawn
native SendRconCommand(const string:cmd[]);
new cmd[32];
format(cmd, _, "loadfs %s", scriptName);
// `cmd` is allowed to be modified, but `SendRconCommand` won't do so.
SendRconCommand(cmd);
```

### Include Guards

On older compilers the following code:

```pawn
#include <my_include>
```

Imported all the code from inside the `my_include.inc` **if it wasn't previously included**.  It is equivalent to:

```pawn
#if !defined _inc_my_include
	#define _inc_my_include
	
	// `my_include` code goes here.
#endif
```

The new compiler by default no longer checks if the file was previously included, so includes need custom include-guards (note that this is the only true *breaking* compiler change).  Add code like this to the top of your include (not needed in a gamemode):

```pawn
#if defined _INC_my_include
	#endinput
#endif
#define _INC_my_include
// `my_include` code goes here.
```

`my_include` should be customised to something unique for your include.

 Include Changes
-----------------

### More Tags

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

Native functions that don't return any useful value have `void:` tags to indicate this fact.  The compiler doesn't enforce this by default but can with:

```pawn
#define VOID_TAGS
#include <open.mp>

main()
{
	// Now a (slightly inaccurate) warning claiming that `ShowPlayerMarkers`
	// should return a value.  It shouldn't, and you shouldn't use it.
	new useless = ShowPlayerMarkers(PLAYER_MARKERS_MODE_GLOBAL);
}
```

The tags are all *weak* - passing an integer instead of an enum value is a warning, but the reverse isn't.  The latter can be enabled by making the tags *strong*:

```pawn
#define STRONG_TAGS
#include <open.mp>
```

Alternatively, if you really hate help:

```pawn
#define NO_TAGS
#include <open.mp>
```

The only breaking change introduced by these new tags are on callbacks.  The best way to deal with these is to ensure that the `public` part of the callback will compile regardless of tag settings by falling back to `_:` when none is specified (which is fully backwards-compatible):

```pawn
#if !defined SELECT_OBJECT
	#define SELECT_OBJECT: _:
#endif
forward OnPlayerSelectObject(playerid, SELECT_OBJECT:type, objectid, modelid, Float:fX, Float:fY, Float:fZ);
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

### Deprecation And Unimplemented

Many removed functions are now marked as *unimplemented*, meaning calling them is an error.  These will often suggest an alternative:

```pawn
#pragma deprecated Use `OnPlayerClickMap`.
forward void:AllowAdminTeleport(bool:allow);
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
#pragma deprecated Use `DB_GetRowCount`
native db_num_rows(DBResult:result);
```

Or names that are spelt correctly:

```pawn
#pragma deprecated Use `TextDrawColour`
native bool:TextDrawColor(Text:textid, textColour);
```

Or less terse names thanks to the increased symbol limit:

```pawn
#pragma deprecated Use `SetPlayer3DTextLabelDrawDistance`
native bool:SetPlayer3DTextLabelDrawDist(playerid, PlayerText3D:textid, Float:drawDistance);
```

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

