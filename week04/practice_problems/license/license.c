#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
What was wrong in the source code?
    All elements of plates[8] were pointing to the adress of buffer[7].
    Hence, all elements of plate[8] were being updated with the same value in buffer at every iteration.

How to fix it?
    Copy the current value of the buffer to the plates[idx] element.
    This way, the buffer may change, but its previous value will be already saved to the plates array.
    However, the source code did not assign an adress to char *plates[8].
    In order to copy the string from the buffer, first it's required to assign a "storage" of 7 bytes
    to each element that plates[8] points to.
    To do so, use malloc.
    Lastly, close the infile and free each plates[] element as to prevent memory leaks.
*/


int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        plates[idx] = malloc(7);
        strcpy(plates[idx], buffer);
        
        idx++;
    }

    fclose(infile);

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
        free(plates[i]);
    }
}
