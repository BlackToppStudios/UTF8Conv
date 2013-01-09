# README #
This library is a small collection of functions and declarations to assist with converting between UTF8 and Integers that store the actual Unicode Codepoint. The UTF8 representations are great for storage and transmission, while Integer values are better 

This has only been tested on little endian system and I have good reason to expect it won't work elsewhere. Big endian compatibility will be added in the future.

## Files ##
CMakeLists.txt - Use this file with CMake to create builds scripts or project files suitable for your compiler
datatypes.h - A few declaration of datatypes that is woefully ineadequate for larger projects and likely incorrect on some compilers
LICENSE - The whole Text of the GPL v3
main.cpp - Tests for verifying this library does work.
README.md - This file.
utf8conv.cpp - The implementation of this library.
utf8conv.h - The interface for accessing these functions

The easiest to use this library is to include utf8conv.cpp and utf8conv.h in your project that require their functionality

## License ##
This library is release under the terms of the GPL v3, more details can be found in the file LICENSE


## TODO ##
  - Add big endian support
  - Enable all compiler warnings
  - Remove all compiler warnings, currently just one in main.cpp in the tests portion. None known in the library files.
  - Create Doxygen docs and remove all doxygen generation warnings.
