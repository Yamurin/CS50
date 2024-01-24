#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define ALPHABET 26
int main (void)
{
    int POINTS[] = {1, 2, 3, 4};
    char LETTERS[] = {'a', 'b', 'c', 'd'};
    int score = 0;

    string s = get_string("Word: ");

    for (int n = 0; n < strlen(s); n++)
    {
        for (int i = 0; i < ALPHABET; i++)
        {
            if (LETTERS[i] == s[n])
            {
                score += POINTS[i];
            }
            else
            {
                score += 0;
            }
        }
    }

    printf("score: %i\n", score);
}