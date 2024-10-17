///Page de tests effectués pour la hitbox des défenses
///Non fonctionnel sans doute à cause de la gestion des ennemis avec plusieurs structures ennemi et des tableaux
/*
#include "utilitaire.h"
#include "ennemi.h"
#include "listemissile.h"
#include "defenses.h"


void testEnnemi(t_ennemi * ennemi, t_listeDef *test)
{
    int i;


    for(i=0; i<test->max; i++)
    {
        ///test d'abord la position en x sur le bord droit d'une défense
        if(ennemi->posx==(test->tab[i]->x+test->tab[i]->tx))
        {
            ///test en y
            if(((ennemi->posy)<(test->tab[i]->y+test->tab[i]->ty)&&(ennemi->posy>test->tab[i]->y))||(((ennemi->posy+ennemi->ty)<(test->tab[i]->y+test->tab[i]->ty))&&((ennemi->posy+ennemi->ty)>(test->tab[i]->y))))
            {
                if(test->tab[i]->cas==3)
                {
                    ennemi->ptvie=0;
                    test->tab[i]->vivant=0;
                }
                if(test->tab[i]->cas==1)
                {
                    ennemi->ptvie-2;
                }
                if(test->tab[i]->cas==2)
                {
                    ennemi->ptvie--;
                }
            }
        }
    }

}

///Test à partir des ennemis
void CollisionAll(t_listeDef *test, t_ennemi * tab[NENNEMI1])
{
    int i;
    for (i=0; i<NENNEMI1; i++)
    {
        testEnnemi(tab[i],test);
        if(tab[i]->vivant==0)
        {
            actualiserEnnemis(tab[i],0);
        }
    }
}

*/
