#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("Number:");
    long number = GetLongLong();
    int i;
    for(i = 0; i == 10; i++)
    {
        number = number/10;
        printf("%ld\n", number);

    }

}
