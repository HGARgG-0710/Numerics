# Numerics

This repository contains different number types realizations that I (for some reason) needed. 
For now amongst them there is BigInt only. 

## Installation

It's super simple. Perhaps the simplest you can find. 
All you need to do is to add this repository as a git submodule of your own project. 

The idea is this: 

```bash
$ cd path/to/dependency/folder
$ git submodule add https://github.com/HGARgG-0710/Numerics.git
```

After this, just include the needeed number class using the C++ #include preprocessor directive (for example, bigint): 

``` cpp
#include "../path/to/dependency/folder/Numerics/bigint/bigint.hpp"
```

A-a-a-and that's it! 
Now the only thing left to do is to compile the whole thing using g++ (or any other compiler of your choice): 

```bash
$ g++ -Wall src/main.cpp path/to/dependency/folder/Numerics/bigint/bigint.cpp -o outputfilename.ext
```

That is how you work with the Numerics number library in general.
In order to get to see what is available in it, you'll have to visit the header files (.hpp) for the certain subprojects.  
They are usually not big and are quite good at describing the capabilities of different classes and functions. 

If you want to contribute or are just curious - go to the source code, it is also quite simple. 
More or less good documentation (or comments to things, at least) are in plans.  

## Test 

You are also able to test the parts of the library provided: 

```bash
$ cd numerics/bigint/bigint
$ make test && cd bin
$ test
```

Tests are supported for Windows only (for now at least). 