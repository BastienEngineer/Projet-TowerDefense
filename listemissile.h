#ifndef LISTEMISSILE_H_INCLUDED
#define LISTEMISSILE_H_INCLUDED
#include "missile.h"

typedef struct listemissiles
{
    int max;
    int n;
    t_missile **tab;

} t_listemissiles;


// liste missile
t_listemissiles * creerListemissiles(int maxmissiles);
int libreListemissiles(t_listemissiles *la);
t_missile * ajoutermissile(t_listemissiles *la,int *x,int *y);
void enlevermissile(t_listemissiles *la,int i);
void actualiserListemissiles(t_listemissiles *la);
void dessinerListemissiles(BITMAP *bmp,t_listemissiles *la);

#endif // LISTEMISSILE_H_INCLUDED
