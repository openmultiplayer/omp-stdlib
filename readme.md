 open.mp Includes
==================

Welcome to the official open.mp includes, vastly upgraded and improved from the original versions - more functions, more correctness, more compile-time checks.  open.mp is the culmination of years of gradual improvements, fixes, and hard-learnt best practices for pawn code and SA:MP.  It is the direct continuation of several projects all with the same aim - making online San Andreas better for everyone:

If you are completely new to Pawn programming [click here for the beginner documentation](/documentation/readme-beginner.md), showing you how to get your first server started: [readme-beginner.md](/documentation/readme-beginner.md)

If you are an expert at Pawn programming [click here for the expert documentation](/documentation/readme-expert.md), detailing all the changes made and their reasons:  [readme-expert.md](/documentation/readme-expert.md)

If you are somewhere in between [click here for the intermediate documentation](/documentation/readme-intermediate.md), which just tells you how to upgrade your code:  [readme-intermediate.md](/documentation/readme-intermediate.md)

 Using sampctl
---------------

Many legacy libraries using sampctl will reference `samp-stdlib` and `pawn-stdlib` directly, which this library replaces entirely.  We need to trick sampctl in to not downloading those libraries so that this one takes precedence.  A new `@open.mp` branch has been added to both projects to achieve this.  They are completely empty so there are no duplicates of files.  Using this tag version in `pawn.json` in your project will ensure that and other dependencies including those libraries transitively will use the same tag, and then including `<open.mp>` in your main file will correctly set all the requisite defines to appear to those libraries like you have included `<a_samp>`.  Basically your `pawn.json` should first include:

```json
	"dependencies": [
		"openmultiplayer/omp-stdlib",
		"pawn-lang/samp-stdlib@open.mp",
		"pawn-lang/pawn-stdlib@open.mp"
	],
```

All other dependencies go ***after*** these three lines.

 Further Reading
-----------------

https://github.com/pawn-lang/samp-stdlib/tree/consistency-overhaul - The SA:MP includes updated with const-correctness and more tags.
https://github.com/samp-incognito/samp-streamer-plugin/pull/435 - A streamer plugin PR with more information on this tag system.
[https://github.com/pawn-lang/compiler/wiki/What's-new#const-correctness](https://github.com/pawn-lang/compiler/wiki/What's-new#const-correctness) - Compiler changes, incorrectly lists const-correctness as a "breaking" change.
https://github.com/pawn-lang/compiler/wiki/Const-Correctness - More information on const-correctness and updating code.
https://github.com/pawn-lang/sa-mp-fixes/ - Origin of many fixes, including several trivial ones integrated in to open.mp but not listed here.
https://github.com/pawn-lang/compiler/raw/master/doc/pawn-lang.pdf - For more information on strong and weak tags.

