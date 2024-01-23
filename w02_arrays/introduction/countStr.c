#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // calculate size of a string

    string s = get_string("String: ");

    int n = 0;

    while (s[n] != '\0')
    {
        n++;
    }

    printf("The string typed has %i letters.\n", n);

}