#include <cs50.h>
#include <stdio.h>
#include <string.h>

 typedef struct      // Create a custom type
{
    string name;
    string number;
}
person;     // Assign name to custom type

int main(void)
{
    person people[2];

    people[0].name = "Jay";
    people[0].number = "34 12354-5678";

    people[1].name = "Max";
    people[1].number = "34 9876-5432";

    string name = get_string("Name: ");
    // Compares each character from the name[i] to the user input
    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}