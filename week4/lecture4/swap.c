#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("X is %i\nY is %i\n\n", x, y);

    swap(&x, &y); // With '&' operator, we passing the address of the values and not the values themselves!

    printf("X is %i\nY is %i\n", x, y);
}

/*
X is 1 / Y is 2
       |
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

X is 1 / Y is 2 (didn't swap)

    Why? Because of the scope issue, the function "swap(int a, int b)" would not be able to perform the swap,
  since the function is receiving the *value* of the parameter, not the reference. So, in the end, we're
  just copying the values that were passed as parameters and passing them to other variables in the function's
  scope and swapping them around!

    To fix this, instead of receiving the value of the variables as a parameter, we should receive the memory address
  where the values we want to swap are stored, i.e. the pointers to those values!
*/

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}