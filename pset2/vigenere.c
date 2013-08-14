#include <stdio.h>
#include <cs50.h>
#include <string.h>

char EncryptLowerCase(char input, int key);
char EncryptUpperCase(char input, int key);
bool IsUpper(char input);
bool IsLower(char input);


int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Return 1");
        return 1;
    }    
    int KeyLenght = strlen(argv[1]);
    int key[KeyLenght];
    for(int i = 0; i < KeyLenght; i++)
    {
        if(IsLower(argv[1][i]))
            key[i] = argv[1][i] - 'a';
        else if(IsUpper(argv[1][i]))
            key[i] = argv[1][i] - 'A';
        else
        {
            printf("The Key must only contain characters\n");
            return 1;
        }
    }
        
    string message = GetString();

        
    for(int i = 0, j = 0, n = strlen(message); i < n; i++)
    {
        
        if(IsLower(message[i]) == true)
        {
            message[i] = EncryptLowerCase(message[i],key[j]);
            j = (j + 1)%KeyLenght;
            
        }
        else if(IsUpper(message[i]) == true)
        {
            message[i] = EncryptUpperCase(message[i],key[j]);
            j = (j + 1)%KeyLenght;
               
        }
    }
    printf("%s\n", message);
    return 0;
    
}

char EncryptLowerCase(char input, int key)
{
    
    input = 'a' + (input -'a' + key)%26;
    return input;
}

char EncryptUpperCase(char input, int key)
{
    input = 'A' + (input -'A' + key)%26;
    return input;
}

bool IsLower(char input)
{
    return(input >= 97 && input <= 122);
}

bool IsUpper(char input)
{
    return(input >= 65 && input <= 90);
}

