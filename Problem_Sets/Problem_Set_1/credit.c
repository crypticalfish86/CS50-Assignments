#include <cs50.h> //allows me to use get_long which asks for user input and returns the cardNumber as a long (64 bit integer)
#include <stdio.h>

long returnCardNumber(void);
int checkCardLength(long cardNumber);
void checkValidity(int cardLength, long cardNumber);
int finalAlgorithmCheck(long cardArray[], int cardLength);

int main(void)
{
    long cardNumber = returnCardNumber();
    printf("Card number: %li\n", cardNumber);
    int cardLength = checkCardLength(cardNumber);
    printf("Card length: %d \n", cardLength);
    checkValidity(cardLength, cardNumber);
}

long returnCardNumber(void)
{
    return get_long("Input card number: \n");
}

int checkCardLength(long cardNumber)
{
    if(cardNumber / 1000000000000000 != 0 && cardNumber / 10000000000000000 == 0)
    {
        return 16;
    }else if(cardNumber / 100000000000000 != 0 && cardNumber / 1000000000000000 == 0)
    {
        return 15;
    }else if(cardNumber / 1000000000000 != 0 && cardNumber / 10000000000000 == 0)
    {
        return 13;
    }else
    {
        printf("Card length invalid, returning 0 (inside function) \n");
        return 0;
    }
}

void checkValidity(int cardLength, long cardNumber)
{
    if(!cardLength) //checks if cardLength returned 0
    {
        printf("INVALID\n");
    }else //rest of function
    {
        long cardArray[cardLength - 1];
        long startingNumberDivider = 1000000000000000; //to divide a long by 1 quadrillion leaving the first digit
        int j = 0;
        if(cardLength == 16) // if length is 16 startingNumberDivider remains as 1 quadrillion
        {
            for (long i =  startingNumberDivider; j < 16; i = i / 10)
            {
                cardArray[j] = (cardNumber / i) % 10;
                printf("Card Number %d : %li \n", j, cardArray[j]);
                j++;
            }
            int cardValidity = finalAlgorithmCheck(cardArray, cardLength);
            printf("%d\n", cardValidity);
            if(cardValidity)
            {
                if(cardArray[0] == 4)
                {
                    printf("VISA\n");
                }else if(cardArray[0] == 5)
                {
                    if(cardArray[1] == 1 || cardArray[1] == 2 || cardArray[1] == 3 || cardArray[1] == 4 || cardArray[1] == 5)
                    {
                    printf("MASTERCARD\n");
                    }else
                    {
                        printf("INVALID\n");
                    }
                }else
                {
                    printf("INVALID\n");
                }
            }else
            {
                printf("INVALID\n");
            }
        }else if(cardLength == 15)
        {
            startingNumberDivider = startingNumberDivider / 10; // same as above for loop except startingNumberDivider is divided by 10
            for (long i = startingNumberDivider; j < 15; i = i / 10)
            {
                cardArray[j] = (cardNumber / i) % 10;
                printf("Card Number %d : %li \n", j, cardArray[j]);
                j++;
            }
            int cardValidity = finalAlgorithmCheck(cardArray, cardLength);
            printf("%d\n", cardValidity);
            if(cardValidity)
            {
                if(cardArray[0] == 3)
                {
                    if(cardArray[1] == 4 || cardArray[1] == 7)
                    {
                        printf("AMEX\n");
                    }else
                    {
                        printf("INVALID\n");
                    }
                }else
                {
                    printf("INVALID\n");
                }
            }else
            {
                printf("INVALID\n");
            }
        }else if(cardLength == 13)
        {
            startingNumberDivider = startingNumberDivider / 1000; //same as above for loop except this time its divided by 1000 to get to 13 digits
            for (long i = startingNumberDivider; j < 13; i = i / 10)
            {
                cardArray[j] = (cardNumber / i) % 10;
                printf("Card Number %d : %li \n", j, cardArray[j]);
                j++;
            }
            int cardValidity = finalAlgorithmCheck(cardArray, cardLength);
            printf("%d\n", cardValidity);
            if(cardValidity)
            {
                if(cardArray[0] == 4)
                {
                    printf("VISA\n");
                }else
                {
                    printf("INVALID\n");
                }
            }else
            {
                printf("INVALID\n");
            }
        }else
        {
            printf("error, you somehow got here");
        }
    }
}

int finalAlgorithmCheck(long cardArray[], int cardLength)
{
    long totalMultiplied = 0;
    long totalRemaining = 0;

    if(cardLength == 16)
    {
        for (int i = 14; i >= 0; i -= 2) //14 is the second to last digit in an array of length 16 this is the first part of the algorithm discussed
        {
            if((cardArray[i] * 2) / 10 == 0)
            {
                totalMultiplied += (cardArray[i] * 2);
            }else //maximum possibility is 18 so always just + 1, + the remainder of modulo 10
            {
                totalMultiplied++;
                totalMultiplied += (cardArray[i] * 2) % 10;
            }
        }

        for (int i = 15; i >= 0; i -=2)
        {
            totalRemaining += cardArray[i];
        }
        printf("you got to final check 16\n");
    }else if(cardLength == 15)
    {
        for (int i = 13; i >= 0; i -= 2) //13 is the second to last digit in an array of length 15 this is the first part of the algorithm discussed
        {
            if((cardArray[i] * 2) / 10 == 0)
            {
                totalMultiplied += (cardArray[i] * 2);
            }else //maximum possibility is 18 so always just + 1, + the remainder of modulo 10
            {
                totalMultiplied++;
                totalMultiplied += (cardArray[i] * 2) % 10;
            }
        }

        for (int i = 14; i >= 0; i -=2)
        {
            totalRemaining += cardArray[i];
        }
        printf("you got to final check 15\n");
    }else //else if 13
    {
        for (int i = 11; i >= 0; i -= 2) //11 is the second to last digit in an array of length 13 this is the first part of the algorithm discussed
        {
            if((cardArray[i] * 2) / 10 == 0)
            {
                totalMultiplied += (cardArray[i] * 2);
            }else //maximum possibility is 18 so always just + 1, + the remainder of modulo 10
            {
                totalMultiplied++;
                totalMultiplied += (cardArray[i] * 2) % 10;
            }
        }

        for (int i = 12; i >= 0; i -=2)
        {
            totalRemaining += cardArray[i];
        }
        printf("you got to final check 13\n");
    }

    printf("Total multiplied: %li \n", totalMultiplied);
    printf("Total remaining: %li \n", totalRemaining);

    long totalSum = totalMultiplied + totalRemaining;

    if(totalSum % 10 == 0)
    {
        return 1;
    }else
    {
        return 0;
    }
}
