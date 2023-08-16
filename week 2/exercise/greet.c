#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // The values is the arguments in the CLI
{
    if (argc == 2) //argc is a counter of argumentes in CLI
    {
        printf("hello, %s!\n", argv[1]); // argv[0] problably is "./greet"
    }
    else 
    {
        printf("hello, world!\n");
    }
}