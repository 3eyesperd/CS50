#include <stdio.h>

void divide(int a, int b)
{
    if (b == 0)
    {
        if (a == 0)
        {
            printf("Undefined\n");
        }
        else
        {
            printf("Infinity\n");
        }
    }
    else
    {
        printf("%d\n", a / b);
    }
}

int main(void)
{
    divide(13, 4);
    divide(0, 0);
    divide(1, 0);
}
