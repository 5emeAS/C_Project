#include "affichage.h"

void ShowArray(int line,int column, int Array[line][column])
{
	int i,j,n=0;
	for(i=25; i<line;i++)
	{
		if(i%10 == 0)
			if(n%2)
				printf("🌴 ");
			else printf("🌵 ");
		else printf("  ");
		printf("║");
		for(j=0;j<column;j++)
		{

			if(Array[i][j] == 1)
				printf("  *	 ");
			else
				if(Array[i][j] == 2)
					printf("  O	 ");
				else
					printf("  	 ");
				if(j!=2)
				printf("| ");
			
		}
		printf("║");
		if(i%10 == 0)
			if(n%2)
			{
				printf("🌴 ");
				n++;
			}
			else 
			{
				printf("🌵 ");
				n++;
			}
		else printf("  ");
		printf("\n");

	}
}

void initArray(int line,int column, int Array[line][column])
{
	for(i=0; i<line;i++)
	{
		for(j=0;j<column;j++)
		{
			iArray[i][j] = 0;
		}
	}
}

void initPlayerPlace(int Array[3])
{
	iArray[1] = 1;
}

void newVehicule(voiture Array[line][column]) // need voiture.h
{
	choice = rand()%20;// % de chance qu'une voiture apparaisse
	choix = rand()%3; // le type de voiture qui apparait
	place = rand()%3;
	if(choice > 15)
	{
		Array[99][place]=/*voiture choix in the first line in the Array*/;
	}
}
// fonction d'affichage de tableaux
/*  0-> rien
	1-> voiture
	2-> joueur

*/
int verifAliveandScore(/*Array of cars and player*/)
{
	for(i=0;i<3:i++)
	{
		if(Array1[74][i] && Array2[i])
			return -1;
		else
			if(Array1[74][i])
				return 1;

	}
	return 0;
}

void nextMoment(/*Array of Cars, player and trees*/)
{
	for(i = 98; i>1 ; i--)
	{
		for(j=0;j<3;j++)
		{
			Array[i][j] = Array[i-1][j];
			Array1[i][j] = Array1[i-1][j];
			Array2[i][j] = Array1[i-1][j];
		//refaire en fonction des tailles des tableaux
		}
	}
	newVehicule(Array);
}
/* revoir en focntion du ses du tableau et donc de parcours*/