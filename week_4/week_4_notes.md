Remember that each pixel on your computer screen is
represented using RGB memory, where there is a byte
associated with the variation each of the colour red, green and blue. This memory for every pixel
is stored somewhere and has an addressin the RAM.

ever see those colour codes associated with certain
colours in CSS e.g. #E201FF

this is a hexidecimal representation, of RGB,

the first 2 digits are red, the second 2 are green
and the last 2 represent how much blue is in the 
pixel

HEXIDECIMAL

Hexidecimal is a way or writing numbers in base 16
which compresses numbers into a smaller amount of
digits however is still relatively readable to a
computer scientist.

hexidecimal digits are like this

0 1 2 3 4 5 6 7 8 9 A B C D E F

so 15 in hexidecimal is F, 10 would be A and 16 
would be 10

FF would be 256 (including 0 as 1 because computer
1 is 0) coincidentally this is how many bits are in
a byte and why hexidecimal was chosen. because
its easy to represent binary in less digits
11111111 becomes FF.

F would be represented in binary with 4 bits (1111)

MEMORY ADDRESSES

every bit/byte of memory in RAM has a hexidecimal 
memory address, that address is usually structured
in bytes (8 bits) and its position is then assigned
a number which is represented to the user in 
hexidecimal. To remove ambiguity and signify
that it is computer memory in hexidecimal all 
memory addresses are prefixed with 0x to signal
"this is hexidecimal".

e.g. the first 16 bytes of memory would have these
addresses:

0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xA 0xB 0xC 0xD 0xE 0xF

the next 16 would have:

0x10 0x11 0x12 0x13 0x14 0x15 0x16 0x17 0x18 0x19 0x1A 0x1B 0x1C 0x1D 0x1E 0x1F

etc. etc.

Take this simple line of code for example:

int n = 50;

When making a variable in C (or in most 
programming languages) 3 things are happening

1. The computer is reserving space in memory
   for the variable (0xFFE02)
2. The variable is assigned a value (50)
3. the variable is assigned a name (n)


POINTERS

A pointer is really just a variable that contains
the address of a value.

in C programming if you want to access a memory
address (which is a common thing C would be used
for) 

if we want to access a memory address of a variable
we or the value of a variable we use both & and *

& for memory
* for value

e.g. for the variable above &n would give its 
memory address (0xFFE02)

if we want to print the address of a variable in
printf we would use %p, (p for memory pointer)

e.g. printf("%p\n, &n"); 

you need to use &n to get the memory address

If we wanted to assign a variable the value of
a memory address directly we would need to do
the following

int n = 50;
int *p = &n;

p's value is now the memory address of n
we have done this by using the * assigning
the value of p as the value of &n.

now if we printf("%p\n", p) 
it will give the memory address of n.

all a pointer is, is a variable that points at 
another variable.

do note two things about the example below:

int n = 50;
int *p = &n; //declaring a pointer
printf("%i\n", *p); //prints the value

even though theyre the same syntax on the outside
the *p on line 2 and line 3 mean different
things, on line 2 we are declaring a pointer,
on line 3 we are "dereferencing" (meaning
getting the value of) the value of p so even
though the syntax is similar they are different
things.


STRINGS AND POINTERS

imagine a string with the value "HI!"

string s = "HI!"

each byte would be: H I ! \0

remember each string has an extra value \0 to
signify the end of the string.

s would actually be in computer memory the address 
of the first value. The array s it turns out IS A 
POINTER

WHEN WE ASSIGN VALUES TO ARRAYS WE ARE SIMPLY
ASSIGNING A POINTER TO THE FIRST VALUE IN AN ARRAY

This is why the \0 is important because we the 
computer knows where to begin (where the pointer)
signifies is the first value and now knows where
to end (the first \0 the computer comes across) 

therefore &s would give the hexidecimal address
for s[0] which has the value of H.

now we take off the training wheels, 
YOU CAN NO LONGER USE THE KEYWORD string in
code here is the change from now on:

from:
string s = "HI!";

to:
char *s = "HI!";

this is what the cs50 library has been actually
doing under the hood all this time.

so the value (*) of s becomes the string "HI!".

note the following code:

char *s = "HI!";
printf("%p\n", s);
printf("%p\n", &s[0]);
printf("%p\n", &s[1]);
printf("%p\n", &s[2]);
printf("%p\n", &s[3]);

this will print the following

0xF134
0xF134
0xF135
0xF136
0xF137

line 2 and line 3 are the same just formatted
slightly differently as s itself is just a
pointer to the first value, then every other
memory address is as you can see right next
to each other as they are part of the same
string and so the addresses go up consecutively in 
1s. This is how arrays are stored inside computer
memory and is extremely useful in creating data
structures.

therefore you can do pointer arithmatic like so:

char *s = "HI!";
printf("%c\n", *s);
printf("%c\n", *(s + 1));
printf("%c\n", *(s + 2));

this will print the values of the addresses
that the chars of the array are stored at,
giving: HI!

this is what the computer is doing under the hood
as well when doing something like s[1] it is 
under the hood just doing *(s + 1)

s[0] is just *(s + 0) meaning just *s
s[1] is just *(s + 1)
s[2] is just *(s + 2)

remember s is just a pointer and %s in printf
is a signifier to keep going from the current 
value to when you reach \0

so if we were to do the following:

char *s = "HI!";
printf("%s\n", s);
printf("%s\n", s+1);
printf("%s\n", s+2);

the computer would print the following:
HI!
I!
!

because s is just a pointer, it's a memory
address so you are adding one to the address
each time

because it starts at the address of the first 
value given and continues till it reaches \0 if 
you use %s in printf

this can be used to print a substring

COMPARING STRINGS

You cannot directly compare strings precisely
because of the reasons above, a variable containing
a string will always just contain a pointer to the
first value and because two strings will have 
different memory addresses two identical strings
will always == false

strcmp directly compares each char in each string
to each other through a for loop and returns
the result if they're the same or not.

if you had two strings

char *s = "HI!"
char *t = "BYE!";

and did:
s = t;

s would now actually be "BYE!"
because while the original values of s are still
in memory somewhere the pointer for s has been
reassigned to the memory address of t therefore
the computer reads s goes to t's address and just
reads until it reaches \0.

do note when copying strings like this into others
its important t is initiated with a value otherwise
it will throw random values when copied onto s
and throw a segementation fault crashing your 
program.

MALLOC AND FREE

in order to safely stay inside allocated memory
and not touch any amount of memory that may be
detrimental to your program or even your computer
OS itself we have two functions in C that can
allocate and disallocate memory for C programmers
to use in their programs.

Malloc works by asking you how much memory you
want to reserve for use and then you can modify
as much information as you want within that space
and no other process in your computer will touch it
(unless you accidentally touch the memory twice
within your program in which case it will crash)


#include <stdlib.h>

char *t = malloc(4); 
/*you have now reserved 4 bytes of memory for t
and can now fill those bytes with char values. */


t is now a pointer for a chunk of free space,
malloc will return with the memory address for the
first byte of memory you ask for UNLIKE A STRING
IT IS NOT NULL TERMINATED SO IF YOU GO OUT OF 
BOUNDS WITH MALLOC IT WONT STOP YOU AND YOU WILL
CAUSE A SEGMENTATION FAULT AND YOUR PROGRAM WILL
CRASH.

malloc itself is a pointer that will be 8 bytes
in size but it points to the first byte of t.

free does the opposite of MALLOC, free takes the
address that malloc returned and disallocates that
memory allowing you to use that memory for other
things (you'll want to do this otherwise that
part of memory will stay reserved and the
computer can't use it for anything else).

all you do is add the malloc pointer inside free
to free up all the memory space:

char *t = malloc(4); 
//memory is allocated with pointer
free(t); 
//memory is freed up by feeding the pointer to free

STRCPY

now that we know how malloc and free works we 
can safely declare enough memory to copy strings
and other data structures, to automate and copy 
two strings we can use a function called strcpy()
which is in the <string.h> library:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = "hello";
    char *t = malloc(strlen(s) + 1);
    //we assign an extra byte to account for \0
    
    strcpy(t, s); //copys s and pastes it in t
    //the destination first then the source.

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    /*we check to make sure t has a string before
    modifying so we dont crash*/

    printf("%s\n", t);
    free(t); //finally we free the memory allocated
}

this should print Hello with first char capitalised

NULL

sometimes in order to signify an error, a variable
will be assigned the value NULL which is actually
a memory pointer to 0x0 which is the first byte
of memory in a computer. This is intentionally
assigned to variables to signify something not
being the case.

so we would modify the code above to this:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = "hello";
    char *t = malloc(strlen(s) + 1);
    //we assign an extra byte to account for \0
    
        if(s == NULL || t == NULL)
    {
        return 1;
    }
    //if something has gone wrong and memory could
    not be allocated we exit the program

    strcpy(t, s); //copys s and pastes it in t
    //the destination first then the source.

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }
    /*we check to make sure t has a string before
    modifying so we dont crash*/

    printf("%s\n", t);
    free(t); //finally we free the memory allocated
}

remember when using malloc, always free the memory

CREATING ARRAYS OF DIFFERENT DATATYPES

if we want to create an array manually we will
use malloc and also we can use the sizeof
function from <stdlib.h> to ensure we assign
enough memory, here we create an array of ints:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 74;
    return 1;
}

here we multiply the size of an integer by 3
so that the array has enough space for 3 integers

note we do not ever free this memory up, this 
causes a "memory leak" which is a bug where memory 
is not freed up after it has been allocated, there 
are countless bugs like this in software and there 
needs to be special software to detect them

VALGRIND

valgrind is a piece of software specifically made
to detect memory leaks.

In order to initiate valgrind you simply do:

valgrind ./program_name

valgrind is a bit esoteric to read, however it will
tell you when you missallocate memory without 
freeing the memory afterwards, how much memory is 
still allocated and tell you which line the bug is 
on.

Memory Leaks are very damaging bugs if they happen
over and over and so its important to fix them
when they appear.


MULTIPLE POINTERS TO THE SAME ADDRESS

Multiple pointers can be created to the same 
address:

int main(void)
{
    int *x = 42;
    int *y;
    y = x; //y now points to the same place as x
    *y = 13; 
    //the value at address y and x has now been 
    changed to 13
    printf("%i", *x); //this now prints 13
}

when assigning multiple pointers to the same value,
if you were to use one pointer to change the value
of the destination of the pointer, the *value
of all pointers now has also changed to what you 
changed that one pointers *value to.

SWAP (AND AFFECTING VALUES OUTSIDE OF THE LOCAL 
SCOPE OF A FUNCTION)

you've done this before but take these two 
variables:

int x = 13;
int y = 42;

if you want to swap these two variables so x 
equals 42 and y = 13 you will need a temporary 
variable in between (a relay variable as you have 
previously called it):

int relayValue = x;
x = y;
y = relayValue;

relayValue was needed to temporarily preserve
the original value of x and then apply it to y
after x is assigned the value of y.

however if we wanted to do this inside a local
function:

int main(void)
{
    int x = 13;
    int y = 42;
    swap(x, y);
    printf("%i\n%i\n", x, y);
}

void swap(int x, int y)
{
    int relayValue = x;
    x = y;
    y = relayValue;
}

THIS WILL NOT WORK and this is because when you 
put arguments into a function they are actually
creating copies of those values, as in generating
new memory addresses and assigning them to 
variables.

if we actually wanted to modify the variables
we would actually have to feed the pointers
of the variables into the function instead:

int main(void)
{
    int *x = 13;
    int *y = 42;
    swap(&x, &y); //we now pass addresses in
    printf("%i\n%i\n", x, y");
}

/*we initialise instead of an integer but a 
pointer to an integer as parameters of a function*/

void swap(int *x, int *y) 
{
    int relayValue = *x; 
    //value of pointer assigned to relay Value
    *x = *y;
    /*value of pointer y assigned to value of 
    pointer x/*
    *y = relayValue;
    //value of relay value assigned to value of 
    pointer y
}

now that we have passed the pointers in, it has 
taken the memory addresses themselves and 
reassigned the values at those addresses, you 
cannot make a copy of a memory address and 
therefore the values outside of the function
are altered too. (note the function is technically 
creating a copy of a pointer still but its a 
pointer to the same address as the one outside of 
the function and so just like how if multiple 
pointers are assigned to the same address and 
theres a modification with one then there will be 
a modification with all of them).

SCANF

scanf is a function in <stdin.h> which gets a user
input via the console and assigns it to a variable

#include <stdio.h>
#include <stdin.h>

int main(void)
{
    int x;
    printf("input integer value:");
    //prompting on console for user to input value
    scanf("%i", &x);
    //program will now wait for a user input
    printf("%i", x);
}

you put the %i in like in printf in scanf to
indicate you want to assign an integer,
and you are putting in a memory address
because remember in the previous example
it would otherwise create a copy of the variable.

if you don't type in an actual integer like shown,
scanf will default the value to 0;

MANIPULATING FILES

now that we have access to memory addresses we can
manipulate files outside of our program.

here we have a few more functions and a new 
datatype.

first a new datatype FILE which is the datatype
which is a pointer for the first byte of a file
in computer memory.

then there is fopen which returns the first byte
of a file in computer memory, connecting these two
you can do this:

FILE *file = fopen("file.csv", "a");

this assigns the first byte of a file as the value
to the variable file. note the second arguement in 
fopen is "a". This second argument is telling 
fopen what you intend to do to the file and so
preps the file for futher modification in your code
there is more than one letter here are all of them:

"r" opens a file just for reading (file MUST exist)

"w" creates an empty file for writing (if a file
with the same name already exists that file is 
erased and a new file is created in its place)

"a" Appends to a file. writing operations, appends 
data at the end of the file. the file is created 
if it doesn't exist.

"r+" opens a file to update both reading and writing to the file. the file must exist.

"w+" creates an empty file for both reading and 
writing to the file.

"a+" opens a file for reading and appending.

then there is another new function called fprintf,
fprintf essentially writes to a file and depending
on how the file is opened using fopen it will do it
in different ways:

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    string name = get_string("Name: ");
    string number = get_string("Number: ");

    fprintf(file, "%s%s\n", name, number)

    fclose(file);
}

because fopen was initialized with "a" fprintf will
append name and number to the end of the existing 
csv file,

if we had instead used "w" it would delete any file
called phonebook.csv and create an empty file and
write the name and number there

if we initalised it with "r" it would throw us an 
error because we are not authorised to edit the 
file just read its contents

finally fclose, closes the file and frees up memory
always close a file in a program at the end of your
program otherwise it will stay open which can cause
bugs.