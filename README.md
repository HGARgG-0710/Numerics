# Numerics

This repository contains different number types realizations that I (for some reason) needed. 
For now amongst them there is BigInt only. 

## Installation

It's super simple. Perhaps the simplest you can find. 
All you need to do is to add this repository as a git submodule of your own project. 

The idea is this: 

    $ cd path/to/dependency/folder
    $ git submodule add https://github.com/HGARgG-0710/Numerics.git

After this, just include the needeed number class using the C++ #include preprocessor directive (for example, bigint): 

    ``` cpp
    #include "../path/to/dependency/folder/Numerics/bigint/bigint.hpp"
    ```