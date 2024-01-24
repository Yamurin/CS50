#include <stdio.h>

int main(void)
{
    int a[] = {7, 1, 3, 9, 0, 2, 4, 5, 8, 6};

    int lenght = 10;

    // Iterates as many passes as the number of elements in the array
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < (lenght - 1 - i); j++)
        {
            // Swaps the number at arr[j] and the subsequent element if out of order
            if (a[j] > a [j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < lenght; i++)
    {
        printf("[%i]: %i\n", i, a[i]);
    }

    return 0;
}

// Checks two numbers at a time, and swaps then in not in correct order
// The algorithm makes as many"checks" (passes) in the array as there elements
// So if we have an array of 5 numbers, its gonna check 5 times

// This algorithm can be further optmized with booleans, in case the sequence gets in the right order
// without necessarily going trough the required quantity of passes