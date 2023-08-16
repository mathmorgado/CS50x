#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-lines-arguments\n");
        return 212; // Error code like 404 (not found) -> "echo $?" to see
    }
    else
    {
        printf("Hello, %s\n", argv[1]);
        return 0; // Success code
    }
}