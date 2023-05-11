GENERAL NOTES

computer memory is essentially an address, every single byte has a hexidecimal code/pointer associated with it.

crashes on applications tend to occur when two processes in an application want to use the exact same byte of memory with the exact same address, this causes the application to get confused and crash.

An array is a data structure that stores information in a large chunk of memory that have addresses next to each other.

Frameworks and libraries are third party code that others have produced in the same language as you and is used to simplify or automate certain processes in your program.

BINARY

Computer science itself is essnetially the "study of information". Computational thinking is the application of that study by computers.

decimal (base-1) is the traditional way of counting (1, 2, 3, 4, 5, 6, 7, 8, 9, 10) this is the most intuitive however there are issues as numbers like this for  computer memory can get extremely long and complex and a computer would find it difficult to maintain a potentially infinite amount of unique states of change like this .

computers to solve this ultimatley have just two digits, 0 and 1, this is binary a singular "bit" in computing is a single digit of binary (either 0 or 1), a byte is made up of 8 bits traditionally.

A bit for a computer is represented physically through transistors (extremely microscopic electrical switches) which turn on and off inside computer hardware, a 0 is represented by a transistor which is switched off, a 1 is represented by a transistor which is switched on. Either electricity is there or it is not.

numbers in binary to save space have to be represented as efficently as possible with the least amount of space possible, so counting in binary tends to be a pattern of switches instead of a series of switches either on or off

e.g. 
decimal: 0, 1, 2, 3, 4, 5, 6, 7
binary: 0, 1, 10, 11, 100, 101, 110, 111

if we counted in unary we would need a total of 8 switches to count up to 7 in machine language (starting at 0) however using a collection of 3 transistors in binary we can represent the first 8 numbers (0 to 7) using just 3 switches.

when looking at base-10 each column represents a different base of 10:

 123 has three in 10^0 column, two in 10^1 column and one in 10^2 column

 with binary each column like the counting compared to unary above has the same rules just each column represents a base of 2 instead.

 e.g.
 here is the number four in binary:

 11

 it has one in the 2^0 column and one in the 2^2 column 

here is the number 8 in binary on top and the base it represents in binary on the bottom:

1000
8421

this can be broken down into: (1*8) + (0*4) + (0*2) +(0*1)

the same way in decimal the number 1250 can be broken down into: 

(1 * 1000) + (2 * 100) + (5 * 10) + (0 * 1)



a byte is made up of 8 bits : 11111111
1 byte can count up to 255 as it goes up in base 2 up to the 128th base of 2 (which when all swiches are turned on it goes up to 256 or 255 in machine language because 0 is the first digit)

