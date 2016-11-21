#include "game.h"

void nextmoment(int choice,int choix,int place,int line,int column, int Array[line][column],int speed, int tim)
{
	int i,j;
	Array[1][0] = Array[0][0];
	Array[1][1] = Array[0][1];
	Array[1][2] = Array[0][2];
	for(i = line-2; i>0 ; i--)
	{
		for(j=0;j<column;j++)
		{
			Array[i][j] = Array[i-1][j];
			Array[i-1][j] = 0;
		}
	}
	for(i=0;i<column;i++)
	{
		if(Array[line-1][i] != 10)
			Array[line-1][i] = 0;
		Array[0][j] = 0;
	}
	createCarOnTop(choice,choix,place,line,column,Array,speed,tim);
}

int getcolision(int lin, int col, int Array[lin][col])
{
	int i, place;
	for(i=0;i<col;i++)
	{
		if(Array[lin-1][i] == 10)
			place = i;
	}
	if(Array[lin-2][place] != 0)
		return 1;
	return 0;
}

double getNewScore(int lin, int col, int Array[lin][col],int speed)
{
	int i = 0;
	double score=0;
	for(i=0;i<col;i++)
	{
		if(Array[lin-2][i] != 0)
			score+= speed/80.;
	}
		return score;
}