#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Enter lowercase letter:");
    char input = 1;
    do
    {
    input = GetChar();
    }
    while( (int)input < 97 || (int)input > 122);
    input = (int)input - 22;
    printf("ASCII: %i \n Char:%s \n ", (int)input, input);
    return 0;
}

