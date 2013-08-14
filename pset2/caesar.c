#include <stdio.h>
#include <cs50.h>
#include <string.h>

char EncryptLowerCase(char input, int key);
char EncryptUpperCase(char input, int key);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Return 1\n");
        return 1;
    }
    int key = atoi(argv[1])%26;    
    string message = GetString();
    
    for(int i = 0, n = strlen(message); i < n; i++)
    {
        if(message[i] >= 97 && message[i] <= 122)
        {
            message[i] = EncryptLowerCase(message[i],key);
        }
        else if(message[i] >= 65 && message[i] <= 90)
        {
            message[i] = EncryptUpperCase(message[i],key);   
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
