#include <stdio.h>
#include <cs50.h>

string paragraph(int number);

int main(void)
{
    int n;
    do 
    {
        n = GetInt();
    }
    while(n > 10 || n == 0);

    string number[10] = {" one"," two"," three"," four"," five"," six"," seven"," eight"," nine"," ten"};
    string thing[10] = {" on my thumb"," on my shoe"," on my knee"," on my door"," on my hive"," on my sticks"," up in heaven"," on my gate"," on my spine"," once again"};

    for(int i=0; i <= n; i++)
    {
        printf("This old man, he played%s\n", number[i]);
        printf("He played%s\n", thing[i]); 
    }
    
   return 0;
}

