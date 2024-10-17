#ifndef UTILITAIRE_H_INCLUDED
#define UTILITAIRE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <time.h>
#define NIMAGE 4


///Pour ne charger qu'une fois les bitmaps et les samples pour le jeu pur
typedef struct{
BITMAP *menu;
SAMPLE *son;
SAMPLE *son1;
BITMAP *animation1[NIMAGE];
BITMAP *animation2[NIMAGE];
BITMAP *animation3[NIMAGE];
BITMAP *page;
BITMAP *menuHaut;
BITMAP *base;
BITMAP *id;
BITMAP *mine1;
BITMAP *mine2;
BITMAP *exit1;
BITMAP *defense;
}t_images;

extern t_images img;

///Ici même système mais exclusivement pour les "events" de la Narration et les règles
typedef struct{
BITMAP *regle1;
BITMAP *regle2;
BITMAP *niv1;
BITMAP *niv2;
BITMAP *niv3;
BITMAP *gameover1;
BITMAP *gameover2;
BITMAP *win1;
BITMAP *win2;
}t_Narration;

extern t_Narration nar;

void charger_image_son();
void charger_Narration();
void lancerToutAllegro(int largeur, int hauteur);
BITMAP * load_bitmap_check(char *nomImage);
void regles();
void menuInterface();
int lireniveau();
void quitter();
void save_niveau(int nivx);
void sauvegarde(int nivx);


#endif // UTILITAIRE_H_INCLUDED
