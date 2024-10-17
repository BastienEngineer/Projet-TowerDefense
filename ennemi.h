#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED

#include <string.h>
#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "defenses.h"
// niveau par vagues
#define NENNEMI1 3
#define NENNEMI2 5
#define NENNEMI3 10

#define NDEFENSE 10
// Animation Ennemi
#define NIMAGE 4

typedef struct ennemi
{
    int posx, posy;
    int depx, depy;
    int tx,ty;
    int imgcourante;
    /// point de vie
    int ptvie;
    /// vivant pour savoir si on l'affiche ou non
    int vivant;
    /// ralentir séquence
    int tmpimg;
    int cptimg;

} t_ennemi;

// ennemis
t_ennemi * creerennemi(int *speed);
void remplirTabEnnemis(t_ennemi * tab[NENNEMI1],int *speed);
void actualiserEnnemis(t_ennemi *ennemi,int *gameover);
void actualiserTabEnnemis(t_ennemi * tab[NENNEMI1],int *gameover,int*fin);
void dessinerEnnemi( t_ennemi *ennemi, BITMAP *animation[NIMAGE]);
void dessinerTabEnnemis( t_ennemi * tab[NENNEMI1], BITMAP *animation[NIMAGE]);
void enleverennemi(t_ennemi *tab[NENNEMI1]);




#endif // ENNEMI_H_INCLUDED
