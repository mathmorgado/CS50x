#include <cs50.h>
#include <stdio.h>

const int N = 3;
int scores[N];

float average(int lenght, int array[]);

int main(void)
{
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", average(N, scores));
}

float average(int lenght, int array[])
{
    int result = 0;
    for (int i = 0; i < lenght; i++)
    {
        result += array[i];
    }
    return result / (float) lenght;
}