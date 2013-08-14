#include <stdio.h>
#include <cs50.h>


int main(void)
{
    printf("O hai! How much change is owed?");
    double change = GetDouble();
    int coin25 = 0;
    int coin10 = 0;
    int coin05 = 0;
    int coin01 = 0;
    
    

 
    while(change >= 0.25)
    {
        change = change - 0.25;
        coin25++;
    }
         
    while(change >= 0.10)
    {
        change = change - 0.10;
        coin10++;
    }
    
    while(change >= 0.050)
    {
        change = change - 0.05;
        coin05++;
    }
    
    while (change >= 0.01)
    {
        
        change=change-0.01;
        coin01++;
    }
    
    printf(" 25coin: %i\n 10coin: %i\n 5coin:%i\n 1coin:%i\n change:%f\n", coin25, coin10, coin05, coin01,change);
     
      
    return (0);
}
