CC=gcc
CFLAGS=-Wall -lSDL2 `sdl-config --cflags --libs`
EXEC=main

all: $(EXEC) clean


main: game.o voiture.o joueur.o ennemis.o affichage.o
	$(CC) -o main voiture.o joueur.o ennemis.o affichage.o  $(CFLAGS)

game.o: game.c game.h
	$(CC) -o game.o -c game.c $(CFLAGS)

voiture.o: voiture.c voiture.h
	$(CC) -o voiture.o -c voiture.c $(CFLAGS)


joueur.o: joueur.c joueur.h
	$(CC) -o joueur.o -c joueur.c $(CFLAGS)


ennemis.o: ennemis.c ennemis.h
	$(CC) -o ennemis.o -c ennemis.c $(CFLAGS)


affichage.o: affichage.c affichage.h
	$(CC) -o affichage.o -c affichage.c $(CFLAGS)


clean:
	rm -rf *.o core

mrproper: clean
	rm -f main
