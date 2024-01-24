#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main ()
{
    int a = 25;
    int b = 13;
    int *c = &a;

    *c = 14;
    c = &b;
    *c = 26;

}