#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include <stdio.h>
#include <stdlib.h>
#include "ennemis.h"

typedef struct voiture VOITURE;
struct voiture;

void ShowArray(int line, int column, int Array[line][column]);
void initArray(int line, int column, int Array[line][column]);
void test();
void initPlayerPlace(int line,int column, int Array[line][column]);
void newVehicule(int column, int line, int Array[line][column]);
//int verifAliveandScore(int line, int col, VOITURE Array1[line][col], int Array2[3]);
void nextMoment(int line,int column, int Array[line][column]);
void test(int line,int column, int iArray[line][column]);
void createCarOnTop(int line, int column, int Array[line][column]);

void initGame(int line,int column, int Array[line][column]);

void clearScreen();

#endif