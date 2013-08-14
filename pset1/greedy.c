#include <stdio.h>
#include <cs50.h>


int main(void)
{
    double change;
    do
    {
        printf("O hai! How much change is owed?");
        change = GetDouble();
    } while(change <=0);
    
    int coin = 0;
    int cents = 100*change;
    coin = coin + cents/25;
    cents = cents%25;
    coin = coin + cents/10;
    cents = cents%10;
    coin = coin + cents/5;
    cents = cents%5;
    coin = coin + cents;
   
    printf("%i\n", coin);
     
      
    return (0);
}
