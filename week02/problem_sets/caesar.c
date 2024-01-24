#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET 26
#define MAX_ARGC 2

bool only_digits(string key);
string cipher(string plaintext, int key);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    bool valid;
    string plaintext;
    int key;

// Checks if the user inputed the correct number of arguments and if the key is valid
    if (argc == MAX_ARGC)
    {
        valid = only_digits(argv[1]);
    }
    else
    {
        printf("ERROR: Invalid number of arguments\n");
        return 1;
    }

// If there is a valid key, convert the plaintext to ciphertext
    if (valid == true)
    {
        key = atoi(argv[1]);
        plaintext = get_string("plaintext: ");

// Convert and then print each char
        printf("ciphertext: ");
        for (int i = 0; i < strlen(plaintext); i++)
        {
            printf("%c", rotate(plaintext[i], key));
        }
        printf("\n");
    }
    else
    {
        return 1;
    }
}

// Returns an error if any digit of the key is not a number
bool only_digits(string key)
{
    bool b = true;

    for (int i = 0; i < strlen(key); i++)
    {
        if (!(isdigit(key[i])))
        {
            printf("Usage: ./caesar key\n");
            return 0;
            b = false;
        }
    }
    return b;
}

// Convert each alphabetical digit to cipher
char rotate(char c, int key)
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int i = 0;
    char c_1 = tolower(c);

    if (isalpha(c))
    {
        while (c_1 != alphabet[i])
        {
            i++;
        }
        i = (i + key) % ALPHABET;

// Switch final output to original case
        c_1 = isupper(c) ? toupper(alphabet[i]) : alphabet[i];
    }
    else
    {
        c_1 = c;
    }

    return c_1;
}