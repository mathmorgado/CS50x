#include <cs50.h>
#include <stdio.h>

bool valid_triangle(float x, float y, float z);

int main(void)
{
    x = get_float("x: ");
    y = get_float("y: ");
    z = get_float("z: ");

    if (valid_triangle(x, y, z))
    {
        printf("Valid trangle!\n")
    }
    else
    {
        printf("Invalid trangle!\n")
    }
}

bool valid_triangle(float x, float y, float z)
{
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
    else if ((x + y <= z) || (x + z <= y) || (z + y <= x))
    {
        return false;
    }
    return true;
}