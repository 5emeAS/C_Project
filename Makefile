CC=gcc
CFLAGS=-Wall

prog: utilitaire.o voiture.o game.o affichage.o IA.o mode_player.o mode_IA.o main.o
	$(CC) $(CFLAGS) utilitaire.o voiture.o game.o affichage.o IA.o mode_player.o mode_IA.o main.o -o executable
	@./executable
utilitaire.o: utilitaire.c
	$(CC) $(CFLAGS) -c utilitaire.c

voiture.o: voiture.c
	$(CC) $(CFLAGS) -c voiture.c

game.o: game.c
	$(CC) $(CFLAGS) -c game.c

affichage.o: affichage.c
	$(CC) $(CFLAGS) -c affichage.c

IA.o: IA.c
	$(CC) $(CFLAGS) -c IA.c

mode_player.o: mode_player.c
	$(CC) $(CFLAGS) -c mode_player.c

mode_IA.o: mode_IA.c
	$(CC) $(CFLAGS) -c mode_IA.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -rf *.o
	rm -rf executable

run:
	@./executable