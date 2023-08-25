#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

float letters = 0;
float words = 1;
float sentences = 0;
double L;
double S;

int main(void)
{
    // get_text
    string text = get_string("Text: ");

    // count how many letters have in the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        else if (text[i] == 32)
        {
            words++;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    L = letters / words * 100;
    S = sentences / words * 100;

    // calculet level
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    printf("L: %f\nS: %f\nIndex: %f -> grade: %i\n", L, S, index, grade);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}