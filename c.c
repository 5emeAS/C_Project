#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
#include <error.h>
#define RED     "\033[1;31m" 
#define WHITE   "\033[0;m" 
#define GREEN   "\033[1;32m" 
#define BLUE    "\033[1;34m"
#define YELL	"\033[1;33m"

void ShowArray(int line, int column, int Array[line][column],int speed,int score, int highscore)
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

			if(Array[i][j] == 10)
				printf(RED"  🚘	 ");
			else
				if(Array[i][j])
					printf(BLUE"  🚘	 ");
				else
					printf("  	 ");
				if(j!=column-1)
				printf(WHITE"| ");
			
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

void createCarOnTop(int choice,int choix,int place,int line, int column, int Array[line][column], int speed,int tim)
{
	
	int n= (speed-80)/10;
	if(choice > (13-n)-tim)
	{

		Array[0][place]=choix;/*voiture choix in the first line in the Array*/;
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


void clearScreen()
{
  const char* CLEAR_SCREE_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
}

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

	void initPlayerPlace(int line,int column, int Array[line][column])
{
	Array[line-1][1] = 10;
}

char key_pressed()
{
struct termios oldterm, newterm;
int oldfd;
char c, result = 0;
tcgetattr (STDIN_FILENO, &oldterm);
newterm = oldterm;
newterm.c_lflag &= ~(ICANON | ECHO);
tcsetattr (STDIN_FILENO, TCSANOW, &newterm);
oldfd = fcntl(STDIN_FILENO, F_GETFL, 0);
fcntl (STDIN_FILENO, F_SETFL, oldfd | O_NONBLOCK);
c = getchar();
tcsetattr (STDIN_FILENO, TCSANOW, &oldterm);
fcntl (STDIN_FILENO, F_SETFL, oldfd);
if (c != EOF) {
ungetc(c, stdin);
result = getchar();
}
return result;
}
void mode_raw(int activer) 
{ 
    static struct termios cooked; 
    static int raw_actif = 0; 
  
    if (raw_actif == activer) // si on est déjà dans le bon mode
        return; 
  
    if (activer) //sinon si il faut activer
    { 
        struct termios raw; 
  
        tcgetattr(STDIN_FILENO, &cooked); 
  
        raw = cooked; 
        cfmakeraw(&raw); 
        tcsetattr(STDIN_FILENO, TCSANOW, &raw); 
    } 
    else 
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked); //désactiver
  
    raw_actif = activer; //on se souviens de notre mode actue
}
int unix_text_kbhit(void) 
{ 
    struct timeval tv = { 0, 0 }; 
    fd_set readfds; 
  
    FD_ZERO(&readfds); 
    FD_SET(STDIN_FILENO, &readfds); 
  
    return select(STDIN_FILENO + 1, &readfds, NULL, NULL, &tv) == 1; 
}
	
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

int getcolision(int lin, int col, int Array[lin][col])
{
	int i, place;
	for(i=0;i<col;i++)
	{
		if(Array[lin-1][i] == 10)
			place = i;
	}
	if(Array[lin-2][place] != 0)
	{
		Array[lin-1][i] == 11;
		return 1;

	}
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

int theIAchoice(int lin,int col,int Array[lin][col],int level)
{
	int i;
	int place;
	int choice = rand()%2;
	int err = rand()%100;
	int err2 = rand()%300;
	int boost = rand()%5;
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
			if(choice == 1)
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
			for(i=0;i<col;i++)
			{			
				if(Array[lin-1][i] == 10)
				place = i;
			}
			if(err==25)
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
		return 0;
	}

		if(level == 2)
		{
			if(Array[lin-2][place] != 0)
			{
				if(choice == 0)
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
				if(choice == 1)
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
				for(i=0;i<col;i++)
				{			
					if(Array[lin-1][i] == 10)
					place = i;
				}
				if(err2==50)
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

				return 2;
			}
		}


	if(level >= 3)
		if(Array[lin-2][place] != 0)
		{
			if(choice == 0)
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
			if(choice == 1)
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



int main()
{
	int playerorauto = 0;
	while(playerorauto!=1 && playerorauto !=2)
	{
		printf("				");
		printf("Hello what do you want to do ?\n");
		printf("				");
		printf("1. Start the game\n");
		printf("				");
		printf("2. Let the computer Play\n");
		printf("				");
		printf("3. See credits\n");
		do{
			scanf("%d",&playerorauto);
		}while(playerorauto > 3);
			if(playerorauto == 3)
				printf("				Welcome to this Game\n		It was developped by ARNAUD SOULAT and FREDERICK LUKSCH\n		You start the game on speedway but not in the good way\n		Your were probably drunk. Anyway try to survive as much as possible.\n		If you beat our expectation you'll possibly join us.\n				Waiting for ya!\n\n\n");
	}
	double score = 0;
	int speed = 80;
	int stop =0;
	int size=50;
	int way = 3;
	srand(time(NULL));
	int i = 0;
	
	int choice,choix,place;
	char c;
	int tim = 0;
	FILE* fichier = NULL;
    int highscore = 0;
 
    fichier = fopen("score.txt", "r");
 
    if (fichier != NULL)
    {
        fscanf(fichier, "%d", &highscore);
        fclose(fichier);
    }

	//mode_raw(1);
	if(playerorauto == 1)
	{
		int diff;
		printf("Difficulty :\n");
		printf("1.ultra-easy\n2.very easy\n3.easy\n4.normal\n5.difficult\n5.hardcore(non implemented)\n");
		do{
			scanf("%d",&diff);
		}while(diff > 5);
		while(diff < 4)
		{
			diff++;
			way++;
		}
		if(diff > 4)
			way=2;
			
		int iArray[size][way];
			initArray(size,way,iArray);// piste vide
			initPlayerPlace(size,way,iArray);// place le joueur au milieu
		while(!stop)
		{
			i++;
			if(i>100)
			{
				tim++;
				i=0;
			}
			choice = rand()%20;
			choix = (rand()%3)+1;
			place = rand()%way;
			if(getcolision(size,way,iArray))
				stop= 1;
			score += getNewScore(size,way,iArray,speed);
			if(diff<=4 || i%4 == 0)
				nextmoment(choice,choix,place,size,way,iArray,speed,tim);
			ShowArray(size,way,iArray,speed,score,highscore);
			while(speed <= 0)
			{
				if(unix_text_kbhit)
				speed+=mvPlayer(size,way,iArray);
			}

			usleep(17000000/(3*speed));
			if(unix_text_kbhit)
				speed+=mvPlayer(size,way,iArray);
			clearScreen();
			printf("\n");
			fflush(stdin);
			fflush(stdout);
		}
		if (score>highscore)
		{
			fichier = fopen("score.txt", "w");
 	
 		   if (fichier != NULL)
	 	   {
	    	    fprintf(fichier, "%d", (int)score);
	    	    fclose(fichier);
	    	}
		}

		printf("It's the end you had an accident and you died...\n");
		printf("Votre score est de : %d\n",(int)score);
		if(score > highscore)
			printf("Vous avez battu votre prédécesseur bienvenu parmi nous !\n");
	}
	else
	{
		int lev = 0;
		printf("Computer skill :\n");
		printf("1.normal\n2.good\n3.God\n4.God(Unleashed)\n");
		do{
			scanf("%d",&lev);
		}while(lev > 4);
		int iArray[size][way];
		initArray(size,way,iArray);// piste vide
		initPlayerPlace(size,way,iArray);// place le joueur au milieu
		while(!stop)
		{
			i++;
			if(i>100)
			{
				tim++;
				i=0;
			}
			choice = rand()%20;
			choix = (rand()%3)+1;
			place = rand()%3;
			if(getcolision(size,3,iArray))
				stop= 1;
			score += getNewScore(size,3,iArray,speed);
			nextmoment(choice,choix,place,size,3,iArray,speed,tim);
			ShowArray(size,3,iArray,speed,score,highscore);
			if(speed > 250)
			{
				if(lev < 4)
				speed = 250;
				if(unix_text_kbhit)
					speed+=theIAchoice(size,3,iArray,lev);
			}

			usleep(17000000/(3*speed));
			if(unix_text_kbhit)
				speed+=theIAchoice(size,3,iArray,lev);
			clearScreen();
			printf("\n");
			fflush(stdin);
			fflush(stdout);
		}
		if (score>highscore)
		{
			fichier = fopen("score.txt", "w");
 	
 		   if (fichier != NULL)
	 	   {
	    	    fprintf(fichier, "%d", (int)score);
	    	    fclose(fichier);
	    	}
		}
		printf("Le score est de : %d\n",(int)score);


	}
	//mode_raw(0);
	return 0;
}