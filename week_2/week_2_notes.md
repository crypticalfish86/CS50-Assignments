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

ARRAYS

because bytes are stored physically in memory
they have physical attributes, and because they
have physical attributes they can be ordered
and have addresses we can assign to them based
on their position in the chip, this can be
simplified as the "memory address". 

an array is a method of storing your data where
each index is stored back-to-back in memory
right next to each other, if you run from the 
memory address at the beggining of the array and
cycle through memory, each consecutive memory
address stores the next indexed datapoint

declaring an array in C looks like this

int score[3];

int is the type of data in the array (only one 
type can be stored in an array)

score is the array name

3 is the maximum amount of indexes in the array
(note 3 is the human number so the max length
of the array would be score[2] because arrays
start at 0)

to pass an array into a function you would
structure the parameter like this:

void function(int arr[]);

void is the return value of the function,
int arr[] represents an array of integers
can be passed into this function 
(doesn't need to be called arr can be called 
anything)

a string just like in any other language is just
an array of characters. because a string has to
end at a certain point and because it is 
potentially endless we need some sort of indication
for the computer where the string ends, so a string
is an array with an extra character right at the 
end which looks like this : "\0" this is always
the final character of a string. in actual binary
the \0 the computer reads as 0, so the computer 
knows for a string to read every character of a 
string until it reaches a 0 which marks the end
of a string.

a string as part of an array is then an array
inside an array (technically a 2D matrix). 

in reality an array within an array doesn't
store an entire array in a byte of memory,
all it does it ensure that each array inside
the super-array has its index values in order
one after the other and then the next array
on the next index of the super-array begins with 
its indexes right after.

you can figure out the length of a string
with strlen("string") from the <string.h>
library (comes with C)

another useful library would be <ctype.h>
it has many different uses, one very useful
one would be the islower('char') which we
can use to determine if a character is lower
case. There is also toupper('char') that
changes a character to its upper case version.

IN A FOR LOOP YOU CAN DECLARE MULTIPLE VARIABLES
AT THE START LIKE SO:

for(int i = 0, n = 1; i < n; i++)
{
    code
}

just add a "," after each variable and it can get
as long as you want.


COMMAND LINE ARGUMENTs

you can express your command line arguments all
together with a couple modifications to a main

from:

int main(void)
{

}

to:

int main(int argc, string argv[])
{

}

the void in main meant that your program took 
no command line arguments, now it takes two
arguments called argc, and argv.

argc means argument count

argv[] is an array of characters representing
all the words that you type in your command line
prompt


now we can use argc and argv[] inside our actual
main program

for example:

    source code:
    int main(int argc, string argv[])
    {
        printf("hello, %s\n", argv[1])
        printf("%i\n", argc)
    }

    command line:
    ./"file_name" Jace

    output:
    hello Jace
    2

Jace being the first word in our command prompt
after our file and 2 being the number of arguments
we passed into our file (both the calling of the
file with ./file_name and Jace which are two
different arguments)
(argv[0] would be called the file name)


EXIT STATUS

an exit status is an integer a program returns
after it has finished running, there are various
different errors with different exit codes
e.g. 404 is the universal standard for "not found"
on the internet

this is why we always use int in front of

int main(void){}

(YOU HAVE TO WRITE THE EXIT CODE YOURSELF
AND POTENTIALLY YOUR OWN DOCUMENTATION FOR
WHAT EACH EXIT CODE MEANS)

we can see the exit status by doing the following
command line prompt after incorrectly running a 
program:

    echo $?

this only works immediatley after a program
is run with an error.


CRYPTOGRAPHY

there are multiple algorthms that can encrypt
and decrypt messages, this goes back before
computer programming existed