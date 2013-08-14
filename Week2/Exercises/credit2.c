#include <stdio.h>
#include <cs50.h>


int count(int input);

int main(void)
{
    printf("Number:");
    long long number = GetLongLong();
    int numbersize = 0;
    
    count(numbersize);
    
    int digit[numbersize];
    
    for (int i = 1; i <= numbersize; i++) //naming digits
    {
        digit[numbersize - i] = (number - 10*(number/10));
        number = number/10;
    } 
    
    for (int i = 0; i < numbersize; i++) //naming digits
    {
        printf("Digit #%i is:%i\n", i, digit[i]);
        
    } 
    
    
    int sumeven = 0;    
    for (int i = 1; i < numbersize; i = i + 2)
    {
        digit[i] = digit[i]*2;
        digit[i] = count(digit[i]);
        sumeven = sumeven + digit[i];
        
    }
    
    sumeven = count(sumeven);
    printf("sumeven is %i \n", sumeven);
}


int count(int input)
{
    for (long x = input; x > 0; x = x/10) //counting digits
    {

        input++;
    }
    return input;
}
