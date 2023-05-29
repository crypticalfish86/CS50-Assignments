programs we write in any language work using space in our RAM we have a finite amount of memory
This means there will be a limitation in the amount of 0s and 1s we can play with
and therefore we can only count up to a certain value per variable.
Computers tend to use 32-bits in 0s and 1s to represent a single integer variable. 

smallest number we can represent using 32 bits is this:
00000000000000000000000000000000
this = 0

largest number we can represent using 32 bits is this:
11111111111111111111111111111111
this = 429467295
roughly 4 billion

HOWEVER a variables maximum number is actually half of this (2147483647 roughly 2 billion), this is because the other half is actually used to represent negative numbers

if we have an increment that happens to surpass this value in the positive direction it actually 
loops around and = -2147483647 and then begins counting up in negative numbers back to 0

this is called integer overflow where you want to use more bits than you have available.

we can address this in c using "longs" which are defined just like ints like so:

long x = 60000000;

to printf you would use "%li" instead of "%i"

longs use 64 bits to store its value instead of 32 bits and can count up to 9 quintillion