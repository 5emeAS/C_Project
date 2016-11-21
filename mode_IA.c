#include "utilitaire.h"
#include "IA.h"
#include "voiture.h"
#include "affichage.h"
#include "game.h"
#include "mode_IA.h"

void modeIA(int size, int way,int speed, int stop, int i, int tim, FILE* fichier, double score, int highscore)
{
	int choice,choix,place;
	int lev = 0;
	printf("Computer skill :\n");
	printf("1.normal\n2.good\n3.God\n4.God(Unleashed)\n");
	do{
		scanf("%d",&lev);
	}while(lev > 4);
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
		nextmoment(choice,choix,place,size,way,iArray,speed,tim);
		ShowArray(size,way,iArray,speed,score,highscore,stop);
		if(speed > 220)
		{
			if(lev < 4)
				speed = 220;
	
				speed+=theIAchoice(size,way,iArray,lev);
		}
		usleep(17000000/(3*speed));

			speed+=theIAchoice(size,way,iArray,lev);
		clearScreen();
		printf("\n");
		fflush(stdin);
		fflush(stdout);
	}
	if (score>highscore)
	{
		fichier = fopen("score.txt", "w");
	
		   if (fichier != NULL)
 	    {
    	    fprintf(fichier, "%d", (int)score);
    	    fclose(fichier);
    	}
	}
		ShowArray(size,way,iArray,speed,score,highscore,stop);
	printf("Le score est de : %d\n",(int)score);
}