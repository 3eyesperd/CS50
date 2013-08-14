#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    for(int i = 0; i < argc; i++)
        for(int j = 0; j < strlen(argv[i]); j++)
            printf("Arg %i #j letter is: %c\n", i, argv[i][j]);
} 
