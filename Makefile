CC=gcc
CFLAGS=-Wall

prog:  joueur.o ennemis.o affichage.o game.o 
	$(CC) $(CFLAGS) joueur.o ennemis.o affichage.o game.o -o executable


joueur.o: joueur.c
	$(CC) $(CFLAGS) -c joueur.c

#voiture.o: voiture.c
#	$(CC) $(CFLAGS) -c voiture.c

ennemis.o: ennemis.c
	$(CC) $(CFLAGS) -c ennemis.c

affichage.o: affichage.c
	$(CC) $(CFLAGS) -c affichage.c

game.o: game.c
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -rf *.o

run:
	@./executable