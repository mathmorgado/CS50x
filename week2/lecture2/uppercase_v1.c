#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("BEFORE: ");
    printf("AFTER: ");

    // uppercase_v1 show how the things work under the hood, but it's not well design
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] -32); // (('a' == 97) - 32) == (65 == 'A')
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    printf("\n");
}