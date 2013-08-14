#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    printf("Put a line of text:");
    string s = GetString();
    printf("Say a position:");
    int number = GetInt();
    char c = s[number-1];
    printf("The # %i position is %c\n", number, c);
    return 0;
}
    
