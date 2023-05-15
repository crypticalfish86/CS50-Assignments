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




REPRESENTATION

At the end of the day a computer simply has a ton of microscopic transistors and switches, so how would a computer represent values other than 0 and 1 (e.g the letter "A")

if the 0's and ones described above are used to represent numbers how would you go about representing letters of the alphabet?

if the letter A is represented just by 0, then how would the actual number 0 be represented? the computer would not recognise the difference at the end of the day.

the alphabet therefore can be represented using ASCII, where each computer has a built in reference for when ASCII is being used and represents that value with a number (with capital A being the number 65).

Every Character in ASCII is represented by 8 bits (1 byte) A in decimal is 65 but in binary it looks like 01000001. A second part of the computer interprets this 65 to the ASCII character A.

paradoxically the character (string number "1") number one can be stored in ASCII as the number 49
(11001) so when we write 1 as a string and not as a number/integer it has the actual value in bits of 49.

The patterns of numbers of 0s and 1s they will be automatically interpreted as character strings converted into ASCII



In things like visual graphics, the colours are NOT represented in ASCII but instead are reperesented by something called a HEXIDECIMAL CODE

ASCII as its made up of 1 byte can represent only up to 256 variations of characters, as there are more than 256 variations of colours or if you want more than 256 characters represented (e.g. non latin alphabet characters or emojis) you would instead use something called UNICODE which is the representation of up to 24-32 bits (roughly 3-4 bytes) which is more than enough to represent 4 billion characters, more than enough space for every possible iteration of character. these 4 billion possible iterations give us extra space to let us represent emojis.

Every pixel on a computer screen is represented through an interpreter of bits called RGB where there is 1 byte for red, 1 byte for green and 1 byte for blue. there are 256 iterations of each colour and so each code has a very specific variation of red green and blue to represent different potential colours like orange, purple, yellow etc. e.g. if the bytes which represent the numbers 72, 73, 33 were interpreted by a computer as RGB then it would instead look like a murky yellow. This is how pixels are represented under the hood on a screen (this is why images take up so much memory because each individual pixel has a code to them and videos are even larger in size for the same reasons + iterations and changes to pixels that change over time)

There are similar interpreters for all sorts of things (like Hz interpreted as bits for music, game engine graphics, 3d graphs etc. etc.)



ABSTRACTION AND ALGORITHMS

An algorithm in the most simple terms is the step by step process used to turn an input into a specific output, an abstraction is a referral to the algorithm in general used to turn an input into an output without going into details about how the process is working.

The beggining of planning out an algorithm tends to be done by writing "pseudocode" essentially instructions in plain english used to break down the steps of a problem making it easier to understand the step by step process the developer would have to take.

ALGORITHM EXAMPLE (SEARCH THROUGH DATABASE)

Hypothetically a search algorithm through a large database doesn't neccessarily have to sort through all of the database until it matches but instead can begin in the middle of the database, determine from data in the middle where the answer would be sorted, then go to the middle of that half of the database, figure out which side of the database it is on that side and continue that process continuously until it reaches the correct data, this is much faster computationally than simply trying to search the entire database.

pseudocode for this problem:

1. Pick up phone book
2. Open to middle of phone book
3. Look at page
4. If person is on page
    5. Call person
6. Else if person is ealier in book
    7. Open to middle of left half of book
    8. go back to step 3
9. Else if Person is later in book
    10. Open to middle of right half of book
    11. go back to step 3
12. Else
    13. Quit

All of the verbs in this scenario (like pick up, open, look at, call, go back) should be your functions. All the ifs and else's should be our conditionals that rely on boolean expressions.

