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
    
    In preprocessing, this is also where function
    declarations involved in "hoisting" are also
    processed and ready for use in main

compiling:
    once a program has been pre processed, it now
    looks only into main (as everything outside
    of main has been interpreted), now what it does
    is actually convert your source code in C into
    "assembly code" (NOT 0s and 1s, assembly can
    still be interpreted by a human it just looks
    extremely hard to read)

assembling:
    this is where the assembly code that was created and turns it into machine code 
    (binary), these wont be all the 0s and 1s of
    your program though, this is fixed in the
    next step

linking:
    now we combine the 0s and 1s of your source
    code with the 0s and 1s of your hard drive
    as well as any of the libraries you use, and 
    combines all the 0s and 1s together to create
    your program, the computer then executes the 
    program.

DEBUGGING

to debug at the start just use printf to print out
your variables in code and see where exactly in
code its going wrong.

computer scientists however tend to use something
called a "debugger", 

in cs50 we have a debugger first we hit the red 
"stop" which is initially unhilighted but visible
when mousing over to the left of the line number
in vs code, that is the line you're telling the
debugger to stop the code at and start running
through in human time (slowly)

you then do the following:

1. debug50 ./"file_name"
2. the debugger will then execute and highlight 
the relevant line as well as any and all local
variables at that point in the code
3. there are also now "play" and "step over"
functions, the play allows you to finish the
program, the stepover goes to the next line
and executes it
4. you can then see the new variables value
(if any have changed)

this allows you to see the variables in every
stage without needing to add massive printf's
in your code

THIS ONLY WORKS IF YOUR PROBLEM IS IN MAIN

if you want to see issues within a function
that is written below main, on the relevant
line in main you click the "step into" button
which brings you down to the line where the 
relevant function used in main is found, you
can then use that to debug your code.