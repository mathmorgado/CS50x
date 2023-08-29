#include <stdio.h>

int main(void)
{
    // get_int
    int x;
    printf("x: ");
    scanf("%i", &x);

    printf("x: %i\n", x);

    char s[4]; // Arrays can serve as pointers
    printf("\ns: ");
    scanf("%s", s);

    printf("s: %s\n", s);
}