#include <stdio.h>
#include <cs50.h>
#include <string.h>

char CorrectLowerCase(char input);
char CorrectUpperCase(char input);

int main(int argc, string argv[])
{
    int k = atoi(argv[1])%26;    
    string message = GetString();

    for(int i = 0, n = strlen(message); i < n; i++)
    {
        if(message[i] >= 97 && message[i] <= 122)
        {
            message[i] = message[i] + k;
            message[i] = CorrectLowerCase(message[i]);
        }
        else if(message[i] >= 65 && message[i] <= 90)
        {
           message[i] = message[i] + k;
           message[i] = CorrectUpperCase(message[i]);       
    }

    printf("Message is:%s\n", message);
}

char CorrectLowerCase(char input)
{
    if(input < 97)
        input = input + 26;
    else if(input > 122)
        input = input - 26;
    return input
}

char CorrectUpperCase(char input)
{
    if(input < 65)
        input = input + 26;
    else if(input > 90)
        input = input - 26;
    return input
}
