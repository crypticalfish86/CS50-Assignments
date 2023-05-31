//https://cs50.harvard.edu/x/2023/psets/1/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    while (n < 1 || n > 8)
    {
        n = get_int("insert integer: \n");
    }

    int x = (n - 1); // initial number of spaces for row

    //for loop per line (starting with the top line)
    for(int i = 0; i < n; i++)
    {

        //for loop for row spaces
        for(int j = x; j > 0; j--)
        {
            printf(" ");
        }
        x --; //subtract from x after completion of spaces for next loop


        //for loop for current line first blocks
        for(int j = (i + 1); j > 0; j--)
        {
            printf("#");
        }

        //print trench
        printf("  ");

        //for loop for current line of second blocks
        for(int j = (i + 1); j > 0; j--)
        {
            printf("#");
        }


        //finally new line
        printf("\n");
    }


}




