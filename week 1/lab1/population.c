#include <cs50.h>
#include <stdio.h>

int start_size();
int end_size();
int calc_population();

int main(void)
{
    // TODO: Prompt for start size
    int start = start_size();

    // TODO: Prompt for end size
    int end = end_size(start);

    // TODO: Calculate number of years until we reach threshold
    int years = calc_population(start, end);

    // TODO: Print number of years
    printf("Years: %d\n", years);
}

int start_size(void)
{
    int size;
    do
    {
        size = get_int("Start size: ");
    }
    while (size < 9);
    return size;
}

int end_size(int start)
{
    int size;
    do
    {
        size = get_int("End size: ");
    }
    while (size < start);
    return size;
}

int calc_population(int start, int end)
{
    int years = 0;
    if (start != end)
        do
        {
            int new = start / 3;
            int less = start / 4;
            start += new - less;
            years++;
        }
        while (start < end);
    return years;
}
