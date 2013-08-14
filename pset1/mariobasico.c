#include <stdio.h>
#include <cs50.h>

int main(void)
{
   int height;

   // Will only accept numbers beetwen 0 and 23
    
   do 
   {
       printf("Height:");
       height = GetInt();    
   } 
   while (height < 0 || height >23);
   {
       int espaco;
       int blocos;
       int linha;


       for(linha = 0; linha < height; linha++)
       {
                    for(espaco = 0; espaco <= (height - linha-2); espaco++)
                    {
                        printf(" ");
                    }
                    for(blocos = 0; blocos <= linha+1; blocos++)
                    {
                        printf("#");
                    }
               
                    
                    printf("\n");
       }   
   }
         
    return 0;
}
