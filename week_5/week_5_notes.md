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