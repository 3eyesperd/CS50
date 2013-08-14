#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size);

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = GetInt();
    if (search(n, numbers, SIZE))
        printf("YES\n");
    return 0;
}


bool search(int needle, int haystack[], int size)
{
    if (size == 0)
        return (size == haystack[0]);
       
    if( needle < haystack[size/2])
        {
            
            int new_size = (size/2);
            int new_array[new_size];
                for(int i=0; i < new_size; i++)
                {
                    new_array[i] = haystack[0 + i];
                }
            return(search(needle, new_array, new_size)); 
        }
    if( needle > haystack[size/2])
        {
            
            int new_size = (size/2);
            int new_array[new_size];
                for(int i=0; i < new_size; i++)
                {
                    new_array[i] = haystack[(size/2) + i];
                }
            return(search(needle, new_array, new_size)); 
        }
    else
        return true;          
    
    
    return false;
         
}    
    
      
    
    
