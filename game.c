#include "affichage.h"

int main()
{
	

	int iArray[100][3];
	int i,j;
	for(i=0; i<100;i++)
	{
		for(j=0;j<3;j++)
		{
			iArray[i][j] = 0;
		}
	}
	iArray[74][1] = 2;
	ShowArray(75,3,iArray);

	return 0;
}