 The View
----------

Starting Qawno will give the following view:

![The initial view of Qawno once freshly opened.](documentation/initial-view.png)

The three main panes are:

* Top-Left - The main code view, where you write pawn.
* Bottom-Left - The compiler view, where you can see issues with your code.
* Right - The function list, with natives found in open.mp and third-party includes.

 The Code
----------

First we *include* another file, meaning we get access to all the code in there as well, allowing access to all the features of the server - things like vehicles, objects, map icons, and more.  The file is called `open.mp.inc`, but you don't need the extension.  There are many other *third-party* includes and components we can also download to provide more features.  Once your script starts growing beyond a few simple functions you will also want to start splitting the code in to multiple files to help with code management:

```pawn
#include <open.mp>
```

The green text after this include is called a *comment*.  It starts with `/*` and ends with `*/`.  The colour is to visually distinguish it from real code, because nothing in comments are compiled or run.  They are purely there to give information to humans reading the source code.  Comments can also start with `//`, that style finishing at the end of the line, not an explicit delimiter:

```pawn
/*
     ___      _
    / __| ___| |_ _  _ _ __
    \__ \/ -_)  _| || | '_ \
    |___/\___|\__|\_,_| .__/
                      |_|
*/
```

Now we get to our first custom code in a *function* - this one is called *main* and is special.  It is called when the mode first starts, but so is another function called `OnGameModeInit`, and most startup code tends to be found there instead.  So this function just prints a message, *printing* meaning it is displayed in the console window and not anywhere else.  The code between the *braces* (`{}`s, often incorrectly called *brackets*) are "inside" the function so when this function is called that is the code that is run:

```pawn
main()
{
	printf(" ");
	printf("  -------------------------------");
	printf("  |  My first open.mp gamemode! |");
	printf("  -------------------------------");
	printf(" ");
}
```

Then we get our first true *callback*.  A *callback* is a function in our code that the server calls at some time (in this case, when the mode starts).  Callbacks are always `public`, which allows the server to see them, and usually start with `On`, meaning "up*on* this event":
`
```pawn
public OnGameModeInit()
{
```

A *callback* is in contrast to a *native*, which is a function in the server that our code calls to do something.  `SetGameModeText`, the next line, is one such *native* and it defines the mode name seen in the server browser:

```pawn
	SetGameModeText("My first open.mp gamemode!");
```

![The custom mode name shown in the server browser.](documentation/mode-name.png)

 the server to add a skin to the class selection screen before a player first spawns.  This sets the skin as `43` (), the position (``) somewhere in Los Santos, the angle (``) facing south, and then gives the player three weapons with various levels of ammo  This is where the player will be after they select a skin and spawn, it is not where the skin appears while being selected.  Try duplicating this line and changing the co-ordinates to see where you spawn.  Or open the client debug mode and type `/save` while on foot to generate more of these lines:


Finally, although running around is fun, this is *Grand Theft Auto* - we need some *autos*!  So create a vehicle that will spawn (and respawn after death) near to where the player will spawn:

```pawn

```

## Compiling

The server doesn't run the same code as you write, it needs to first be converted in to a format that's better for computers (but way way worse for people).  This process is called *compiling*.  Sometimes when you compile there will be mistakes in your code that mean it cannot be converted in to the computer format - these are *errors* and will mean the compilation fails entirely.  There can also be minor mistakes that won't stop the code compiling, but might mean the result is wrong anyway, these are pointed out to you as *warnings*.  It is important to know the difference as far few people understand this distinction.

Errors - Code cannot run at all.
Warnings - Code can run but might do the wrong thing.

Then there's the third type of mistake, similar to warnings but the compiler can't spot them - *bugs*.  This is just code you've written that doesn't do what you want, but does something that is technically valid.  Dropping a player from 1000 units in the sky might not be what you wanted, but it is valid behaviour.  So there are no messages when you make these mistakes and you'll just have to work out why things aren't doing what you want.  No warnings or errors doesn't mean your code is correct - welcome to debugging!

