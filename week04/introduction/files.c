#include <stdlib.h>
#include <stdio.h>

int main (void)
{
   FILE *fh_output;

    fh_output = fopen("test.txt", "w");
    printf("\nA new blank file called test.txt will now be stored in fh_output.\n");

    fputs("A string\nHello!\n", fh_output);
    printf("\nA new line was added to the file.\n");

    printf("fprintf can inpu custom content on to the file. Try it out. Content: ");
    char str[50] = "mygod";

    fprintf(fh_output, "data: %s\n", str);

    fclose(fh_output);
}

/*
FILE *input = fopen("text.txt", "r");

    // Reads one block of bytes each time
    // Reads 3 blocks of bytes in total
    // Puts those read blocks in 'buffer'
    fread(buffer, 1, 3, input);
    */
