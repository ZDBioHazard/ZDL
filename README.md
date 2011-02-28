What is ZDL?
------------

ZDL is a [ZDoom](http://zdoom.org/ "ZDoom Website") (or similar) frontend
designed to be *simple to use*, but also be powerful and flexible if the user
needs it to be.

Why create ZDL 4?
-----------------

ZDL 3 has always haunted me as a *terrible mess* of code that an alarming number
of people actively use. Back when I wrote it, I was still relatively new at
programming and was oblivious to the error of my ways. 

Sure, a couple people managed to swim through that *brainless morass* of code
and fix some of my bugs (Thanks Risen!), and QBasicer's ZDLSharp/qZDL has some
really cool ideas, but I feel I really need to fix it myself so I can regain my
honor and be able to *sleep* again. ;)

For the last several years, I've thought about what I would change and how I
would do things differently. (A good bit of inspiration came from QBasicer's
ZDLSharp/qZDL effort too) So now that I've discovered an object-oriented and
cross-platform development toolkit that *doesn't suck*, QBasicer and I have
decided to join forces and do ZDL right. *For reals this time.* :)

ZDL 4 has been completely re-written from the ground-up and is entirely
different in fundamental design from ZDL 3. QBasicer and I have huge, *huge*
ideas for new ways to make ZDL 4 *awesome*.

So what does that mean?
-----------------------

Our goals and philosophy for ZDL 4 include:

 * Most code should be written in Qt/C++ to allow a non-stupid way of making
   everything object-oriented and cross-platform. (among other things)
 * Dramatically higher coding standards. *No dirty hacks this time.* Code so
   clean you could *eat* off it.
 * Design and Documentation before Code.
 * Simplicity of design is *very* important. Developers should be able to pick
   up and understand the source code easily.
 * Master branch should always be buildable and relatively stable.
 * Object-oriented design facilitates the future addition of Plug-in support.
 * Unicode and Translation support are important and must work before the 4.0
   release.

New features since ZDL 3
------------------------

In addition to just plain being coded better, ZDL 4 has some new features for
the user planned, including:

 * Tab-based user interface to efficiently use window space and allows easy
   addition of future interface plug-ins.
 * A really cool interactive DMFlag calculator that supports user-defined flags.
   *No waiting for a binary update to get access to new flags!*
 * A new XML-based configuration system for maximum compatibility between
   versions and configurations of ZDL 4 and beyond.
 * Support for importing and exporting ZDL 3-style INI configurations. (Within
   the limitations of the old format of course.)
 * QBasicer is on the project, so you know at least *one* of us knows what's
   going on. ;)

Compiling and Installation
--------------------------

ZDL 4 is written using the open-source and cross-platform toolkit
[Qt](http://qt.nokia.com/) version 4. So obviously you must have it installed to
compile ZDL 4. No other library dependencies are currently planned, but may be
required in the future.

### Compiling on *nix ###
To compile ZDL 4 on *nix, just run `qmake` on `ZDL.pro` and then run `make`. The
`ZDL` binary should be created in the base project folder.

The `ZDL` binary should be able to run from wherever you put it. I expect
distributors to place it wherever it works best in their package system.

At some point in the future, ZDL 4/nix will require a `ZDLDefs.xml` file in a
known location. It will default to `/usr/local/share/zdl/ZDLDefs.xml`, but I
expect distribution maintainers to patch the source code to set the location to
whatever is suitable for the distribution.

### Compiling on Windows ###
Not sure how to compile ZDL 4 on Windows as I don't have a copy to test with. If
you can do it, send me the instructions and I'll add them here. :)

In any case, ZDL 4/Win should be able to run from wherever you put the
executable. At some point in the future, ZDL 4/Win will need a `ZDLDefs.xml`
file to sit next to it.

### Compiling on Mac ###
Not sure about compiling ZDL 4 on a Mac either. I would assume you would be able
to. If you get it working, be sure to drop me a line so I can include the
instructions here.

I'm pretty sure ZDL 4/Mac should be able to be completely self-contained in it's
own `ZDL.app` bundle.

### Compiling on Toasters ###
To compile ZDL 4 on your toaster, your toaster must have at least 16 MB of
flash, 32MB of RAM (Mostly due to the Qt/toast library), 2 slots and a 6oz crumb
tray. I don't recommend doing the actual compiling on the toaster, but if you
want to, I've found compiling to be the most stable if the toaster is set to
"Bagel" mode. YMMV of course.

ZDL 4/toast should be able to run from any one the available slots if compiled
statically, but as the Qt/toast library is a bit on the heavy side for embedded
devices, Qt should probably be installed separately in it's own slot and be
dynamically linked instead.

At some point in the future, ZDL 4/toast will require a `ZDLDefs` module to be
installed in the slot adjacent to the slot ZDL 4/toast is running in.

When the plug-in system is finished, they will most likely take additional
slots, so it would be a good idea to find at least a 4, or maybe even a 6-slot
toaster to get the most out of ZDL 4/toast.

