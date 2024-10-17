///Il y a eu des tentatives ici d'intégration de missiles il missile s'affiche et se déplace jusqu'au bord droit en cliquant sur un mage lors d'un assaut
#include "utilitaire.h"
#include "missile.h"
/// Sources
/*
Extraits de code récupérés de la page sur le site de Mr Fercoq :
https://fercoq.bitbucket.io/allegro/

-TP4 Gestion Acteurs
https://fercoq.bitbucket.io/allegro/tp4/tp4_etape4.zip
https://fercoq.bitbucket.io/allegro/tp4/allegro_tp4.pdf
*/

// Allouer et initialiser un missile
t_missile * creermissile(int *x,int *y){
    t_missile *missile;

    // Allouer
    missile=(t_missile *)malloc(1*sizeof(t_missile));

    // Initialiser

    missile->x = *x;
    missile->y = *y;

    missile->dx = 20;
    missile->dy = 0;
    missile->vivant=1;
    missile->coup=1;

    return missile;
}

void actualisermissile(t_missile *missile){//, t_ennemi *tab[NENNEMI1]){
//int i;
    // deplacement
    missile->x=missile->x+missile->dx;
    missile->y=missile->y+missile->dy;

    // si dépasse un bord alors disparait
    if ( missile->x>SCREEN_W)
        missile->vivant=0;


}

void dessinermissile(t_missile *missile){
    rectfill(img.page, missile->x, missile->y, missile->x+10, missile->y+10, makecol(50,0,255));

}


