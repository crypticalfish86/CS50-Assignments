#include <stdio.h>
//implicit declarations
void question(void);
void verticalBlocks(void);
void blockGrid(void);
//main
int main(void)
{
    question();
    verticalBlocks();
    blockGrid();
    long x = 400; 
    //longer integer variable using double the amount of memory of an integer good to prevent integer overflow
    printf("%li", x); //li is used to printf longs (longs are stored in 64 bits)
}
//function content (hoisted by implicit declarations)
void question(void)
{
    for(int i = 0; i < 4; i++)
    {
        printf("?");
    }
    printf("\n");
}

void verticalBlocks(void)
{
    for(int i = 0; i < 3; i++)
    {
        printf("#\n");
    }
}

void blockGrid(void)
{
    const int n = 5;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}



