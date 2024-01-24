#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Constant variables for grade number and ASCII codes
#define MAX_GRADE 16
#define MIN_GRADE 1

#define a 97
#define z 122

#define A 65
#define Z 90

#define QUEST_MARK 63
#define EXCLMT_POINT 33
#define DOT 46
#define SPACE 32

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    int letters, words, sentc = 0;

    // Prompt for text
    string text = get_string("Text: ");

    letters = count_letters(text);
    words = count_words(text);
    sentc = count_sentences(text);

    // Calculate index
    float L = ((float) letters / words) * 100;
    float S = ((float) sentc / words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Output grade
    if (index >= MAX_GRADE)
    {
        printf("Grade %i+\n", MAX_GRADE);
    }
    else if (index < MIN_GRADE)
    {
        printf("Before Grade %i\yn", MIN_GRADE);
    }
    else
    {
        printf("Grade %.0f\n", round(index));
    }
}

// Count chars within the scope of lower and upper case ASCII codes
int count_letters(string text)
{
    int l = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= A && text[i] <= Z) || (text[i] >= a && text[i] <= z))
        {
            l++;
        }
    }

    return l;
}

// Count words
int count_words(string text)
{
    int w = 0;

    // Check the amount of spaces and add one
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == SPACE)
        {
            w++;
        }
    }

    return w + 1;
}

// Count sentences
int count_sentences(string text)
{
    int s = 0;

    // Check the amount of . ! or ? characters
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == DOT || text[i] == EXCLMT_POINT || text[i] == QUEST_MARK)
        {
            s++;
        }
    }

    return s;
}