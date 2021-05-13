#define ENDCARACTER '\0'
#define TRUE 1
#define FALSE 0
typedef struct Word Word;
struct Word
{
	char *word;
};

int charIn(const char letter, const char word[]);
void formatResponse(char letters[], char word[], char wordToFormat[]);
char readCaracter(char *chaine, int length);
void setWordsInTable(Word wordsList[], FILE *file, char sep);
char readWordFile(char *wordResult, FILE *fileWords, char sep);
long countWords(char sep, FILE* file);

