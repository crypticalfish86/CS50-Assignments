COMPILING

in the CLI how you've been compiling source code
is using the "make" command, however "make" itself 
is not actually a compiler. all it does is automate
the process that actually runs a compiler.

there are two main compilers for C, one is called
GCC one is called clang.

in cs50 we will use clang

to use clang we use the following:

1. write source code file
2. clang -o hello hello.c (-o names your compilled program as hello) 
3. ./hello (to run the program)

the -o in step 2 means "output"
NOTE THIS ONLY WORKS FOR WHEN YOU ARE USING BASIC
C LIBRARIES IT WILL THROW YOU AN ERROR IF YOU
USE THIRD PARTY LIBRARIES

how to run it with 3rd party libraries like cs50
you must modify your command a bit:

1. write source code file with custom libraries
2. clang -o hello hello.c -lcs50 (names your 
compiled program as hello and retrives the library
code for cs50)
3. ./hello (to run the program)

the l in -l"library_name" means "library"

now the compiler knows to retrieve the 0s and 1s
neccessary to interpret the third party libraries
functions

we will only need to use clang in your cs50 course
for specific circumstances, make will still be used
for now but in the real world you will use the 
other method

in compiling there are actually 4 steps:

1. preprocessing
2. compiling
3. assembling
4. linking

preprocessing:
    when you install C there is a hidden file on 
    your hard drive that stores all the standard
    C libraries e.g. <stdio.h> this contains
    the assembly language required to interpret
    the functions in those libraries (this is 
    where we would store third party libraries
    like cs50 too)
    so preprocessing looks for any line that begins
    with "#" and go retrive that file on your hard
    drive

compiling:
    once a program has been pre processed, it now
    looks only into main (as everything outside
    of main has been interpreted), now what it does
    is actually convert your source code in C into
    "assembly code" (NOT 0s and 1s, assembly can
    still be interpreted by a human it just looks
    extremely hard to read)

assembling:
    this is where the assembly code that was created

