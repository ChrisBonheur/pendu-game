#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include "modules.h"

int main(int argc, char *argv[])
{
	char userChoice[CHOICE_LENGTH] = {0};
	long userChoiceConvert = 0;
	char gameRun = TRUE, gameContinue = TRUE;

	options();//show menu indication

	while (gameContinue == TRUE)
	{
		while (gameRun == TRUE)
		{
			printf("=> ");
			readCaracter(userChoice, CHOICE_LENGTH);
			userChoiceConvert = strtol(userChoice, NULL, 10);
			if (userChoiceConvert == 1 || userChoiceConvert == 0)
			{
                gameRun = FALSE;
			}
		}

		if (userChoiceConvert == 1)
		{
			startGame();//launch game
			printf("\n Entrez : \n1 pour continuer \n 0 pour quitter \n");
			printf("=> ");
			readCaracter(userChoice, CHOICE_LENGTH);
			userChoiceConvert = strtol(userChoice, NULL, 10);

			if (userChoiceConvert == 0)
			{
				gameContinue = FALSE;
			}
		}
		else
		{
			exit(0);
		}
	}
	printf("*************Good bye, see you later*********\n");

	return 0;
}
