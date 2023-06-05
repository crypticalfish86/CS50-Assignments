COMPILING

in the CLI how you've been compiling source code
is using the "make" command, however "make" itself 
is not actually a compiler. all it does is automate
the process that actually runs a compiler.

COMPILERS FOR C

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

