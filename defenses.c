///L'id�e �tait de donner des PV aux d�fenses c'est en ce sens qu'on a employ� le code r�serv� aux acteurs
#include "utilitaire.h"
#include "defenses.h"
/// Sources
/*
Extraits de code r�cup�r�s de la page sur le site de Mr Fercoq :
https://fercoq.bitbucket.io/allegro/
-Acteurs en quantit� variable et collision
https://fercoq.bitbucket.io/allegro/Alleg_C3/2_0_acteurs_en_quantite_variable.html
https://fercoq.bitbucket.io/allegro/Alleg_C3/2_1_acteurs_en_quantite_variable.html

-TP4 Gestion Acteurs et Animation
https://fercoq.bitbucket.io/allegro/tp4/tp4_etape4.zip
https://fercoq.bitbucket.io/allegro/tp4/allegro_tp4.pdf
*/

t_images img;

///Sert � allouer par rapport � l'entier taille la pose de d�fenses
t_base * CreerDefense(int x, int y, int cas)
{
    t_base * nouv=NULL;
    ///Allouer
    nouv = (t_base *)malloc(1*sizeof(t_base));

    ///Position associ�e � la nouvelle structure
    nouv->x=x;
    nouv->y=y;
    ///Le type de base
    nouv->cas = cas;
    ///Valeur par d�faut
    nouv->vivant=1;
    ///Pour la taille de bitmap ou la zone � check
    nouv->tx=100;
    nouv->ty=100;

    ///Association du missile/boule de mana question de perspective au mage
    if(nouv->cas == 1)
    {
        nouv->missile->x;
        nouv->missile->y;
    }

    return nouv;
}

///Sert au d�but avant la boucle de jeu avec un tableau de taille d�finie dans le main
t_listeDef * creerListeDef(int maxacteurs)
{
    t_listeDef *nouv;
    int i;

    nouv=(t_listeDef *)malloc(1*sizeof(t_listeDef));

    nouv->max=maxacteurs;
    nouv->n=0;
    nouv->tab=(t_base **)malloc(maxacteurs*sizeof(t_base*));

    for (i=0; i<maxacteurs; i++)
        nouv->tab[i]=NULL;

    return nouv;
}

void AfficherDefenser(t_listeDef *defenses, int posx, int posy, int cas, int taille)
{
    ///Blindage de la position avec retour d'un entier
                                                ///Cr�er une d�fense
                                                ajouterDef(defenses, posx, posy, cas);
                                                if(defenses->tab[taille-1]==NULL)
                                                {
                                                    if(cas==1)
                                                    {
                                                        draw_sprite(img.defense,img.base,mouse_x-50, mouse_y-150);
                                                    }
                                                    if(cas==2)
                                                    {
                                                        draw_sprite(img.defense,img.mine1,mouse_x-50, mouse_y-150);
                                                    }
                                                    if(cas==3)
                                                    {
                                                        draw_sprite(img.defense,img.mine2,mouse_x-50, mouse_y-150);
                                                    }

                                                }
}

///Pour appeler CreerDefense celui qui est appel� de la boucle de jeu
t_base * ajouterDef(t_listeDef *la,int x,int y,int type)
{
    int i;
    t_base *acteur;

    ///Est un blindage emp�chant un exc�s d'ennemis
    if (la->n >= la->max)
        return NULL;

    ///On peut creer une nouvelle d�fense
    acteur=CreerDefense(x,y,type);

    ///On cherche � placer cette defense dans le tableau de pointeurs
    i=0;
    while (la->tab[i]!=NULL && i<la->max)
        i++;

    ///C'est un deuxi�me test pour v�rifier le placement d'une d�fense nouvelle dans une case vide du tableau
    if (i<la->max)
    {
        ///L'acteur prend une place dans le tableau
        la->tab[i]=acteur;
        la->n++;
    }
    ///Afficher une erreur �ventuelle
    else
        allegro_message("Anomalie gestion ajouterActeur : liste corrompue");

    return acteur;
}

///Lib�rer la listeDef en fin de niveau
void enleverListeDef(t_listeDef *la)
{
    int i;

    ///On teste si l'emplacement est vide
    for(i=0; i<la->max; i++)
    {
        free(la->tab[i]);
        la->tab[i]=NULL;
        la->n--;
    }
}



