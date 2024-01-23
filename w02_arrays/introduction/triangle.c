#include <stdio.h>
#include <cs50.h>

bool valid_triangle(float sides[]);
#define ARRAYSIZE 3

int main (void)
{
    bool b;
    float sides[ARRAYSIZE];

    for (int i = 0; i < ARRAYSIZE; i++)
    {
        while (sides[i] <= 0)
        {
            sides[i] = get_float("Side %i: ", i + 1);
        }
    }

    b = valid_triangle(sides);
    if(b == true)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}

bool valid_triangle(float sides[])
{
    if (sides[0] + sides[1] > sides[2])
    {
        return true;
    }
    else
    {
        return false;
    }
}
