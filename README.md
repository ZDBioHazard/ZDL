ZDL
===

What is ZDL?
------------

ZDL is a [ZDoom](http://zdoom.org/) (or similar) frontend designed to be
*simple to use*, but also be powerful and flexible if the user needs it to be.

Why create ZDL 4?
-----------------

ZDL 3 has always haunted me as a *terrible mess* of code that an alarming number
of people actively use. Back when I wrote it, I was still relatively new at
programming and was oblivious to the error of my ways. 

Sure, a couple people managed to swim through that *brainless morass of code*
and fix some of my stupid bugs (Thanks Risen!), and QBasicer's ZDLSharp/qZDL has
some really cool ideas, but I feel I really need to fix it myself so I can
regain my honor and be able to *sleep* again. :)

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
 * Object-oriented design facilitates the future addition of Plugin support.
 * Unicode and Translation support are important and must work.

New features since ZDL 3
------------------------

In addition to just plain being coded better, ZDL 4 has some new features for
the user, including:

 * Tab-based user interface to efficiently use window space and allows easy
   addition of future interface plugins.
 * A really cool interactive DMFlag calculator that supports user-defined flags.
   *No waiting for a binary update to get access to new flags!*
 * A new XML-based configuration system for maximum compatibility between
   versions and configurations of ZDL 4 and beyond.
 * Support for importing and exporting ZDL 3-style INI configurations. (Within
   the limitations of the old format of course.)
 * QBasicer is on the project, so you know at least *one* of us knows what's
   going on. ;)

...And that's only the first release. ;)

