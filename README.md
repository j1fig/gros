gros
====

GROS (Global Route Optimization System), a C++ library for global routing optimization.


Development configuration
----

Development is being done in Codeblocks 12.11 in Ubuntu Linux 12.04 LTS.
The project may be imported in Codeblocks in Windows or OSX as Codeblocks is a multi-platform IDE.

The GROS base code (without GUI) is portable across OS. The same foes not apply for the GUI, because this is typically OS-dependent.

The .cbp files are already configured with the relative paths to the include,search and lib folders that are necessary for building the system.

GROS.cbp Project
----

This project implements the system, and also features a visual debug mode, built by #define 'ing the GUI_DEBUG flag in main.cpp.
The GUI_DEBUG flag, will build with X11 lib dependencies, and so requires UNIX-based system that has these libs.


GROSTest.cbp Project
----

This is the unit testing project for GROS. It uses UnitTest++, a minimalistic C++ unit-testing framework, to perform unit tests to each of the modules deemed appropriate.

