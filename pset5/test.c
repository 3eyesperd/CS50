/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"


int numberOfWords = 0;
char **wordsArray;


int main(void)
{
	load("/home/cs50/pset5/dictionaries/large");
	printf("%s", wordsArray[3]);
	return 1;


}




/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	int low = 0;
	int max = numberOfWords;
	int medium = (low + max)/2;

	

	while (low != max)
	{
		if (strcmp(word,wordsArray[medium]) == 0)
			return true;
		else if(strcmp(word,wordsArray[medium]) == 1)
		{
			low = medium + 1;
			medium = (low + max)/2;
		}
		else
		{
			max = medium -1;
			medium = (low + max)/2;
		}


	}


    return false;
}





/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)

    
{
	FILE* f;
	int bufferSize = 16;
	wordsArray = (char**)malloc(bufferSize*sizeof(char*));
	f = fopen(dictionary, "r");
	if (f == NULL)
        return false;
	char buffer[45];
	int lenght = 0;
	int c = 0;
	while((c = fgetc(f)) != EOF)
	{	

		c = lowercase(c);
		if (c == '\n')
		{	
			
			if (numberOfWords == bufferSize)
				{
					bufferSize = 2*bufferSize;	
					wordsArray = (char**)realloc(wordsArray, sizeof(char*)*bufferSize);
				}
			

			
			wordsArray[numberOfWords] = (char*)malloc(sizeof(char)*(lenght + 1));
			
			strncpy(wordsArray[numberOfWords], buffer, lenght);
			wordsArray[numberOfWords][lenght] = '\0';
			numberOfWords++;
			lenght = 0;

		}
		else
		{
			buffer[lenght] = (char)c;
			lenght++;
		}
		
		
	}	
	free(f);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return numberOfWords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    free(wordsArray);
    return true;
}


char lowercase(char input)
{
    if( (int) input < 96 && (int) input != 32)
        input = (int) input + 32;
        
    return(input);
}