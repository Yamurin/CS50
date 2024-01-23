#include <cs50.h>
#include <stdio.h>
#include <math.h>

void idCard(long cardNumber);
long prodSum(int d1);
int main(void)
{
    long x = get_long("Number: ");
    int digQuantity = 16;
    long productSum, totalSum = 0;

    long number = x;

    if (x < 1e12 || x > 1e17)
    {
        printf("INVALID\n");
        return 0;
    }

    // Gets each digit individually
    for(int i = 0; i < digQuantity; i++)
    {
        // d1 is the new value which will be multiplied by 2
        int d1 = 0;
        // d is the individual digit from x
        int d = x % 10;
        x = x / 10;

        // Multiplies each other digit by 2
        if (i % 2 > 0)
        {
            d1 = d * 2;
            productSum = prodSum(d1);
        }
        else
        {
            totalSum = totalSum + d;
        }
    }

    totalSum = totalSum + productSum;

    // Checks if totalSum ends is 0, that is, if the number is legit

    if (totalSum % 10 == 0)
    {
        idCard(number);
    }
    else
    {
        printf("INVALID\n");
    }
}


// Adds the products' digits
long prodSum(int d1)
{
    long productSum;

    while (d1)
    {
        int d2 = d1 % 10;
        productSum = productSum + d2;
        d1 = d1 / 10;
    }

    return(productSum);
}

// Identifies card flag
void idCard(long cardNumber)
{
    float e = -14;
    int firstDig = cardNumber * pow(10, e);

    // Checks if the card has 13 digits
    if (firstDig == 0)
    {
        e = -12;
        firstDig = cardNumber * pow(10, e);

        if (firstDig == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // Checks if the card has 16 digits
    else if (firstDig > 10)
    {
        if (firstDig >= 51 && firstDig <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (firstDig >= 40 && firstDig <=49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }

    else if (firstDig < 10)
    {
        e = -13;
        firstDig = cardNumber * pow(10, e);

        if (firstDig == 34 || firstDig == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
