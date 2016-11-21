#include "IA.h"

int theIAchoice(int lin,int col,int Array[lin][col],int level)
{
	int i;
	int place;
	int choice = rand()%2;
	int err = rand()%100;
	int err2 = rand()%300;
	for(i=0;i<col;i++)
	{
		if(Array[lin-1][i] == 10)
			place = i;
	}
	
	if(level == 1)
	{
		if(Array[lin-2][place] != 0)
		{
			if(choice == 0)
			{
				if(place > 0)
				{
					if(Array[lin-2][place-1] == 0)
						{
							Array[lin-1][place-1] = 10;
							Array[lin-1][place] = 0;
						}
				}
				else
					if(Array[lin-2][place+1] == 0)
						{
							Array[lin-1][place+1] = 10;
							Array[lin-1][place] = 0;
						}
			}
			if(choice == 1)
			{
				if(place < col-1)
				{
					if(Array[lin-2][place+1] == 0)
						{
							Array[lin-1][place+1] = 10;
							Array[lin-1][place] = 0;
						}
				}
				else
					if(Array[lin-2][place-1] == 0)
						{
							Array[lin-1][place-1] = 10;
							Array[lin-1][place] = 0;
						}
			}
			for(i=0;i<col;i++)
			{			
				if(Array[lin-1][i] == 10)
				place = i;
			}
			if(err==25)
			{
					if(place < col-1)
					{
						Array[lin-1][place+1] = 10;
						Array[lin-1][place] = 0;
					}
					else
					if(place > 0)
					{
						Array[lin-1][place-1] = 10;
						Array[lin-1][place] = 0;
					}	
			}
		}
		return 0;
	}

		if(level == 2)
		{
			if(Array[lin-2][place] != 0)
			{
				if(choice == 0)
				{
					if(place > 0)
					{
						if(Array[lin-2][place-1] == 0)
							{
								Array[lin-1][place-1] = 10;
								Array[lin-1][place] = 0;
							}
					}
					else
						if(Array[lin-2][place+1] == 0)
							{
								Array[lin-1][place+1] = 10;
								Array[lin-1][place] = 0;
							}
				}
				if(choice == 1)
				{
					if(place < col-1)
					{
						if(Array[lin-2][place+1] == 0)
							{
								Array[lin-1][place+1] = 10;
								Array[lin-1][place] = 0;
							}
						}
					else
						if(Array[lin-2][place-1] == 0)
							{
								Array[lin-1][place-1] = 10;
								Array[lin-1][place] = 0;
							}
				}
				for(i=0;i<col;i++)
				{			
					if(Array[lin-1][i] == 10)
					place = i;
				}
				if(err2==50)
				{
					if(place < col-1)
					{
						Array[lin-1][place+1] = 10;
						Array[lin-1][place] = 0;
					}
					else
					if(place > 0)
					{
						Array[lin-1][place-1] = 10;
						Array[lin-1][place] = 0;
					}	
				}
				return 2;
			}
		}


	if(level >= 3)
	{

		if(Array[lin-2][place] != 0)
		{
			if(choice == 0)
			{
				if(place > 0)
				{
					if(Array[lin-2][place-1] == 0)
						{
							Array[lin-1][place-1] = 10;
							Array[lin-1][place] = 0;
						}
				}
				else
					if(Array[lin-2][place+1] == 0)
						{
							Array[lin-1][place+1] = 10;
							Array[lin-1][place] = 0;
						}
			}
			if(choice == 1)
			{
				if(place < col-1)
				{
					if(Array[lin-2][place+1] == 0)
						{
							Array[lin-1][place+1] = 10;
							Array[lin-1][place] = 0;
						}
				}
				else
					if(Array[lin-2][place-1] == 0)
						{
							Array[lin-1][place-1] = 10;
							Array[lin-1][place] = 0;
						}
			}
		}
	}
	//return (int) (((((((((15+rand()%15)/2.)*0.666)+2)*666)/25)*level)-choice)/777); //pourquoi pas...
		// pas de retour suite à un accord avec le fantôme dans la machine (The Gost in the Shell)
}/*Ghost In The Shell*/