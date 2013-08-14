/****************************************************************************
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 ***************************************************************************/


// includes

// load raw into ram

// check 4 bytes
	//if found
		//create file
 			//while 512b doesnt start with sig
 				//write data
 	//if not
 		//search next 512 bytes



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isJpeg(char[]);

int main(void)
{
	FILE* inptr = fopen("card.raw", "rb");
    if (inptr == NULL)
    {
        
        return 1;
    }
    char output_name[7];
    char buffer[512];
    int count = 0;
    while(!feof(inptr))
    {
        while(!isJpeg(buffer))
         {
            fread(&buffer, 512, 1, inptr);
         }   

        
       
            count++;
            sprintf(output_name, "%d.jpg", count);
            FILE* outptr = fopen(output_name, "w");
            do
            {                
                fwrite(&buffer, 512, 1, outptr);
                fread(&buffer, 512, 1, inptr);
            } while (!isJpeg(buffer) && !feof(inptr));

            fclose(outptr);
            

              
    }

    fclose(inptr);

}



bool isJpeg(char array[])
{
    char header1[4] = {0xff, 0xd8, 0xff, 0xe0};
    char header2[4] = {0xff, 0xd8, 0xff, 0xe1};

    int matches = 0;

    for(int i = 0; i < 4; i++)
        {
            if ((array[i] == header1[i]) || (array[i] == header2[i]))
                matches++;
        }
    return (matches == 4);
}