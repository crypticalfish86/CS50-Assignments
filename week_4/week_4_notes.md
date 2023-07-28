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

because it starts at the value its given and
continues till it reaches \0 if you use %s in
printf

this can be used to print a substring