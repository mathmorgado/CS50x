#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;
int bits[8];

void print_bulb(int bit);
void bulbs(string word);

int main(void)
{
    // TODO
    string word = get_string("Message: ");
    bulbs(word);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void bulbs(string word)
{
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        int char_byte = word[i];
        int bit = 128;
        int count = 0;

        for (int j = 0; j < 8; j++)
        {
            if (bit > char_byte)
            {
                print_bulb(0);
            }
            else
            {

                if (char_byte % 2 == 0)
                {
                    bits[count] = 0;
                }
                else
                {
                    bits[count] = 1;
                }
                char_byte /= 2;
                count++;
            }
            bit /= 2;
        }

        for (int c = count; c > 0; c--)
        {
            print_bulb(bits[c - 1]);
        }
        printf("\n");
    }
}