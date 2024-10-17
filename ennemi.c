///Ici sont gérés les ennemis et le tableau d'ennemis
#include "utilitaire.h"
#include "ennemi.h"
#include "defenses.h"
/// Sources
/*
Extraits de code récupérés de la page sur le site de Mr Fercoq :
https://fercoq.bitbucket.io/allegro/
-TP4 Gestion Acteurs et Animation
https://fercoq.bitbucket.io/allegro/tp4/tp4_etape4.zip
https://fercoq.bitbucket.io/allegro/tp4/allegro_tp4.pdf
*/
t_ennemi * creerennemi(int *speed)
{
    t_ennemi*ennemi;
    ennemi =(t_ennemi *)malloc(1*sizeof(t_ennemi));

    do{
        ennemi->posx = rand()%((2000) + 800);
    }while(ennemi->posx<SCREEN_W);
    do{
        ennemi->posy = rand()%(435 + 105);
    }while(ennemi->posy<=105);
    ennemi->depx =*speed;
    ennemi->depy = 0;
    ennemi->imgcourante = 0;
    ennemi->vivant=1;
    ennemi->ptvie=1;
    ennemi->tmpimg=4;
    ennemi->cptimg=0;
    ennemi->tx=100;
    ennemi->ty=106;

    return ennemi;
}


void remplirTabEnnemis(t_ennemi * tab[NENNEMI1],int *speed)
{
    int i;
    for (i=0;i<NENNEMI1;i++)
            {
                tab[i]=creerennemi(speed);
            }
}

void actualiserEnnemis(t_ennemi *ennemi,int *gameover)
{
// actu ennemi pos x et y
    /// Trajectoire
    ennemi->posx = ennemi->posx + ennemi->depx;
    ennemi->posy = ennemi->posy + ennemi->depy;

    if(ennemi->posx-ennemi->tx==0)
    {
        *gameover=1;
    }
        ennemi->cptimg++;
        if (ennemi->cptimg>=ennemi->tmpimg){
            ennemi->cptimg=0;

    ennemi->imgcourante++;
    if ( ennemi->imgcourante==NIMAGE )
        ennemi->imgcourante = 0;}

}


void actualiserTabEnnemis(t_ennemi * tab[NENNEMI1],int *gameover,int*fin)
{
    int i;
    for (i=0; i<NENNEMI1; i++)
    {
        if(tab[i]->vivant==0)
    {
        *fin=*fin+1;
    }
    actualiserEnnemis(tab[i],gameover);
    }


}

void dessinerEnnemis(t_ennemi *ennemi,BITMAP *animation[NIMAGE])
{
    draw_sprite(img.page,animation[ennemi->imgcourante], ennemi->posx,ennemi->posy);
}



void dessinerTabEnnemis( t_ennemi * tab[NENNEMI1], BITMAP *animation[NIMAGE]){
    int i;
    for (i=0; i<NENNEMI1; i++)
        dessinerEnnemis(tab[i],animation);
}

// Enlever et libèrer un ennemi qui était dans la liste en indice i
void enleverennemi(t_ennemi *tab[NENNEMI1]){


    // Vérifier qu'il y a bien un ennemi accroché en indice i
    if (tab[NENNEMI1]!=NULL)
    {
        // libérer la mémoire du ennemi
        free(tab[NENNEMI1]);

        // marquer l'emplacement comme libre
        tab[NENNEMI1]=NULL;

    }
}
