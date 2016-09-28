#ifndef AFFICHAGE_H
#define AFFICHAGE_H
typedef struct voiture VOITURE;
struct voiture
{
int posx; /* Position courante x de la voiture */
int posy; /* Position courante y de la voiture */
char alignement; /* ’g’=>gauche ou ’m’=>milieur ou ’d’=>droite */
char type; /* ’v’=>voiture, ’c’=>camion, etc. */
char couleur[10]; /* Couleur du véhicule */
char custom[30]; /* Contient le véhicule customisé */
char etat; /* État du véhicule => actif ou inactif */
double speed; //in case of differents cars.
};

#endif