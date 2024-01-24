#include <stdio.h>

void exe_1 (void);

int main (void)
{
    FILE *file_out = fopen("test.txt", "w");
    fputs("This is the content of the file test.txt.\n", file_out);
    printf("File test.txt has been created.\n");

    fclose(file_out);

    return 0;
}

