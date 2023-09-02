# Design Document

To some of you the style of code in the official includes may seem a little strange, but everything has a reason, and those reasons are explained in here.  Almost all of them are from one of two categories - fixing bugs and quirks, or improving diagnostics (warnings).  We are going to look at almost every part of some files and explain what is going on and why.  Let's start with the obvious entry point - `open.mp.inc`.

## `open.mp.inc`

Firstly, the name.  This was just chosen so that it is included via the full name of the mod.  While most of the includes use the common (but unofficial) short form of `omp`, because this is the main include, the only one most people will import directly, it uses the full version.  Side note, the correct pronunciation is "open-dot-m-p", as if it were a domain name (which it is).

This file does only one thing - include a different file called `_open_mp`.  Why?  To make it easier to upgrade your files.  The default include files location when you download the server is `qawno/include`; they are however tracked on github in the [https://github.com/openmultiplayer/omp-stdlib](openmultiplayer/omp-stdlib repo).  When you [https://github.com/openmultiplayer/omp-stdlib.git](clone this repo) it (by default) creates a directory called `omp-stdlib`.  If you instead download the files using the (again default) [https://github.com/openmultiplayer/omp-stdlib/archive/refs/heads/master.zip](zip download option) they extracted in to a directory called `omp-stdlib-master`.  If you have used one of these two methods to place a newer version of the includes somewhere near the originals this file will attempt to find them those first, and fall back to the ones included with the server otherwise.  The priority is *git*, then *zip*, then *server*.

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

Pawno just uses almost any line that starts with `native`; Qawno is a little stricter - the line must be vaguely valid syntax, but interprets any native name that starts with `#` as a subheading in the list.  We can semi-replicate these headings in Pawno as well by using invalid lines for spacing:

```pawn
/*
native
native #Heading();
native
*/
```

## `__` prefix.

It has always been the case that the `__` prefix on symbols is reserved for the compiler and system libraries; well, these are the system libraries, so they use them.  This is to try and avoid any potential conflicts with user code - if all variables in these includes start with `__` and none in user code do there can't be any conflicts!

## `/// <p/>`

This line appears on its own in many places throughout the includes.  When you compile with `-r` a `<modename>.xml` is generated containing information about all the functions and symobls derived from documentation comments - those that start with either `///` or `/**` instead of the standard `//` or `/*`.  You will notice that all the functions declared in these includes have these documentation comments before them for exactly this reason.  Unfortunately `-r` is very broken (less so now, but still slightly).  Comments can frequently get attached to the wrong symbols.  These `/// <p/>` lines are sacrificial documentation.  In places where two comments may get merged together and become attached to the wrong place these empty comments are attached instead, allowing later comments to be parsed more correctly.

## 'public const`

This just declares a variable as being changable by the server, but not by users.  Unfortunately `public stock const` doesn't work, so if you don't read these variables you'll get a warning, hence them being immediately followed up by a `#pragma unused`.

## `static stock DIALOG_STYLE:_@DIALOG_STYLE() { return __DIALOG_STYLE; }`

This weird declaration is again related to documentation comments.  The documentation for an `enum` is always generated, but if the `enum` is never used anywhere in code the comments become unattached and form part of the global documentation, instead of a symbol's documentation.  This line just uses the enum in such as way to correctly attach the documentation to the correct symbol in the `.xml`, but not generate any additional output in the AMX.

It does however transpire that `enum`s have some minor issues when used for array indexes.  While not all of the enums declared make sense for array indexes (think `KEY`, which is a bit-map), they have all none-the-less been converted to simple `const`s instead (at great cost in documentation complexity).

