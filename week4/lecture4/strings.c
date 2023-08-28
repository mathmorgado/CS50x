#include <stdio.h>

/*
                                              STRINGS

     C doesn't know what strings are, because that concept doesn't exist in C. So how have we used
   strings so far? Well, the cs50 library created the string structure using a concept that already
   exists in C: Pointers.

     A string is nothing more than a pointer to the first character in a sequence of characters where,
   from there, using "%s" we continue in memory until we reach the memory space that represents \0 (NUL) and
   end the sequence!
       Ex: int *s = "HI!"; -> in the memory is [H][I][!][\0]
                |                               0  1  2   3
                |  0x123
                 -> [H]     (s)
       prinf("%s\n", s ); -> 0 -> 1 -> 2 -> 3  (stop)
                            [H]  [I]  [!]  [\0]

     Now that we have a better understanding of the pointer concept and that strings are a pointer to the first character,
   we can expand a  little further and try to figure out what s[0] or s[1] really are!

     Using the previous example, we know that 's' is a pointer to the memory space where the first character is stored,
   which in this case is (0x123) and (H) respectively. So we can deduce that the next character is in the next
   memory space (0x124) -> (I) and so on!

     Therefore, we can conclude that the syntaxes:
         s[0] -> *s
         s[1] -> *(s+1)
         s[2] -> *(s+2)
     In other words, syntactic sugar!
*/

int main(void)
{
    char *s = "HI!";

    printf("%s\n", s);
}