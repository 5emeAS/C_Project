#ifndef GAME_H
#define GAME_H
#include "voiture.h"

void nextmoment(int choice,int choix,int place,int line,int column, int Array[line][column],int speed, int tim);
int getcolision(int lin, int col, int Array[lin][col]);
double getNewScore(int lin, int col, int Array[lin][col],int speed);


#endif