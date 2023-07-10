MEMORY

Remember your computers memory is just a grid of 
bytes with addresses.

an array of memory is really a sequence of closed 
doors, a computer can only open one door at a time 
and check the value. Remember the indexes of an 
array? Every single byte of code also has an index 
and its called the memory address.

The address is an index written in hexidecimal

MORE ADVANCED PSEUDOCODE

more simple pseudocode:

For each door from left to right
    If 50 is behind door
        Return true
Return false

more advanced pseudocode of same code:

For i from 0 to n-1
    If 50 is behind doors[i]
        Return true
Return false


In the second example a for loop is represented
properly, and "doors" is properly represented as
an array.


BINARY SEARCH

remember the phone book example where you're
searching an alphabetised phone book for a name,
remember how the best solution was to start in the
middle and then figure out which half the code is
on, this is called binary search and is a very 
common way of searching for a value in a sorted 
array.

here is a similar algorithm represented in 
pseudocode:


If no doors left
    Return false
If 50 is behind middle door
    Return true
Else if 50 < middle door
    search left half
Else if 50 > middle door
    search right half

More advanced psudocode you should get used to:

If no doors left
    Return false
If 50 is behind doors[middle]
    Return true
Else if 50 < doors[middle]
    Search doors[0] through doors[middle - 1]
Else if 50 > doors[middle]
    Search doors[middle + 1] through doors [n - 1]

remember arrays always end at n - 1 because they 
start with 0

There is an assumption with this type of binary 
search however and that is that THE ARRAY MUST
BE SORTED.

RUNNING TIME

Rates of performance in computer programming are
represented a bit differently than in base math.
You have to assume with performance that sometimes
a certain computer might be more powerful than 
another, therefore determining actual precise
running time is pointless.

Instead you determine the shape and general 
performance of an algorithm by the shape
of a graph where the x axis is amount of
data and y axis is time to solve (look at
lecture 22:00 in week 3)

essentially the running time is
represented using a big O and then the shape
of the graph AS IT APPROACHES INFINITY, 
e.g. for a binary search the formula is O(log n)

Big O is essentially an upper bound for how long
it can potentially take to complete the algorithm
taking into account even the slowest computer

for a linear search it would just be O(n)
because it will take as long to complete the
program as long as n is (which is the size of
the data you are processing)

There are many different formulas that can be 
applied depending on the alogrithm and these can
be applied to certain datasets of finite amounts to
determine an approximate running time.

here are all the common formulas a computer 
scientist will come across using this method:

SLOWEST

O(n^2)

O(n log n)

O(n) (or O(2n) or O(100n) essentially steps associated directly with data size)

O(log n)

O(1) (or O(2) or O(100) essentially a finite number of steps no matter what)

FASTEST


These are just the common examples, there are
likely to be many more.



There is also the best case scenario (lower bound)
formula computer scientists take into account,
it is represented using the omega symbol in greek Ω

The lower bound is how few steps an algorithm may
take.

The lower bound also uses the same formulas as 
above:

Ω(n^2)
Ω(n log n)
Ω(n)
Ω(log n)
Ω(1)

with linear search for example the actual
completed formula with both of these formulas
taking into account is as follows:

Ω(1) < TIME < O(n)

with binary search it will be 

Ω(1) < TIME < O(log n)

These formulas let a computer scientist determine
what may happen in the worst case scenario and
what may happen in the best case scenario.

When data engineers look at a program they will
use these formulas while planning out their 
algorithm to determine which methods are the most 
efficent at processing data

if some algoritm, happens to have the same upper
and lower bound, you would instead use the greek
letter Theta Θ

so:

Θ(n^2)
Θ(n log n)
Θ(n)
Θ(log n)
Θ(1)

COMPARING STRINGS

when you want to compare strings in C
what you have to do is use this in <string.h>

strcmp("first string", "second string");

returns 0 when the two strings 
are the same (for some reason they decided with 0
for true)

it returns a positive number if the first non
matching character in the first string is 
later alphebetically (or greater in ASCII)
than the second string

it returns a negative number if the first non 
matching character in the first string is earlier
alphebatically (or lower in ASCII) than the
second string

SEGMENTATION FAULT BRIEF

if you come across a segmentation faul(core dumped)
error it means you have touched memory you 
shouldn't have. Either you iterated over a value
more than once at the same time or you tried
iterating too far to a position not on the array
you were using

STRUCTS

structs are custom user made data structures,
strings and arrays are data structures provided by
the base C engine however users can create and 
tailor data structures to suit their specific needs
and interests

a struct is built in C using the following syntax

typedef struct
{
    "datatype" "variable_name";
    "datatype" "variable_name";
     etc.
     etc.
}
"struct_name";

applying values to a "struct_name" now would done 
through the following

"struct_name" "single_struct_name";
"single_struct_name"."variable_name" = "value";

e.g.

typedef struct
{
    string firstName;
    string lastName;
    string number;
    int age;
}
person;

applying values to a person now would done 
through the following

person Jace;

Jace.firstName = "Jace";
Jace.lastName = "Weerawardena";
Jace.number = "07557301204";
Jace.age = 24;


Structs can even be put in other data structures
like an array:

person people[2];

people[0].firstName = "Jace";
people[0].lastName = "Weerawardena";
people[0].number = "07557301204";
people[0].age = 24;

people[1].firstName = "Leif";
people[1].lastName = "Zix";
people[1].number = "00000000000";
people[1].age = 26;

now if we want to get Leifs first name we would
do: 

people[2].firstName;

This will give the string value "Leif"