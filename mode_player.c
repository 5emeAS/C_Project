#include "utilitaire.h"
#include "IA.h"
#include "voiture.h"
#include "affichage.h"
#include "game.h"
#include "mode_player.h"
void modePlayer(int size, int way, int speed, int stop, int i, int tim, FILE* fichier, double score, int highscore)
{
	int choice,choix,place;
	int diff;
		printf("Difficulty :\n");
		printf("1.ultra-easy\n2.very easy\n3.easy\n4.normal\n5.difficult\n5.hardcore(non implemented)\n");
		do{
			scanf("%d",&diff);
		}while(diff > 5);
		while(diff < 4)
		{
			diff++;
			way++;	
		}
		if(diff > 4)
			way=2;
			
		int iArray[size][way];
		initArray(size,way,iArray);// piste vide
		initPlayerPlace(size,way,iArray);// place le joueur au milieu
		while(!stop)
		{
			i++;
			if(i>100)
			{
				tim++;
				i=0;
			}
			choice = rand()%20;
			choix = (rand()%3)+1;
			place = rand()%way;
			if(getcolision(size,way,iArray))
				stop= 1;
			score += getNewScore(size,way,iArray,speed);
			if(diff<=4 || i%4 == 0)
				nextmoment(choice,choix,place,size,way,iArray,speed,tim);
			ShowArray(size,way,iArray,speed,score,highscore,stop);
			while(speed <= 0)
			{
				speed+=mvPlayer(size,way,iArray);
			}

			usleep(17000000/(3*speed));
				speed+=mvPlayer(size,way,iArray);
			clearScreen();
			printf("\n");
			
		}
			ShowArray(size,way,iArray,speed,score,highscore,stop);
		if (score>highscore)
		{
			fichier = fopen("score.txt", "w");
 	
 		   if (fichier != NULL)
	 	   {
	    	    fprintf(fichier, "%d", (int)score);
	    	    fclose(fichier);
	    	}
		}

		printf("It's the end you had an accident and you died...\n");
		printf("Votre score est de : %d\n",(int)score);
		if(score > highscore)
			printf("Vous avez battu votre prédécesseur bienvenu parmi nous !\n");
}