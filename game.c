#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "modules.h"
#include "game.h"

/*initialize words list with allocation memory
@liste: liste word pointer
@fileWords: the file contain words
@sep: char delimiter word
static int initWordListWithAlloc(Word *liste, FILE *fileWords, char sep)
{
    long wordsCount;
    int i = 0;
    wordsCount = countWords(',', fileWords);
    liste = malloc(sizeof(char) * 500);
    if (liste == NULL)
    {
        exit(0);
    }
    setWordsInTable(liste, fileWords, sep);
    for (i = 0; i < countWords(',', fileWords); i++)
    {
        printf("%s\n", liste[i].word);
    }
    free(liste);

    return 1;
}*/

/*get random word in filewords
return Word struct
@fileName: file name of file contain words
@sep: delimiter char word*/
static Word getRandomWord(const char *fileName, char sep)
{
    long indexRandom = 0;
    const int INDEX_MIN = 0;
    long INDEX_MAX = 0;
    FILE *fileWords = NULL;
    Word wordsList[WORD_LIST_LENGTH] = {0};

    //read file and set table list
    fileWords = fopen(fileName, "r");
    if (fileWords != NULL)
    {
        INDEX_MAX = countWords(sep, fileWords) - 1;
        setWordsInTable(wordsList, fileWords, sep);
        fclose(fileWords);
    }
    else
    {
        printf("Warning: Can't open file, may file not exist !\n");
        exit(0);
    }
    //get random index
    srand(time(NULL));
    indexRandom = (rand() % (INDEX_MAX - INDEX_MIN + 1)) + INDEX_MIN;

    return wordsList[indexRandom];
}

void printWord()
{
    FILE *fileWord = NULL;
    Word randomWord;

    randomWord = getRandomWord(FILE_WORD, ',');
    printf("%s\n", randomWord);
}
void startGame()
{
	int nivel = 0;
	char userResponses[50] = {0};
	char formatWord[50] = {0};
	Word mysterWord = getRandomWord(FILE_WORD, ',');

	printf("Entrez votre 1ere lettre et trouvez le mot mystère\n");

	do
	{
		printf("=>");
    readCaracter(&userResponses[nivel], 50);
		//show format response
		formatResponse(userResponses, mysterWord.word, formatWord);
		//show response
		printf("%s\n", formatWord);
		//verify if format response not contain "*" like *R**F*
		if (!charIn('*', formatWord))
		{
			printf("***Bingo vous avez Trouvé le mot sous %d coups***\n", nivel);
			break;
		}
		nivel++;
	}while(nivel < 10);
}

void options()
{
	printf("************************************\n");
	printf("***Bienvenue dans le jeu du Pendu***\n");
	printf("\t 1 pour commencer une partie\n");
	printf("\t 2 pour quitter\n");
}
