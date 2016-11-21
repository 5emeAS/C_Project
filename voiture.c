#include <stdio.h>
#include <stdlib.h>
#include "utilitaire.h"
#include "voiture.h"

int mvPlayer(int lin, int col, int Array[lin][col])
{
	int i, place;
	for(i=0;i<col;i++)
	{
		if(Array[lin-1][i] == 10)
			place = i;
	}
	char c = key_pressed();
	if(c == '3')
	{
		if(place < col-1)
		{
			Array[lin-1][place] = 0;
			Array[lin-1][place+1] = 10;
		}
		
		return 0;
	}
	if(c == '1')
	{
		if(place > 0)
		{
			Array[lin-1][place] = 0;
			Array[lin-1][place-1] = 10;
		}
		return 0;
	}
	if(c == '2')
	{
		return -1;
	}
	if(c == '5')
	{
		return +1;
	}
	return 0;
}

void createCarOnTop(int choice,int choix,int place,int line, int column, int Array[line][column], int speed,int tim)
{
	
	int n= (speed-80)/10;
	if(choice > (13-n)-tim)
	{

		Array[0][place]=choix;/*voiture choix in the first line in the Array*/;
	}
}

void initPlayerPlace(int line,int column, int Array[line][column])
{
	Array[line-1][1] = 10;
}
