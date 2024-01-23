#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c;

    do
    {
        c = get_char("type y.\n");
        printf("%c\n", c);
    }
    while (c != 'y');


}