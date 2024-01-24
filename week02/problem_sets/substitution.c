#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Value required for the user-input key
#define KEY_SIZE 26

bool check_key(string key);
string rotate(string key, string plaintext);

int main(int argc, string argv[])
{
    // Assure proper usage
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    bool valid = check_key(key);

    if (valid == true)
    {
        printf("true\n");
        string plaintext = get_string("plaintext: ");

        // Prints encrypted text
        printf("ciphertext: %s\n", rotate(argv[1], plaintext));
    }
    else
    {
        printf("Invalid key\n");
        return 1;
    }
}

// Switch each alphabetical character of the plaintext by its cipher counterpart
string rotate(string key, string plaintext)
{
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    string ciphertext = plaintext;

    int j = 0;
    // Iterate over each letter of the plaintext
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            while (tolower(plaintext[i]) != alphabet[j])
            {
                j++;
            }

            // Switch cases back to original input, if needed (since the predefinition is lowercase)
            plaintext[i] = isupper(plaintext[i]) ? toupper(key[j]) : tolower(key[j]);
        }
        j = 0;
    }

    return ciphertext;
}

bool check_key(string key)
{
    bool valid = true;

    // Assures key has 26 characters
    if (strlen(key) != KEY_SIZE)
    {
        valid = false;
    }

    // Iterates over each letter from the key
    for (int i = 0; i < KEY_SIZE; i++)
    {
        int j = i;

        // Assure key has no duplicate characters
        while (j < KEY_SIZE)
        {
            // Compares the current character with all the other characters in the key, except itself
            if (i != j && key[i] == key[j])
            {
                valid = false;
            }
            j++;
        }

        // Assure key has only alphabetical characters
        if (!isalpha(key[i]))
        {
            valid = false;
            break;
        }
    }
    return valid;
}




