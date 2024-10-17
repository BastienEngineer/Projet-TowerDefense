///Sert � g�rer plusieurs missiles
#include "utilitaire.h"
#include "listemissile.h"
/// Sources
/*
Extraits de code r�cup�r�s de la page sur le site de Mr Fercoq :
https://fercoq.bitbucket.io/allegro/
-TP4 Gestion Acteurs et Animation
https://fercoq.bitbucket.io/allegro/tp4/tp4_etape4.zip
https://fercoq.bitbucket.io/allegro/tp4/allegro_tp4.pdf
*/

t_listemissiles * creerListemissiles(int maxmissiles){
    t_listemissiles *missile;
    int i;

    missile=(t_listemissiles *)malloc(1*sizeof(t_listemissiles));

    missile->max=maxmissiles;
    missile->n=0;
    missile->tab=(t_missile **)malloc(maxmissiles*sizeof(t_missile*));

    for (i=0;i<maxmissiles;i++)
        missile->tab[i]=NULL;

    return missile;
}

// Retourne un bool�en vrai si il reste de la place
// dans la liste, faux sinon
int libreListemissiles(t_listemissiles *la){
    return la->n < la->max;
}

// Allouer et ajouter un missile � la liste
// et retourner l'adresse de ce missileeau missile
// retourne NULL en cas de probl�me

t_missile * ajoutermissile(t_listemissiles *la,int *x,int *y){
    int i;
    t_missile *missile;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (la->n >= la->max)
        return NULL;

    // Allouer un missile initialis�
    missile=creermissile(x,y);

    // Chercher un emplacement libre
    i=0;
    while (la->tab[i]!=NULL && i<la->max)
        i++;

    if (i<la->max){
        ///Association d'un missile � un emplacement
        la->tab[i]=missile;
        la->n++;
    }
    ///Si jamais on rencontre un probl�me
    else
        allegro_message("Anomalie gestion ajoutermissile : liste corrompue");

    return missile;
}

///Supprimer un missile "explos�" du tableau en lib�rant la m�moire allou�e et en mettant � NULL la case du tableau
void enlevermissile(t_listemissiles *la,int i){

    ///On ne l'actualise que si il y a un missile au moins pr�sent
    if (la->tab[i]!=NULL)
    {
        free(la->tab[i]);
        la->tab[i]=NULL;
        la->n--;

    }
}

/// G�rer l'�volution de l'ensemble des missiles successivement
void actualiserListemissiles(t_listemissiles *la){
    int i;

    ///Si le missile est en place on actualise sa position
    ///Si le statut vivant n'est pas v�rifi� on l'enl�ve
    for (i=0;i<la->max;i++)
        if (la->tab[i]!=NULL){
            actualisermissile(la->tab[i]);
            if (!la->tab[i]->vivant){
                enlevermissile(la,i);
            }
        }
}

void dessinerListemissiles(BITMAP *bmp,t_listemissiles *la){
    int i;

    for (i=0;i<la->max;i++)
        if (la->tab[i]!=NULL)
            dessinermissile(la->tab[i]);

}




