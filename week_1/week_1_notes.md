COMPILING

Every single program that a human writes in any language is referred to as "source code"
It is the general code that all humans write, however machines don't actually understand what source code is.
Instead machines can only understand "machine code" (0s and 1s which represent on and off switches of a transistor)

Source code = human written code
machine code = machine understood code

In order to convert a machine must "compile" the code which is an under the hood algorithm that converts source code into machine code. We don't need to know the intracacies of how this works we just need to know that it is happening.


running C programs

for CS50 online cloud services purposes here is how you will create a C file using the terminal

code hello.c
 //creates the file in vsCode to input C into

make hello
//computer recognises file as a program to be run

./hello
//run the program

this will actually create another .exe file, thats the actual program the computer has comipiled into machine language which is binary for the server to recognise and use (it should be unreadable to a human).

Basics in C

in order to print something in C you do

printf("hello, world!\n");

printf is the function
"hello, world" is the string
\n inside the quotations is the "escape sequence" which allows you to print a new line
the ";" is the end of the "statement" a statement is essentially the end of a particular line of code. (not always needed, you will learn in time which ones need it and which ones don't)


what tends to happen in C is this

1. The human writes the code
2. The human inputs the command in the terminal to compile the code
3. the computer compiles the code into machine language
4. the human inputs the comman in the terminal to run the actual program (the machine code)
5. the computer runs the program

The compiler will detect errors in your code when you attempt to compile it, if errors are detected 
the compiler ceases the conversion into machine language and notifies the user of the error for them to correct.


note this line of code that generally appears at the beggining of programs:

#include <stdio.h>

this is the importation of a "library" which is essentially a piece of pregenerated code from 
elsewhere (that someone else wrote) with useful functions for you to use in your program. 
There are many libraries out there for you to use.
If you want to use the functions in the library it MUST be included at the top of the program.

<stdio.h> stands for (standard input and output)

Libraries tend to have documentation, some easier to read than others, you may need to be an experienced programmer to understand some documents.

CS50 has libraries you will use throughout this course,

e.g.
string answer = get_string("Whats, your name? ");

this functions awaits a user input and returns the input as a string to the variable "answer".

you can then plug in the answer into a printf function by doing the following:

printf("%s", answer);

%s is treated as a "plugin value", the plugin being the variable thats included as the second argument in printf.

you can chain as many %s's and variables as you want e.g.

printf("%s %s", firstName, lastName)

the first %s will be the first name and second will be the last name

if you want an actual % sign in a string you have to "escape" the % using 2 %'s like so: 

printf("100%%") this will print as "100%"

there tends to be a space after an if but not after a function:

data_type main(parameter)
{

}

if (condition)

this is not a rule its just a general consensus.

expressing equality in C is done using ==
assignment is done with one =

REMEMBER IN C YOU MUST ALWAYS DECLARE THE VARIABLE TYPE

REMEMBER TO ALWAYS RECOMPILE C CODE AFTER MAKING CHANGES OTHERWISE THE ACTUAL MACHINE CODE WOULD NOT HAVE BEEN UPDATED 

DONT FORGET CHARs REQUIRE SINGLE QUOTES '', strings require double quotes ""

conditionals:

&& and
|| or
!= not equals
>greater than
< less than

returns a boolean true or false value (in c its 1 or 0)


When declaring an existing variable you don't need to include the datatype.

loops

while(condition)
{
    code;
}

will continuously execute the code on a loop until
condition == false

for(variable_declaration; condition; variable_modification)
{
    code;
}

a for loop first allows you to declare a variable e.g. int i = 0; (this only executes once at the beggining of the first loop)
then checks the condition of that variable and if it passes then runs one loop of the code, 
then finally executes the variable modification before checking the condition again and continues to run
the loop until the condition == false (or 0 in C)


if you want a program to execute forever without an exit condition you can use a while loop:

while(true)
{
    code;
}

this will eventually take up all your computers rescources so be careful with it

C has const like javascript like so:

const int i = 9;

i can now never be modified


ABSTRACTION

C has hoisting however its less automatic than javascript all you have to do is declare the functions initially on top and then 
write the actual code below

TRUNCATION

computers sometimes suffer from a problem called "truncation" where computers lose parts of a data value
e.g. losing everything after the decimal point when dividing by an int

int x = 5;
int y = 2;
int z = x / y;
printf("%i", z)

answer should be 2.5 however instead prints 2 losing everything after the decimal point as they're integers

TYPE CASTING

we can prevent truncation by converting one datatype to another value, you must explicitly tell the compiler this.

this is done like so:

int x = 5;
int y = 2;

float z = (float) x / (float) y;

here x and y are initially integers however they
are converted to floats


FLOATING POINT IMPRECISION

just as there is an upper bound on integers, there is an upper bound on how precise floats can be.

if you only have a finite amount of bits you can only have a certain amount of precision, floats are only precise up to 5 decimal places

doubles are precise to 15 decimal places.

floats are 32 bit variables while double is 64 bit variables.