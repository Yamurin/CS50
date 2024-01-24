#include <stdio.h>
#include <cs50.h>

//int selectionSort(int n[]);

int main (void)
{
    int a[] = {5, 9, 7, 6, 4, 0, 2, 3, 8, 1};
    int lenght = 10;

    // Iterates over each index of the array, that is, from index[0] to index[8]
    // It doesnt iterate over the last one because, by default, a single digit is always sorted

    for (int i = 0; i < lenght - 1; i++)
    {
        // Find the index of the minimum number in the unsorted part
        // Assumes that the current index is the smaller, and then updates if it finds a smaller one
r        int min_pos = i;
        for (int j = i + 1; j < lenght; j++)
        {
            if (a[j] < a[min_pos])
                min_pos = j;
        }

        // SWaps the current number for the minimum one, if the current is already not the number itself
        if (min_pos != i)
        {
            int temp = a[i];
            a[i] = a[min_pos];
            a[min_pos] = temp;
        }
    }

    for (int i = 0; i < lenght; i++)
    printf("a[%i] = %i\n", i, a[i]);

    return 0;
}

// Search the unsorted part of the data to find the smallest value
// Swap the smallest found value with the first element of the unsorted part

// Initial array: 5, 9, 7, 6, 4, 0, 2, 3, 8, 1
//
//        Step 0: 0, 9, 7, 6, 4, 5, 2, 3, 8, 1      // Starting at index[0]
//        Step 1: 0, 1, 7, 6, 4, 5, 2, 3, 8, 7      // Starting at index[1]