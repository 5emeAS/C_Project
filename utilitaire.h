#ifndef UTILITAIRE_H
#define UTILITAIRE_H

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
#include "affichage.h"
void initArray(int line,int column, int Array[line][column]);
void clearScreen();
char key_pressed();
void mode_raw(int activer);
int unix_text_kbhit(void);


#endif