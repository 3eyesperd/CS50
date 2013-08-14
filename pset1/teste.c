#include <stdio.h>
#include <cs50.h>



int main(void)
{
   int height;

   do 
   {
   printf("Height:");
   height = GetInt();    
   } 
   while (height > 23);
   return 0;
}   
