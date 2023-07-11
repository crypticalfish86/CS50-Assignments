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

THE COMPUTATIONAL PROBLEM WITH SORTING

sorting is very useful however sorting our data
itself takes time and is a problem to solve, and
therefore is not always the solution to a problem.
Sorting is a computational tradeoff, if the 
computational time needed to sort data is longer
than the time value that it gives during search
then it shouldn't be done.

there are multiple ways to sort data that the next
section will display

SELECTION SORT

Imagine an array of numbers:

[7 2 4 5 1 6 0 3]

this method of sorting starts at the start of the 
array, iterates over it, each time taking note
of the smallest number found after a full iteration
of the array and placing that at n position, 
switching the current number at n position
(in the first case n being index 0) with
the smallest found (the number currently at n
and the smallest being swapped out actually
change indexes regardless of how far along the
chain the smallest number was), it will then
begin at position n+1 and do another full iteration
and do the same switch for the now smallest number
from n+1 to the end of the array and again switch
it out.

e.g. with the example above [7 2 4 5 1 6 0 3]

begin at 7 (current smallest 7) <-- current n
iterate to 2 (current smallest 2)
iterate to 4 (current smallest 2)
iterate to 5 (current smallest 2)
iterate to 1 (current smallest 1)
iterate to 6 (current smallest 1)
iterate to 0 (current smallest 0)
iterate to 3 (current smallest 0)
end of array switch smallest with n

now array looksl like this:

[0 2 4 5 1 6 7 3]

n++
begin at 2 (current smallest 2) <-- current n
iterate to 4 (current smallest 2)
iterate to 5 (current smallest 2)
iterate to 1 (current smallest 1)
iterate to 6 (current smallest 1)
iterate to 7 (current smallest 1)
iterate to 3 (current smallest 1)
end of array switch smallest with n

now array looks like this:

[0 1 4 5 2 6 7 3]

as you can see the 2 has switched positions with
where the smallest in this iteration was previously

this continues until the smallest number is at
n = 0


in simpler pseudocode:

For i from 0 to n - 1
    Find smallest number between numbers[i] and numbers[n-1]
    Swap smallest number with numbers[i]

this is how selection sort works

The running time algorithm for this code
is: n(n - 1)/2
which is really : (n^2 - n)/2
which is really n^2/2 - n/2

so: 

O(n^2)
Ω(n^2)

meaning: Θ(n^2) no matter what it will take n^2 
         steps


BUBBLE SORT

bubble sorting is a different method of sorting,
imagine the same original array again:

[7 2 4 5 1 6 0 3]

Bubble sorts by looking at index n, looking at
index n + 1 and if n is larger than n + 1, they
will switch positions

e.g.

look at [7 2 4 5 1 6 0 3]

begin at 7 <-- current n (index 0)
look at 2 <-- current n + 1
7 is larger than 2 so switch positions
[2 7 4 5 1 6 0 3]
begin at 7 <-- current n (index 1)
look at 4 <-- current n + 1 (index 2)
7 is larger than 4 so switch positions
[2 4 7 5 1 6 0 3]


do this until you reach the end then begin 
iterating from the beggining again but up
to i - 2. After all of this the computer
does one final iteration to check that 
we have sorted properly.

As you can see because 7 is the largest
it will be present every check on the first 
iteration, essentially, the largest elements have 
"bubbled their way to the top".

If no swaps are present on the first iteration,
you break the loop.

here is the pseudocode for bubble sort:

Repeat n times
    For i from 0 to n - 2
        If numbers[i] > numbers[i + 1]
            Swap numbers
    If no swaps after entire iteration
        Quit


here is the running time algorithm:

(n - 1) * (n - 1)

meaning n^2 - 2n + 1

so again: O(n^2)
however:  Ω(n) because if no swaps quit

The bubble sort can be computationally
efficent if the data is already "almost sorted"


this is bubble sorting

both of these methods are relatively slow however
and can be sped up using recursion.

RECURSION

Recursion is when a function calls itself inside
itself, with a proper exit condition this can be
extremely powerful. 

Remember the ripping the phone book in half
question from earlier weeks? That function was
actually recursive:

Pick up phone book
Open to middle of phone book
Look at page
If person is on page
    Call person <-- exit condition
Else if person is earlier in book
    Search left half of book < -- recursive
Else if person is later in book
    Search right half < -- recursive
Else
    Quit <-- exit condition


In recursion it is ESSENTIAL to have a proper exit
condition, when using recursion the function
you are recursively calling must have a different
argument each time (which is a modification of the previous floors argumentation) and the exit 
condition must trigger when your argument reaches
a certain value, and then in C you can just
write "return;" which signals to the function
that there is nothing more to do so it simply
terminates the function.

A recursive program may be confusing to look
at, as it visually looks like you are coding
in reverse, if your next layer is executed
before the current layer, you would want
your next layer to execute before the current
layer until it reaches a certain value and then
return up the chain, executing each layer in 
reverse.

If you're in an infinite loop press CTRL + C
to terminate a program.


we can use recursion now to create a better
algorithm to sort an array

MERGE SORT

here is the pseudocode for merge sort:

If only one number
    Quit
Else
    sort left half of numbers
    sort right half of numbers
    merge sorted halves

imagine the original array again:
[7 2 4 5 1 6 0 3]

split into two arrays so:

[7 2 4 5], [1 6 0 3]

sort both arrays

[2 4 5 7], [0 1 3 6]

also make an empty "sorted array": []

compare 2 and 0 put smallest number in sorted array

[2 4 5 7], [1 3 6]
[0]

move one index across array that was sorted
compare 2 and 1 put smallest number in sorted array
[2 4 5 7], [3 6]
[0 1]

move one index across array that was sorted,

compare 2 and 3 put smallest number in sorted array
[4 5 7], [3 6]
[0 1 2]

move one index across array that was sorted
(this time it was the left array)
etc. etc.

you would find in this case the running time is

O(n log n) instead of n^2

This method does however use more memory