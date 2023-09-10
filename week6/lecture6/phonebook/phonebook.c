#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct person
{
    char *name;
    char *number;
}
person;

int main(void)
{
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";

    people[1].name = "David";
    people[1].number = "+1-949-468-2750";

    char *name = get_string("Name: ");
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(name, people[i].name)== 0)
        {
            printf("Number: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found!\n");
    return 1;
}