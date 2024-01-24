#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "hel";
    s[0][2] = 'a';
    printf("%s\n", s);
}