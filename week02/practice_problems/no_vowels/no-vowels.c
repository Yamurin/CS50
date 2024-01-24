#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

// Check for a single command line argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Invalid argument(s)\n");
        return 1;
    }
    else
    {
        printf("%s\n", replace(argv[1]));
        return 0;
    }
}

// Convert each vowel to a number while ignoring consonants
string replace(string input)
{
    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
            case 'a':
            case 'A':
                input[i] = '6';
                break;

            case 'e':
            case 'E':
                input[i] = '3';
                break;

            case 'i':
            case 'I':
                input[i] = '1';
                break;

            case 'o':
            case 'O':
                input[i] = '0';
                break;

            default:
                input[i] = input[i];
                break;
        }
    }
    return input;
}
