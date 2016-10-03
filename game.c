#include "game.h"
#include <unistd.h>
#include <time.h>
int main()
{
	printf("coucou je bug");
	int i;
	int iArray[100][3];
	initArray(100,3,iArray);
	initGame(100,3,iArray);
	initPlayerPlace(100,3,iArray);
	ShowArray(76,3,iArray);
	nextMoment(100,3,iArray);
	ShowArray(76,3,iArray);
	for(i=0; i<100;i++)
	{
		nextMoment(100,3,iArray);
		ShowArray(76,3,iArray);
		usleep(500000);
		clearScreen();
	}
	return 0;
}