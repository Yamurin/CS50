#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int main(void)
{
    int n = get_int("Number: ");
    printf("%i\n", collatz(n));
}

int collatz(int n)
{
    // base recursion
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz(n / 2);
        printf("%i --> ", n);
    else
        return 1 + collatz(3 * n + 1);
        printf("%i --> ", n);
    return 0;
}
