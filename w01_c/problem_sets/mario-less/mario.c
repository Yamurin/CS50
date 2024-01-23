#include <cs50.h>
#include <stdio.h>

void makePyramid(int height);
int main(void)
{
    int h;

    // Prompts for pyramid height (h)
    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    makePyramid(h);
}

void makePyramid(int max)
{
    // Draws pyramid
    int i;

    for (i = max; i > 0; i--) // Repeats the sequence of spaces and # until the height is met
    {
        for (int k = max - i; k < max - 1; k++)
        {
            printf(" ");
        }

        for (int j = 0; j <= max - i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}