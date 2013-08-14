#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: cat filename [filename ...]\n");
        return 1;
    }

    FILE *filePtr = 0;
    int c = 0;
    for (int i = 1; i < argc; i++)
    {
        
        if ((filePtr = fopen (argv[i],"r")) == NULL)
            
        {
            printf("Error opening file #%i", i - 1);
            exit (1);
        }

        printf ("File number #%i", i);
        c = 0;
        while (c != EOF )
        {
            c = getc(filePtr);
            printf("%c", c);
        }

        printf("\n");

    }

    return 0;
}

