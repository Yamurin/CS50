#include <stdio.h>
#include <cs50.h>

// As N goes into an array, it has to be an integer. So, it's best not to use #define
const int N = 3;

float average(int lenght, int array[]);

int main(void)
{
    int scores [N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(N, scores));
}

// For better seign, the function average() has to be indepent from the constant variable
// So, N was assigned to it's own variable within average(), which is lenght
float average(int lenght, int array[])
{
    int sumScores = 0;

    for (int i = 0; i < lenght; i++)
    {
        sumScores += array[i];
    }

    return sumScores / (float) lenght;
}