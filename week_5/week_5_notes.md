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

what we can do is use malloc to manipulate 
pointers and copy array values over like so:

we can do this via malloc:

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



instead what we can do is reallocate memory to  a 
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