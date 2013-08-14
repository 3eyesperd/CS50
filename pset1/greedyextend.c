#include <stdio.h>
#include <cs50.h>


int main(void)
{
    printf("O hai! How much change is owed?");
    float change = GetFloat();
    int coin=0
     
    while(change >= 0.25)
    {
        change = change - 0.25;
        coin++;
    }
         
    while(change >= 0.10)
    {
        change = change - 0.10;
        coin++;
    }
    
    while(change >= 0.05)
    {
        change = change - 0.05;
        coin++;
    }
    
    while (change >= 0.009)
    {
        
        change=change-0.01;
        coin++;
    }
    
    printf("%f\n", coin);
     
      
    return (0);
}
