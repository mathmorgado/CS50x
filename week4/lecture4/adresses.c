#include <stdio.h>

/*
                                              POINTER

   Pointers are variables that contain an address of something in memory. Working with pointers
  requires two new operators:
     & - an operator that refers to the memory space of a variable (it gets the 'address' of that memory)
     * - an operator that accesses a certain memory space (goes to the 'address' of that memory)
     %p - allows us to print a pointer

   To declared a pointer we use this structure (type of the value in that memory space) *(varible) = &(varible).
      Ex: int *p = &n;

  In this example, 'p' stores the 'address' of the memory space in which the variable 'n' is stored.
   If we want to print 'p', we should use "%p", which is assigned to a pointer, and what we will see is the address.
      Ex: printf("%p\n", p); -> 0x123 (exemple adress)

  Now, if we want to access the value inside memory, we need to use "%(type of value)" and "*p" again.
      Ex: printf("%i\n", *p); -> 50 (exemple value)

*/

int main(void)
{
    int n = 50; // The value is assigned to 'n' and stored somewhere in memory

    int *p = &n; // pointer -> a variable that contains an address of something in memory

    printf("%p\n", p);
}