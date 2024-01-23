#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int startPop, endPop, currentPop, y;

    // Prompt for start size
    do
    {
    startPop = get_int("Start size: ");
    }
    while (startPop < 9);

    currentPop = startPop;

    // Prompt for end size
    do
    {
        endPop = get_int("End size: ");
    }
    while (endPop < startPop);

    /*
    after 1 year, the currentPop = startPop - losses + born
    after 2 years, the currentPop = currentPop - losses + borns
    after 3 years, the currentPop = currentPop - losses + borns
    the cycle will go on until the currentPop reaches the endPop prompted by the user, that is, until currentPop no longer < endPop
    */

    // Calculates the amount of years passed
    for (y = 0; currentPop < endPop; y++)
    {
        if (y >= 1)
        {
            currentPop = currentPop - (currentPop / 4) + (currentPop / 3);
        }
        else
        {
            currentPop = startPop - (startPop / 4) + (startPop / 3);
        }
    }

    printf("Years: %i\n", y);
    // printf("Current llama population: %i\n", currentPop); // checks if the loop REALLY stops at the right point (the endPop)
}

