# Chocolate_Duke3D_DC

A Sega Dreamcast port of Chocolate Duke Nukem 3D by Ivan Guber.

The project is primarily based on Chocolate Duke Nukem 3D by Fabien Sanglard.

Selected improvements and features were adapted from Belgian Chocolate Duke 3D by Tanguy Fautre (GPSnoopy), which is itself a fork of Fabien Sanglard's Chocolate Duke Nukem 3D.

The codebase has been extensively modified and extended for the Sega Dreamcast. Some of these changes have also been retained in the PC version, which is also supported.

VMU and controller vibration functionality was taken from Doom for Dreamcast by Chilly Willy 
and subsequently modified and adapted by me for Chocolate Duke3D DC.

## Credits

* **Ivan Guber** — Sega Dreamcast port and additional modifications for the PC version
* **Fabien Sanglard** — [Chocolate Duke Nukem 3D](https://github.com/fabiensanglard/chocolate_duke3D)
* **Tanguy Fautre (GPSnoopy)** — [Belgian Chocolate Duke 3D](https://github.com/GPSnoopy/BelgianChocolateDuke3D)
* **Chilly Willy** — [Doom_for_Dreamcast](https://dreamcast.wiki/Doom_for_Dreamcast)
* **Ken Silverman** — Build Engine
* **3D Realms Entertainment** — original Duke Nukem 3D

## Dependencies

The Dreamcast port requires:

* **SDL 1.2**
* **SDL_mixer**

These libraries are not included in this repository and must be provided separately.

Chocolate Duke3D
================

Chocolate Duke Nukem 3D is the equivalent of [Chocolate Doom](http://www.chocolate-doom.org/wiki/index.php/Chocolate_Doom).

A **port** that:

1. Remains as faithful as possible to the original source code.
2. Portable and compiling in one click on Windows, OS X and Linux.
3. Aimed at education, with lots of comments and documentation added in order to help programmers to understand and learn.


Requirements
============

[SDL](http://libsdl.org) and [SDL_mixer](http://www.libsdl.org/projects/SDL_mixer) to compile and run the code.

An original copy of [Duke Nukem 3D](https://3drealms.com/catalog/duke-nukem-3d_27/) (specifically the DUKE3D.GRP file from the original CD in binary working directory (and with rw permissions?)).

Build
=====

* **Linux**: Use [Autoconf/Automake](https://www.gnu.org/software/autoconf/manual/autoconf.html#Basic-Installation)
* **Windows**: Use Visual Studio 2005 or Visual Studio 2019 or [Autoconf/Automake](https://www.gnu.org/software/autoconf/manual/autoconf.html#Basic-Installation)
* **OS X**: Use Xcode 4.0


Contributors
============

* **Project Initiator:** [Fabien Sanglard](https://github.com/fabiensanglard)
* **Linux Integration:** [Juan Manuel Borges Caño](https://github.com/juanmabc)
* **Autoconf/Automake Build System:** [darealshinji](https://github.com/darealshinji)


More Information
================

* **[Review of the Duke 3D source code](http://fabiensanglard.net/duke3d/)**
* [Simple DirectMedia Layer](https://wiki.libsdl.org/FrontPage), [SDL_Mixer](http://www.libsdl.org/projects/SDL_mixer/)
* [Duke Nukem 3D](https://3drealms.com/catalog/duke-nukem-3d_27/)

License

Please see the original source files and included license/copyright notices for the applicable licensing terms.
