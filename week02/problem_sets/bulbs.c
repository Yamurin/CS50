#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void ascii_to_binary(int ascii_number,  int bit[]);
void print_bulb(int bit[]);


int main(void)
{
    int binary[BITS_IN_BYTE] = {0};

    // Input user message
    string message = get_string("Message: ");

    // Display message as bulbs
    for (int i = 0; i < strlen(message); i++)
    {
        ascii_to_binary(message[i], binary);
        print_bulb(binary);
    }
}

// Converts integer to binary
void ascii_to_binary(int ascii_number, int bit[])
{
    int decimal[BITS_IN_BYTE] = {128, 64, 32, 16, 8, 4, 2, 1};
    int j = 0;

    while (ascii_number > 0)
    {
        for (int i = j; i < BITS_IN_BYTE; i++)
        {
            if (decimal[i] <= ascii_number)
            {
                j = i;
                ascii_number -= decimal[i];
                bit[i] = 1;
            }
            else
            {
                bit[i] = 0;
            }
        }
    }
}

// Display emojis for each digit
void print_bulb(int bit[])
{
    for (int i = 0; i < BITS_IN_BYTE; i++)
    {
        if (bit[i] == 0)
        {
            // Dark emoji
            printf("\U000026AB");
        }
        else
        {
            // Light emoji
            printf("\U0001F7E1");
        }
    }
    printf("\n");
}
