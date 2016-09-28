CC=gcc
CFLAGS=-Wall
#-lSDL2 `sdl-config --cflags --libs`

all: exe clean


exe: affichage.o game.o joueur.o voiture.o ennemis.o
	$(CC) $(CFLAGS) affichage.o joueur.o ennemis.o voiture.o game.o  -o exe

game.o: game.c game.h
	$(CC) -c game.c $(CFLAGS)

voiture.o: voiture.c voiture.h
	$(CC) -c voiture.c $(CFLAGS)


joueur.o: joueur.c joueur.h
	$(CC) -c joueur.c $(CFLAGS)


ennemis.o: ennemis.c ennemis.h
	$(CC) -c ennemis.c $(CFLAGS)


affichage.o: affichage.c affichage.h
	$(CC) -c affichage.c $(CFLAGS)


clean:
	rm -rf *.o core

mrproper: clean
	rm -f exe

run:
	@./exe