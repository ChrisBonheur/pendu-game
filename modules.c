#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "modules.h"
#include <string.h>

/*Search a letter in sentence or string*/
int charIn(const char letter, const char word[])
{
	int i = 0;
	while (word[i] != ENDCARACTER)
	{
		if (letter == word[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

/*This, format the user answer like **F**T*/
void formatResponse(char letters[], char word[], char wordToFormat[])
{
	int i = 0;
	while (word[i] != ENDCARACTER){
		if (charIn(word[i], letters))
		{
			sprintf(&wordToFormat[i], "%c", word[i]);
		}
		else
		{
			sprintf(&wordToFormat[i], "*");
		}
		i++;
	}
}

void emptyBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

/*read and control caracter from user*/
char readCaracter(char *chaine, int length)
{
	char *entryPosition = NULL;

	if (fgets(chaine, length, stdin) != NULL)
	{
		entryPosition = strchr(chaine, '\n');
		if (entryPosition != NULL)
		{
			*entryPosition = '\0';
		}
		else
		{
			emptyBuffer();
		}
		return 1;
	}
	else
	{
			emptyBuffer();
			return 0;
	}
}

/*Read word in file stop before sep param passed
 *for each function call it read next word ...
 wordResult => table that contain the word readed
 sep => caracter that delimate the end of word in file
 fileWords => the FILE pointer variable
 return a last caracter reader;
 * * */
char readWordFile(char* wordResult, FILE* fileWords, char sep)
{
	int i = 0;

	char currentCaracter = 0;
    //rinit wordResult to 0
    while (wordResult[i] != '\0'){
        wordResult[i] = 0;
        i++;
    }

    i = 0;//set i to 0 for new loop
	while (currentCaracter != sep && currentCaracter != EOF)
	{
		currentCaracter = fgetc(fileWords);
		if (currentCaracter != sep && currentCaracter != EOF && currentCaracter != '\n')
		{
			wordResult[i] = currentCaracter;
			i++;
		}
	}
	return currentCaracter;
}

/*create a struct Word with allocation memory and return
 * Word created
 * string : string using to create Word struct*/
Word createWordWithAlloc(char* string)
{
    int i = 0;
    size_t stringLen = 0;
    Word newWord;

    stringLen = strlen(string);
    newWord.word = malloc(stringLen * sizeof(char));
    sprintf(newWord.word, "%s", string);

    return newWord;
}

/*count number of word in files
 * sep: caracter that delimite word
 * file: file that will be used*/
long countWords(char sep, FILE* file)
{
	long wordsCount = 0, i = 0;
	char caracterRead = 'e';
    //init cursor to begin file
	rewind(file);

	while (caracterRead != EOF)
	{
		caracterRead = fgetc(file);
		if (caracterRead == sep)
		{
			wordsCount++;
		}
	}
	return wordsCount;
}

/*add words from file in list
 * wordsList => that contains words from file
 * file => the file with words list
 * sep => caracter that delimite each word in file*/
void setWordsInTable(Word wordsList[], FILE *file, char sep)
{
    int i = 0;
    char lastCaracterReaded = 0;
    char wordReaded[50] = {0};
    Word wordAlloc;

    //init cursor to begin file
	rewind(file);

    //for each word in file:
    while (lastCaracterReaded != EOF)
    {
        lastCaracterReaded = readWordFile(wordReaded, file, sep);
        wordAlloc = createWordWithAlloc(wordReaded);
        wordsList[i] = wordAlloc;
        i++;
    }
}
