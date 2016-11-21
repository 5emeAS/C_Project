#include <stdio.h>
#include <stdlib.h>
#include "mode_IA.h"
#include "mode_player.h"
#include <unistd.h>
#include <time.h>
#include "utilitaire.h"
int main()
{
	int playerorauto = 0;
		clearScreen();
	while(playerorauto!=1 && playerorauto !=2)
	{
		printf("				");
		printf("Hello what do you want to do ?\n");
		printf("				");
		printf("1. Start the game\n");
		printf("				");
		printf("2. Let the computer Play\n");
		printf("				");
		printf("3. See credits\n");
		do{
			scanf("%d",&playerorauto);
		}while(playerorauto > 3);
			if(playerorauto == 3)
				printf("				Welcome to this Game\n		It was developped by ARNAUD SOULAT and FREDERICK LUKSCH\n		You start the game on speedway but not in the good way\n		Your were probably drunk. Anyway try to survive as much as possible.\n		If you beat our expectation you'll possibly join us.\n				Waiting for ya!\n\n\n");
	}
	double score = 0;
	int speed = 80;
	int stop =0;
	int size=50;
	int way = 3;
	srand(time(NULL));
	int i = 0;
	
	int tim = 0;
	FILE* fichier = NULL;
    int highscore = 0;
 
    fichier = fopen("score.txt", "r");
 
    if (fichier != NULL)
    {
        fscanf(fichier, "%d", &highscore);
        fclose(fichier);
    }

	//mode_raw(1);
	if(playerorauto == 1)
		modePlayer(size, way,speed, stop, i, tim, fichier, score, highscore);

	else
		modeIA(size, way, speed, stop, i, tim, fichier, score, highscore);
		
	//mode_raw(0);
	return 0;
}
