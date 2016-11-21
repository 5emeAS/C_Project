#include "affichage.h"
#define RED     "\033[1;31m" 
#define WHITE   "\033[0;m" 
#define GREEN   "\033[1;32m" 
#define BLUE    "\033[1;34m"
#define YELL	"\033[1;33m"

void ShowArray(int line, int column, int Array[line][column],int speed,int score, int highscore,int stop)
{
	int i,j,n=0;
	for(i=0; i<line;i++)
	{
		printf("				");
		if(i%10 == 0)
			if(n%2)
				printf(YELL"🌴 ");
			else printf(GREEN"🌵 ");
		else printf("  ");
		printf(WHITE"║");
		for(j=0;j<column;j++)
		{

			if(Array[i][j] == 10 && !stop)
				printf(RED"  🚘	 ");
			else
			{
				if(Array[i][j] == 10)
					printf(RED"  💥	 ");
				else
				if(Array[i][j])
					printf(BLUE"  🚘	 ");
				else
					printf("  	 ");
				if(j!=column-1)
				printf(WHITE"| ");
			
			}
			
		}
		printf(WHITE"║");
		if(i%10 == 0)
			if(n%2)
			{
				printf(YELL"🌴 ");
				n++;
			}
			else 
			{
				printf(GREEN"🌵 ");
				n++;
			}
		else printf("  ");
		if(i==line-50)
			printf("	speed = %d",speed);
		if(i == line-49)
			printf(BLUE"	score = %d",score);
		if(i == line-48)
		{
			if(highscore > score)
				printf(RED"	highscore = %d",highscore);
			else printf(BLUE"	highscore = %d",score);

		}

		printf("\n");
	}
}
