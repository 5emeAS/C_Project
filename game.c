#include "game.h"
#include <unistd.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int a,b,c;
	int i;
	int iArray[100][3];
	initArray(100,3,iArray);
	initGame(100,3,iArray);
	printf("k\n");
	initPlayerPlace(100,3,iArray);
	printf("ko\n");
	ShowArray(76,3,iArray);
	printf("ok\n");
	a = rand()%20;
	b = rand()%3+1;
	c = rand()%3;
	nextMoment(a,b,c,100,3,iArray);
	printf("BIM\n");
	ShowArray(76,3,iArray);
	for(i=0; i<100;i++)
	{
		
		a = rand()%20;
		b = 1+rand()%3;
		c = rand()%3;
		printf("BAM\n");
		printf("%d-%d-%d\n",a,b,c);

		nextMoment(a,b,c,100,3,iArray);
		ShowArray(76,3,iArray);
		usleep(500000);

		clearScreen();
	}
	return 0;
}