BASICS OF STACKS AND QUEUES

A queue is a built in data type into C, they 
can be  described as "first in first out" data 
structures that "queue" data in a first in first 
out pattern.

there are two functions you use to queue data:

enqueue(); 
to add data to a queue (to the end of the queue)

dequeue(); 
remove the data first in the queue from the 
queue.


This is in contrast to a different data type called a "stack", a stack is a "last in first out"
data structure that stack up data. 

adding and removing from a stack is through the two following functions:

push();
add data to a stack

pop();
remove the last piece of data added to the stack 
from the stack.

(remember javascript, arrays)

HOW TO USE A STACK OR QUEUE

to create a stack you would use a struct like this:

typedef structs
{
    "datatype" "variable_name"[CAPACITY];
    int size;
}
stack;

note that "size" and capacity are different numbers

CAPACITY is how high the stack could theoretically 
be (the maximum possible size of the stack).

While size is the currrent actual size of the 
stack (how many datapoints are in the stack right 
now).

the problem is we'd need to initiate [CAPACITY] 
somehow in a way that doesn't waste too much 
memory or doesn't overflow the capacity, so we'd 
somehow have to variably resize the array if we 
get close to the end of the array, can we resize 
an array in C?

RESIZING ARRAYS

Say we had an array of size 2 that holds the values
[1, 2, 3] and we wanted to add a 4th integer to 
the end of the array. 

We cannot simply allocate the exact next byte to 
"grow" the array because what if the next byte is 
storing other data used in our program, it would 
be too dangerous to do.

what we can do is copy array values over to a new array like so:

e.g.
#include <stdio.h>
#include <stdlib.h>

int main void()
{
    int *list = malloc(3 * sizeof(int));
    //manually initiating an array of size 3

    if(list == NULL)
    {
        return 1;
    } 
    /*always do this check before adding values to 
    a malloc array because this is the default 
    memory value for malloc if your computer is out of memory*/

    list[0] = 1;
    list[1] = 2;
    list[2] = 3; 
    /*declaring variables now we have full array
    and wouldn't be able to add any additional 
    variables without crashing our program*/

    int *tmp = malloc(4 * sizeof(int))
    //here we have a new array of 4 integers
    
    for(int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    tmp[3] = 4;

    free(list);
    /*here we are freeing the memory for list now that we've copied over all the values*/

    list = tmp;

    /*here after we have freed list and its max 
    size of 3, we are now reallocating values to 
    list by giving it a new pointer value, now 
    when we call list it now has the 4th values 
    and looks like this: [1, 2, 3, 4]*/

    return 0;
}

this is a VERY inefficent way of doing things 
actually (however a good example of how we can 
simply assing a new pointer to a previous variable)
because we are taking time to copy over each 
individual value in the array

LOOK TO THIS FOR HOW TO PROPERLY FREE AND ALLOCATE 
MEMORY ^



instead what we can do is reallocate memory to a 
list using realloc like this:

#include <stdio.h>
#include <stdlib.h>

int main void()
{
    int *list = malloc(3 * sizeof(int));
    //manually initiating an array of size 3

    if(list == NULL)
    {
        return 1;
    } 
    /*always do this check before adding values to 
    a malloc array because this is the default 
    memory value for malloc if your computer is out of memory*/

    list[0] = 1;
    list[1] = 2;
    list[2] = 3; 
    /*declaring variables now we have full array
    and wouldn't be able to add any additional 
    variables without crashing our program*/

    int *tmp = realloc(list, 4 * sizeof(int));
    /*here we created a new pointer by 
    reallocating the values in  memory of list to 
    tmp, tmp now includes all 3 values of list as 
    well as a currently empty 4th value for us to 
    use*/
    
    list = tmp;
    //realloc auto-free's list and so we don't 
    need to free(list); instead all we need to do 
    is reassign the pointer tmp to list, and now 
    we have effectively grown the array.

    return 0;
}

realloc has been used to do all the copying for 
us, realloc will take start at the first index of 
your pointer you specified in your first argument 
and continue copying all values to that new array 
up to how many bytes in memory you specified in 
the second argument. It will also then free the 
memory the first argument is taking up, which is 
why we can just reassign tmp to list like above ^

realloc works by taking the relevant pointer as 
the first argument and reallocating that number 
of bytes to a new pointer as well as freeing the 
original pointer adress.

LINKED LISTS (CONCEPT)

A linked list is what will actually allow us to
stitch different memory addresses together in order
to create long lists or arrays using memory not directly next to each other

for example say i'm storing the value: 

1 at 0x123
2 at 0x456
3 at 0x789

this is not an array because these values are not
contiguous in memory and so the computer
cannot automatically iterate over from 0x123

the solution to this problem will be to create
a data structure containing the memory addresses
of the value next in the list, with 1 having
memory attached to it indicating the next
index in the list is 0x456 leading to the 2
which will have linked to it the adress to the
3 0x789.

The three is the final value in the list and so
it will have linked to it 0x0 or NULL to indicate
that.

this list actually does not begin with 1 but
with the starting memory adress as a pointer
to the memory address 0x123

so the list ends up looking like this:

0x123, 0x456, 0x789, NULL

this is an example of a "single linked list"
meaning once you go to one memory address
there is no link back to the previous memory
address, only the next adress in the list,
if we wanted to we could create a double linked
list which also indicates the previous memory 
adress which we just came from.

A value attached to a forward memory address
as a packet of data is called a "node" in 
compuer programming.

CREATING A LINKED LIST

In order to create a node we would do something
like this:

\/observe here we have implicitly declared the 

typdef struct node 
struct
{
    int number; //value of the current node
    struct node *next; //address of the next node
}
node;

see we have used the struct data type node in our
node itself, this wont work unless we put node
above our node struct like in the above example

then note in our actual struct we have called
"struct node" instead of just "node" these
are all the steps you need to do to self refer
a data structure inside a data structure.

ACTUALLY WRITING A LINKED LIST/NODEs

now that we know how to set up a node, assuming
we have set up using the structure above lets
declare a list in code like so:

node *list = NULL;
/*this is the pointer to the first 
node in our list, it will initially contain a 
value of NULL*/

node *n = malloc(sizeof(node));
/*here we are creating a node with enough memory
assigned to it to fit the size of a node*/

(*n).number = 1;
/*here we are assigning the value of the node n
as 1, remember *n here is not the pointer but the
value of the memory address because we are not
initiating a value*/

this syntax is terrible however so C actually
allows us a simpler syntax which looks like this:

n -> number = 1; we are doing the exact same
as above but instead it looks much more user 
friendly, what this is doing is essentially going 
to the memory address of the pointer n and 
changing the value of the struct variable "number" 
assigned to that node.

n ->next = NULL;
//here we are assigning the next variable of the 
node struct as NULL signifiying the end of the 
list.

here is the full code:

typdef struct node 
struct
{
    int number;
    struct node *next;
}
node; //defining the struct node

node *list = NULL; //initialising list

node *n = malloc(sizeof(node));
//initialising first node

list -> number = 1; 
//initialising list number value
n -> number = 2;// initialises n number as 2
list -> next = n; //links list with n, making n 
the second and last value in the list.

n ->next = NULL;// lists n as the end of the list


CREATING LISTS USING NODES


CREATING A STACK:

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for(int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            return 1;
        }
        n->number = number;
        n-next = NULL;

        n->next = list;
        list = n;
    }
    node *ptr = list;

    while(ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next; 
        //pointer has iterated to next number in 
        the list
    }

    ptr = list;
    while(ptr != NULL) //this loop frees the memory
    {
        node *next = ptr ->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}

this is creating a stack not a queue.

TREES

trees are essentially a 2dimensional list,
which gives you the efficent ability of growth
of a list, with the efficency of the sorting
of an array.

trees as opposed to lists have 2 "next" pointers
associated with them, this is still considered a 
node but is a more complicated one.

see this array:

[1, 2, 3, 4, 5, 6, 7]

take the middle, value which is 4, that is now the 
start of the tree, it is connected to the two 
digits second closest (the next even numbers) and 
those numbers are then connected to the numbers 
next to them, it ends up looking like this:

           <- 4 ->
          ↓       ↓
        <-2 ->  <-6 ->
        ↓    ↓  ↓    ↓
        1    3  5    7

see how each node has 2 pointers associated with 
each value, we can now more quickly and efficently 
get to each value this way

trees are generally sorted through like so
you begin at 4, if you're looking for the number
3, 4 is greater than the number you're looking for 
so you would take the left most node to go down to 
the two, then you check again and see if the 
current node is equal to, smaller than or greater 
than the number you're looking for, in this case 2 
is less than the number you are looking for so you 
would go to the right, thereby finding 3.

here is what our tree node would look like

typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

a function to search through a tree would
look something like this

bool search(node *tree, int number);

where tree is the first pointer in the tree or the 
"root" and number being the number you're looking 
for.

here is the code:

bool search(node *tree, int number)
{
    if(tree == NULL)
    {
        return false;
    }
    else if(number < tree->number)
    {
        return search(tree->left, number);
    }else if(number > tree->number)
    {
        return search(tree->right, number);
    }else if(number == tree->number)
    {
        return true;
    }
}

we can use recursion to search through a tree like 
this efficently.

DICTIONARIES

a dictionary is a struct that has "key value pairs"
meaning there is a key (kind of like a memory 
address but we specifically decide its name) and a 
value (like the value held at an address).

HASHING AND HASH TABLES

a hashing is the idea of converting a large dataset
into multiple smaller datasets so that its easier to manage.

we can sort a dataset into tables to quickly sort
and access the data.

A hash table is essentially an array of linked 
lists, essentially an "array of pointers to nodes".

TRIES

tries are fancier trees each of whos nodes are
arrays. If you want to store alphabetical data, 
the first array would represent the first letter 
of the word, with a pointer to another array 
representing the alphabetical order of the second 
letter of the list and so on until a word is found.

this structure of course uses a ridiculous amount 
of memory.

this is the most efficent data type but its 
extremely memory demanding.