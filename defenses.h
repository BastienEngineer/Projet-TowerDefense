#ifndef DEFENSES_H_INCLUDED
#define DEFENSES_H_INCLUDED

#include "missile.h"
typedef struct base
{
    ///position en jeu
    int x,y;
    ///taille de la défense
    int tx, ty;
    ///Type de defense
    int cas;
    ///Pour Gérer l'actualisation de l'affichage
    //0 si on doit l'enlever
    //1 par défaut
    int vivant;
    ///Pour associer le missile aux mages
    t_missile * missile;
    ///Pour associer une BITMAP
    BITMAP * base;

    int comportement;
    int cptexplo;

} t_base;

///Pour gérer la liste
typedef struct listeDef
{
    ///prend la valeur de taille
    int max;
    ///Effectif stocké
    int n;
    ///tableau de pointeurs
    t_base **tab;

} t_listeDef;




// defense
t_base * CreerDefense(int x, int y, int cas);
void AfficherDefenser(t_listeDef *defenses, int posx, int posy, int cas, int taille);
t_listeDef * creerListeDef(int maxacteurs);
t_base * ajouterDef(t_listeDef *la,int x,int y,int type);
void actualiserDefense(t_base *defense);
void enleverDefense(t_listeDef *la, int i);
void actualiserListeDefenses(t_listeDef *la, int x, int y, int type);
void enleverListeDef(t_listeDef *la);



#endif // DEFENSES_H_INCLUDED
