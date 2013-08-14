#include <stdio.h>
#include <cs50.h>


int count(long long input); //counting # of digits
int namingdigits(int input); //naming digits
int validation(long long input); //check if credicard # is valid



int main(void)
{
    printf("Number:");
    long long number = GetLongLong();
    int sum = validation(number);
    int checkdigits = count(number);
    
    
    if ( (sum == 0) & (checkdigits = 15 & (number/10000000000000 == (34 | 37))))
    {
        printf("AMEX\n");
    }
    
    else if ( (sum == 0) & (checkdigits = 16 & (number/10000000000000000 == (51 | 52 | 53 | 54 |55))))
    {
        printf("MASTERCARD\n");
    }
    
    else if ( (sum == 0) & (checkdigits = (13 | 16) & ((number/10000000000000 | number/10000000000000000) == 4)))
    {
        printf("VISA\n");
    }
    
    else
    {
    printf("INVALID\n");
    }
}


int count(long long input)  
{
    int digits = 0;
    for (long long x = input; x > 0; x = x/10)
    {

        digits++;
    }
    return digits;
}

    

int validation(long long input)
{
    int numbersize = count(input);
    int digit[numbersize];
    
    
    for (int i = 1; i <= numbersize; i++) 
    {
        digit[numbersize - i] = (input - 10*(input/10));
        input = input/10;
    } 
    
      for (int i = 0; i < numbersize; i++) 
    {
        printf("Digit #%i is:%i\n", i, digit[i]);
        
    } 
    
    int sum = 0;    

    for (int i = 1; i < numbersize; i = i + 2)
    {
        digit[i] = digit[i]*2;
        if (digit[i] > 9)
            digit[i]=digit[i]++;
        sum = sum + digit[i];
        
    }
    
    for (int i = 0; i < numbersize; i = i + 2)
    {
        
        sum = sum + digit[i];
    }
   
    if (sum - 10*(sum/10) == 0)
    {
        return 0;
    }
    else
    { 
        return 1;
    }
    
}
    

