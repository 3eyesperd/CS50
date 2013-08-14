#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Temperatura em Celsius:");
    float celsius = GetFloat();
    float fahrenheit = (5.0/9.0)*( celsius -32);
    printf("Temperatura em Fahrenheit? %.1f\n", fahrenheit);
    return 0;
}
    
