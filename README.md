pe-parse for Visual Studio
[![Build Status](https://travis-ci.org/azerg/pe-parse.svg?branch=master)] ( https://github.com/azerg/pe-parse )
<a href="https://scan.coverity.com/projects/5766">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/5766/badge.svg"/>
</a>
=========================================

pe-parse is a principled, lightweight parser for windows portable executable files. It was created to assist in compiled program analysis, potentially of programs of unknown origins. This means that it should be resistant to malformed or maliciously crafted PE files, and it should support questions that analysis software would ask of an executable program container. For example, listing relocations, describing imports and exports, and supporting byte reads from virtual addresses as well as file offsets. 

pe-parse supports these use cases via a minimal API that provides methods for
 * Opening and closing a PE file
 * Iterating over the imported functions
 * Iterating over the relocations
 * Iterating over the exported functions
 * Iterating over sections
 * Iterating over resources
 * Reading bytes from specified virtual addresses
 * Retrieving the program entry point

The interface is defined in `parser-library/parse.h`. The program in `dump-prog/dump.cpp` is an example of using the parser-library API to dump information about a PE file. 

Internally, the parser-library uses a bounded buffer abstraction to access information stored in the PE file. This should help in constructing a sane parser that allows for detection of the use of bogus values in the PE that would result in out of bounds accesses of the input buffer. Once data is read from the file it is sanitized and placed in C++ STL containers of internal types.

Dependencies
============
[cmake]: http://www.cmake.org/
[boost]: http://www.boost.org/

Building (old)
========
pe-parse is built using [cmake] and depends on [boost].

1. Install dependencies:
  * Debian/Ubuntu: `sudo apt-get install boost-dev cmake`
  * RedHat/Fedora: `sudo yum install boost-devel cmake`
  * OSX: `brew install boost cmake`
2. `cmake .`
3. `make`

Authors
=======
pe-parse was designed and implemented by Andrew Ruef (andrew@trailofbits.com), with significant contributions from [Wesley Shields](https://github.com/wxsBSD).
