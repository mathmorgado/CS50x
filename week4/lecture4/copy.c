#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
    A função "malloc( )" devolve o primeiro byte da memória com o espaço requisitado.
  Ex: char *t = malloc(4); -> return 0x438
                    |  search and get  ^
                    |    the space     |
                     - - - - - - >  [0x438][0x439][0x43a][0x43b]

    In turn, the "free( )" function frees all the memory space that malloc returned to you!
  Ex: free(t) -> [0x438][0x439][0x43a][0x43b]     < - - - -
        |         empty  empty  empty  empty                |
        |                                                   |
        |                                        H      i   |  !     \0
         - - - - - - - - - - - - - - - -  >   [0x438][0x439][0x43a][0x43b]


    The function "get_string( )" returs NULL when the string is longer than the space in memory.
  So, to avoid problems, if get_string( ) returns NULL, end the main( ) function using "return 'x'; ".

Finally, return 0 at the end of your code to indicate that the program was successful.
*/

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    //      t<-to
    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("\ns: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    return 0;
}