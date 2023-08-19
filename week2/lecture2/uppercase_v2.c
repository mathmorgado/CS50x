#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    string s = get_string("BEFORE: ");
    printf("AFTER: ");

    // uppercase_v2 it's better design
    for (int i = 0, l = strlen(s); i < l; i++) // call function strlen() just one time
    {
       printf("%c", toupper(s[i])); // convert lowercase to uppercase without deleting what was already uppercase
    }
    printf("\n");
}