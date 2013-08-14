#include <stdio.h>
#include <cs50.h>
#include <string.h>

char lowercase(char input);
char uppercase(char input);

int main(void)
{
    string s = GetString();
    int sequel = 2;
    for(int i=0, n = strlen(s); i < n ; i++)
        {
            if( (int) s[i] != 32)
                sequel++;
            
            if( sequel %2 == 0)
                s[i] = uppercase(s[i]);
            else
                s[i] = lowercase(s[i]); 
            
        }
        
        
        
        
    printf("%s\n", s);
    return 0;
}


char lowercase(char input)
{
    if( (int) input < 96 && (int) input != 32)
        input = (int) input + 32;
        
    return(input);
}

char uppercase(char input)
{
    if( (int) input > 96)
        input = (int) input - 32;
        
    return(input);
}
