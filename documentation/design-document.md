# Design Document

To some of you the style of code in the official includes may seem a little strange, but everything has a reason, and those reasons are explained in here.  Almost all of them are from one of two categories - fixing bugs and quirks, or improving diagnostics (warnings).  We are going to look at almost every part of some files and explain what is going on and why.  Let's start with the obvious entry point - `open.mp.inc`.

## `open.mp.inc`

Firstly, the name.  This was just chosen so that it is included via the full name of the mod.  While most of the includes use the common (but unofficial) short form of `omp`, because this is the main include, the only one most people will import directly, it uses the full version.  Side note, the correct pronunciation is "open-dot-m-p", as if it were a domain name (which it is).

This file does only one thing - include a different file called `_open_mp`.  Why?  To make it easier to upgrade your files.  The default include files location when you download the server is `qawno/include`; they are however tracked on github in the [openmultiplayer/omp-stdlib repo](https://github.com/openmultiplayer/omp-stdlib).  When you [clone this repo](https://github.com/openmultiplayer/omp-stdlib.git) it (by default) creates a directory called `omp-stdlib`.  If you instead download the files using the (again default) [zip download option](https://github.com/openmultiplayer/omp-stdlib/archive/refs/heads/master.zip) they extracted in to a directory called `omp-stdlib-master`.  If you have used one of these two methods to place a newer version of the includes somewhere near the originals this file will attempt to find them those first, and fall back to the ones included with the server otherwise.  The priority is *git*, then *zip*, then *server*.

The convention for include files is to declare an include guard using the name `_INC_<filename>`, which is what `open.mp.inc` checks for to see if the latest implementation was found.  While the old compiler auto-defined and include guard using the name `_inc_<filename>` this feature was (in the only compiler breaking change) removed.  Fortunately all major includes use some variation of the manual method, and this method actually fixes some problems with path separators in the default version even when it does exist (or is enabled with `-Z`).  This is why all the other files start with the following pattern, so that you can't accidentally include them twice:

```pawn
// Was this file already included once before?
#if defined _INC_omp_textdraw
	// Yes, end the file immediately.
	#endinput
#endif
// No, mark it as having now been read.
#define _INC_omp_textdraw
```

## `_open_mp.inc`

This file sets up many compile-time options, a couple of special global symbols, and then includes everything else (again trying a few alternate locations for upgrades).

## `__pawn_build`

```pawn
#if defined __PawnBuild
	#if __PawnBuild == 0
		#undef __PawnBuild
		#define __pawn_build 0
	#else
		#define __pawn_build __PawnBuild
	#endif
#else
	#define __pawn_build 0
#endif
```

`__PawnBuild` is defined by the new compiler to give the current build number (e.g. `11` for `3.10.11`).  This is useful for checking which new features are available if you know in which revision they were added.  However, this can be awkward to check on the old compiler from before `__PawnBuild` existed, as checking it will give an undefined symbol error:

```pawn
#if __PawnBuild > 5
	// Specific version.
#endif
```

The code needed to be:

```pawn
#if defined __PawnBuild
	#if __PawnBuild > 5
		// Specific version.
	#endif
#endif
```

One work-around for this was to just always define the symbol:

```pawn
#if !defined __PawnBuild
	#define __PawnBuild 0
#endif
```

But that then broke a simple check for using the new compiler at all:

```pawn
#if defined __PawnBuild
	// Any new version.
#endif
```

So instead we declare the symbol `__pawn_build` which always has a value for the first check type, and undefine `__PawnBuild` if required for the last check type.

## `NO_TAGS`, `STRONG_TAGS`, `WEAK_TAGS`.

This is well documented in the three *readme* files, so no need to go over their use again.  The only code of note here is the use of `__pawn_build` to test the version.  Prior to `3.10.11` you could only have 16 tags in a tag group (`{Float, File, _}:` etc).  Because open.mp uses tags far more extensively this has been greatly increased for the definition of the tags available with `OPEN_MP_TAGS:`.

## `VOID_TAGS`.

See the readmes again.  This section documentes the code used to check `void:` on `native`s, since normally the compiler does not check their return types.  While you can specify that a normal function doesn't return a value, you couldn't with a `native` until now.  `#if 0` is used here to allow for demonstrating generated code with syntax highlighting for ease of reading - it is a fancy comment.  This is also the first appearance of the next weird construct...

## `/* */ native`

Pawno and Qawno both display a list of available functions in a list on the right-hand side.  This list is defined by all the `native` declarations in `.inc` files in their respective `include/` directories.  Every line that starts with `native` is added to the list; any line that starts with `/* */ native` by definition does not start with `native` and so isn't added.  Both tools are exceptionally simple in their parsing - they have no knowledge of comments at all.  To declare a native but not show it in the list use the `/* */` prefix trick, to *not* declare a native yet show it in the list, use the slightly different comment trick of using multiple lines:

```pawn
/*
native NotDeclared();
*/
```

Pawno just uses almost any line that starts with `native`; Qawno is a little stricter - the line must be vaguely valid syntax, but interprets any native name that starts with `#` as a subheading in the list.  We can semi-replicate these headings in Pawno using some clever tricks to confuse both editors in different ways - Pawno to pad the headings, and Qawno to hide things we don't want.  The code below has a number of `.`s in it, so that you can see what is happening, but you should know that each of those `.`s are in fact ASCII character `0xA0`, which renders as a space without causing the lines to be entirely elided:

```pawn
/*
native # Heading();
native ............Heading(
native .....====================(
native
*/
```

The `#` causes Qawno to render its native heading, while the other lines are all sufficiently invalid that it will entirely ignore them.  Pawno will render all four, but the first and last are sufficiently invalid to it that they will both be blank, while the other two contain padding characters for alignment.  Additionally, if the heading itself has a space between words you should also use `0xA0` in the Pawno version.

## `__` prefix.

It has always been the case that the `__` prefix on symbols is reserved for the compiler and system libraries; well, these are the system libraries, so they use them.  This is to try and avoid any potential conflicts with user code - if all variables in these includes start with `__` and none in user code do there can't be any conflicts!

## `/// <p/>`

This line appears on its own in many places throughout the includes.  When you compile with `-r` a `<modename>.xml` is generated containing information about all the functions and symobls derived from documentation comments - those that start with either `///` or `/**` instead of the standard `//` or `/*`.  You will notice that all the functions declared in these includes have these documentation comments before them for exactly this reason.  Unfortunately `-r` is very broken (less so now, but still slightly).  Comments can frequently get attached to the wrong symbols.  These `/// <p/>` lines are sacrificial documentation.  In places where two comments may get merged together and become attached to the wrong place these empty comments are attached instead, allowing later comments to be parsed more correctly.

## 'public const`

This just declares a variable as being changable by the server, but not by users.  Unfortunately `public stock const` doesn't work, so if you don't read these variables you'll get a warning, hence them being immediately followed up by a `#pragma unused`.

## `static stock DIALOG_STYLE:_@DIALOG_STYLE() { return __DIALOG_STYLE; }`

This weird declaration is again related to documentation comments.  The documentation for an `enum` is always generated, but if the `enum` is never used anywhere in code the comments become unattached and form part of the global documentation, instead of a symbol's documentation.  This line just uses the enum in such as way to correctly attach the documentation to the correct symbol in the `.xml`, but not generate any additional output in the AMX.

## Double declarations.

So most symbols are defined in `enum` for several reasons - to keep them grouped together, to collate things in the generated documentation, and for ease of declaration.  So why are all the values re-declared a second time using `#define`?  This is because different ways of declaring symbols work in different ways.  Using `enum` for a set of related values puts them together in the documentation and allows for very efficient declarations - tags can be ommitted and values inferred, leading to much terser and clearer code.  The downside to using `enum` is that it messes with arrays, since the slots will inherit the declared tags of each element, so this:

```pawn
new WEAPON:gWeapons[MAX_WEAPON_SLOTS];
```

Will produce unexpected results - the entries have the tag of `_:` not the tag of `WEAPON:`, because that's how the values inside the `WEAPON_SLOT` enum were declared.

Using `const` instead of `enum` solves this problem - there's no weird mixing of index tags and value tags, but the code is way more verbose, and the generated documentation is much more spread out; with unused values not even mentioned.

`#define` is slightly shorter than `const` in declaration length, since you only need tags once instead of twice, but they are not inserted in to the generated documentation at all.  There's also one other weird quirk - `#define` is completely ignored by `#emit`, this:

```pawn
#define NUMBER 2
#emit CONST.pri NUMBER
```

Will give an undefined symbol error.  But they're not only ignored by `#emit`, but completely invisible to it.  Meanwhile, `const` and `enum` can be used by `#emit`, even if a `#define` with the same name would normally overwrite them:

```pawn
const NUMBER = 2;
#define NUMBER 2
#emit CONST.pri NUMBER
```

That code works, and uses the `const` in `#emit`, despite the fact that it should have been hidden by the `#define`.  So we have the final solution, covering all use-cases.  It is quite verbose, but you can just use the `enum`s to more easily read the code.  This will generate compact and complete documentation, it makes reading the code easy if you only use the `enum` part, it works for `#emit` as well as normal code, and it doesn't produce weird side-effects in array declarations:

```pawn
enum WEAPON:MAX_WEAPONS
{
	WEAPON_FIST                       = 0,
	WEAPON_BRASSKNUCKLE,
	WEAPON_GOLFCLUB,
	WEAPON_NITESTICK,
	WEAPON_NIGHTSTICK                 = WEAPON_NITESTICK,
	WEAPON_KNIFE,
	WEAPON_BAT,
	WEAPON_SHOVEL,
	WEAPON_POOLSTICK,
	WEAPON_KATANA,
	// ...
}

#define WEAPON_FIST                       (WEAPON:0)
#define WEAPON_BRASSKNUCKLE               (WEAPON:1)
#define WEAPON_GOLFCLUB                   (WEAPON:2)
#define WEAPON_NITESTICK                  (WEAPON:3)
#define WEAPON_NIGHTSTICK                 (WEAPON:3)
#define WEAPON_KNIFE                      (WEAPON:4)
#define WEAPON_BAT                        (WEAPON:5)
#define WEAPON_SHOVEL                     (WEAPON:6)
#define WEAPON_POOLSTICK                  (WEAPON:7)
#define WEAPON_KATANA                     (WEAPON:8)
// ...
```

The enum names can't be used in the `#define`s as that would create an infinite loop in the compiler.

