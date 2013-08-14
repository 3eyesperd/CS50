#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool IsLower(char input);
bool IsUpper(char input);


int main(int argc, string argv[])
{
    if(argc != 2)
        return 1;
        
    
    int key[KeyLenght];
    for(int i = 0; i < KeyLenght; i++)
    {
        if(IsLower(argv[1][i]))
            key[i] = argv[1][i] - 'a';
        else if(IsUpper(argv[1][i]))
            key[i] = argv[1][i] - 'A';
        else
        {
            printf("The Key must only contain characters");
            return 1;
        }
    }

    for(int i = 0; i < KeyLenght; i++)
    printf("Your #%i digit key is: %i\n", i, key[i]);
    
}

bool IsLower(char input)
{
    return(input >= 97 && input <= 122);
}

bool IsUpper(char input)
{
    return(input >= 65 && input <= 90);
}

