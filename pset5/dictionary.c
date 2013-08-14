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


char lowercase(char input);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
	int low = 0;
	int max = numberOfWords;
	int medium = (low + max)/2;

	char tmp[strlen(word) +1];

	strcpy(tmp,word);
	tmp[strlen(word)] = '\0';

	for( int i = 0; i <= strlen(word); i++  )
	{
		tmp[i] = lowercase(tmp[i]);
	}
	



	while (low < max)
	{
		if ( strcmp(tmp,wordsArray[medium]) == 0)
			return true;
		else if(strcmp(tmp,wordsArray[medium]) == 1)
		{
			low = medium + 1;
			medium = (low + max)/2;
		}
		else
		{
			max = medium;
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
	char buffer[46];
	int lenght = 0;
	int c = 0;
	while((c = fgetc(f)) != EOF)
	{

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
	fclose(f);
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
    for (int i = 0; i < numberOfWords; i++)
    	free(wordsArray[i]);
    free(wordsArray);
    return true;
}


char lowercase(char input)
{
    if( input < 91 && (input > 64))
        input =  input + 32;
        
    return(input);
}