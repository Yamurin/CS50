#include <cs50.h>
#include <stdio.h>


int main (int argc, string argv[])
{
        string cars[3][3] = {{"Camaro" , "Corvette", "Silverado"},
                             {"Mustang", "Ranger"  , "Ferrari"  },
                             {"Uno"    , "Lambo"   , "Tesla"    }};
                             
        // Print each row
        for (int i = 0; i < 3; i++)
        {
            printf("\n");
            for (int j = 0; j < 3; j++)
            {
                printf("%s  ", cars[i][j]);
            }
        }
        printf("\n");

}
