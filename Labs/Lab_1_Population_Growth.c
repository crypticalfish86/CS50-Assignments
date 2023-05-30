#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 0;
    // TODO: Prompt for start size (check to make sure user start population is at least 9 and if not keep prompting the user)
    while(n < 9)
    {
        n = get_int("input start population: ");
    }
    // TODO: Prompt for end size (check to make sure the user end population is at least as large as the user start population)
    int endPop = 0;
    while(endPop < n)
    {
        endPop = get_int("input end population: ");
    }
    // TODO: Calculate number of years until we reach threshold
    int y = 0;

    for(y = 0; n < endPop; y++)
    {
        n = n + (n / 3) - (n / 4);
    }
    // TODO: Print number of years
    printf("number of years: %i\n", y);
}

//make sure in all of this to use integers because we cant have 0.4 of a llama, so truncate
//the formula would be something like n = n + (n / 3) - (n / 4);
//y = number of years
//n = current population
//endPop = end population