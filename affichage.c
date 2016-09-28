#include "affichage.h"
//#include "voiture.h"

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

void initPlayerPlace(int Array[3])
{
	Array[1] = 1;
}

void newVehicule(int column, int line, int Array[line][column]) // need voiture.h
{
	int choice = rand()%20;// % de chance qu'une voiture apparaisse
	int choix = rand()%3; // le type de voiture qui apparait
	int place = rand()%3;
	if(choice > 15)
	{
		Array[99][place]=choix;/*voiture choix in the first line in the Array*/;
	}
}
// fonction d'affichage de tableaux
/*  0-> rien
	1-> voiture
	2-> joueur

*/
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
}

void nextMoment(/*Array of Cars, player and trees*/)
{
	/*for(i = 98; i>1 ; i--)
	{
		for(j=0;j<3;j++)
		{
			Array[i][j] = Array[i-1][j];
			Array1[i][j] = Array1[i-1][j];
			Array2[i][j] = Array1[i-1][j];
		//refaire en fonction des tailles des tableaux
		}
	}
	newVehicule(Array);*/
}
/* revoir en focntion du ses du tableau et donc de parcours*/
