// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool uppercase, lowercase, number, symbol, valid = false;

// Checks each required character
    for (int i = 0; i < strlen(password); i++)
    {
        char j = password[i];

        if (isupper(j))
        {
            uppercase = true;
        }
        if (islower(j))
        {
            lowercase = true;
        }
        if (isdigit(j))
        {
            number = true;
        }
        if ((j >= 33 && j <= 47) ||
            (j >= 58 && j <= 64) ||
            (j >= 91 && j <= 96) ||
            (j >= 123 && j <= 126))
        {
            symbol = true;
        }
    }

// Checks if all character conditions were met
    if (uppercase == true &&
        lowercase == true &&
        number == true &&
        symbol == true)
    {
        valid = true;
    }

    return valid;
}
