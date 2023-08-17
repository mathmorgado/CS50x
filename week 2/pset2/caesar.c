#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string encrypt(int key, string text);
bool valid_key(string argv);

int main(int argc, string argv[])
{
    if (argc == 2 && valid_key(argv[1]))
    {
        int key = atoi(argv[1]);
        printf("%i\n\n", key);
        string text = get_string("plaintext: ");

        string encrypted_text = encrypt(key, text);

        printf("ciphertext: %s\n", encrypted_text);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool valid_key(string argv)
{
    for (int i = 0, len = strlen(argv); i < len; i++)
    {
        if (isdigit(argv[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

string encrypt(int key, string text)
{
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        int rotate = key;
        if (isalpha(text[i]))
        {
            if (islower(text[i]) && text[i] + key > 122)
            {
                while (text[i] + rotate > 122)
                {
                    rotate -= (122 - text[i]);
                    text[i] = 96;
                }
                text[i] += rotate;
            }
            else if (isupper(text[i]) && text[i] + key > 90)
            {
                while (text[i] + rotate > 90)
                {
                    rotate -= (90 - text[i]);
                    text[i] = 64;
                }
                text[i] += rotate;
            }
            else
            {
                text[i] += key;
            }
        }
    }
    return text;
}