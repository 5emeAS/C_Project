#include "affichage.h"
//#include "voiture.h"
#include <unistd.h>
#include <time.h>
typedef struct voiture VOITURE;
struct voiture
{
int posx; /* Position courante x de la voiture */
int posy; /* Position courante y de la voiture */
char alignement; /* ’g’=>gauche ou ’m’=>milieur ou ’d’=>droite */
char type; /* ’v’=>voiture, ’c’=>camion, etc. */
char couleur[10]; /* Couleur du véhicule */
char custom[30]; /* Contient le véhicule customisé */
char etat; /* État du véhicule => actif ou inactif */
double speed; //in case of differents cars.
int choix;
};

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
				if(Array[i][j] == 3)
					printf("  v	 ");
				else
					if(Array[i][j] == 10)
					printf("  _	 ");
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
	int i,j;
	for(i=0; i<line;i++)
	{
		for(j=0;j<column;j++)
		{
			Array[i][j] = 0;
		}
	}
}

void initPlayerPlace(int line,int column, int Array[line][column])
{
	Array[75][1] = 10;
}

void newVehicule(int choice,int choix, int place ,int column, int line, int Array[line][column]) // need voiture.h
{
	if(choice > 15)
	{
		Array[99][place]=choix;
	}
}
/*
int verifAliveandScore(int line, int col, VOITURE Array1[line][col], int Array2[3])
{
	int i;
	for(i=0;i<3;i++)
	{
		if(Array1[74][i] && Array2[i])
			return -1;
		else
			if(Array1[74][i])
				return 1;

	}
	return 0;
}*/

void nextMoment(int choice,int choix, int place ,int line,int column, int Array[line][column])
{
	int i,j;
	for(i = 99; i>1 ; i--)
	{
		for(j=0;j<3;j++)
		{
			if(i != 74 && i != 75)
				Array[i][j] = Array[i-1][j];
		}
	}
	printf("K\n");
	newVehicule(choice,choix,place,100,3,Array);
	printf("O");
	for(i=0;i<3;i++)
	{
		Array[0][i] = 0;
	}
}
/* revoir en focntion du ses du tableau et donc de parcours*/

void test(int line,int column, int iArray[line][column])
{
	VOITURE a;
	a.posy = 72;
	a.posx = 2;
	iArray[a.posy][a.posx] = 1;
}

void initGame(int line,int column, int Array[line][column])
{
	srand(time(NULL));

	int choice;// % de chance qu'une voiture apparaisse
	int choix; // le type de voiture qui apparait
	int place;
	int i;
	for(i=0; i<25;i++)
	{
			choice = rand()%20;// % de chance qu'une voiture apparaisse
			choix = (rand()%3)+1; // le type de voiture qui apparait
			place = rand()%3;
		if(choice > 15)
					printf("BOOM %d\n",i);

			Array[i][place] = choix;
	}
}

void clearScreen()
{
  const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO,CLEAR_SCREE_ANSI,0);
  printf("\n");
}