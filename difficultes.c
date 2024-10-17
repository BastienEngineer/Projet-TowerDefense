/*
Voici nos difficultés :

-> Associer missile à la defense 1 (magicien)

-> Ennemi disparait lors d'une collision

-> Fichier Niveaux deja débloqué

-> Ennemis gardent la meme position apres le retour au menu

-> Ennemis aurait du être en liste d'ennemis

-> peut-être l'emploi d'une bitmap intercalaire aurait aidé pour faire des get pixel (stratégie envisagée) abandonné pour cause de maîtrise médiocre
Finalement c'est un problème de choix



*/
/*
Code que nous avons testé lors du jeu mais nous avions pas réussi (bon algorithme)


    if(base1->cas==3)
    {
        if(base1->x/2==ennemi->posx/2 && base1->y/2==ennemi->posy/2)
        {
            ennemi->vivant=0;
        }
    }

// Actualiser une defense(fin explosion)
///Arranger selon comment tu fais exploser la mine
void actualiserDefense(t_base *defense){

    // si en cours d'explosion incrémenter cptexplo
    // et si explose depuis trop longtemps alors disparait
    if (defense->comportement==1)
    {
        defense->cptexplo++;
        if (defense->cptexplo > 7)
            defense->vivant=0;
    }
}
///Pour supprimer une défense explosée en libérant la mémoire
void enleverDefense(t_listeDef *la, int i)
{
    ///On teste si l'emplacement est vide
    if(la->tab[i]!=NULL)
    {
        ///On libère la mémoire
        free(la->tab[i]);
        ///On libère l'emplacement dans le tableau
        la->tab[i]=NULL;
        la->n--;
    }
}
///Pour changer les statuts
///Et pour enlever une défense explosée
void actualiserListeDefenses(t_listeDef *la, int x, int y, int type)
{
    int i;


    for (i=0;i<la->max;i++)
        if (la->tab[i]!=NULL)
        {
            ///Modifie le statut d'une défense
            actualiserDefense(la->tab[i]);
            if(!la->tab->vivant)
            {
                ///Libère la mémoire et met la case à NULL libérant
               enleverDefense(la,i);
            }
        }
}

// sauvegarde Fichier

while(retourmenu!=1)
{
     if(mouse_x>300 && mouse_x<473 && mouse_y<160 && mouse_y>100)
            {
            stop_sample(img.son);
            quitter();           /// niveau=1 (nouvelle partie)
            niv=lireniveau();   /// Affichage du niveau par fichier de sauvegarde
            clear(screen);
            }
    if(mouse_x>300 && mouse_x<475 && mouse_y<237 && mouse_y>180)  /// Regles
            {
            stop_sample(img.son);
            niv=lireniveau();   /// charge partie sauvegardé (niv=1 || niv=2 || niv=3)
            }
                while(retourmenu!=1)
                {
                    if(niv==1)  /// Niveau 1
                        {

                            if(fin==1)
                            {
                            /// Vague 1
                            actualiserTabEnnemis(mesEnnemis1,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis1,img.animation1);
                            actualiserTabEnnemis(mesEnnemis2,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis2,img.animation2);
                            actualiserTabEnnemis(mesEnnemis3,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis3,img.animation3);
                            }
                            if(fin==2)
                            {
                            /// Vague 2
                            actualiserTabEnnemis(mesEnnemis4,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis4,img.animation1);
                            actualiserTabEnnemis(mesEnnemis5,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis5,img.animation2);
                            actualiserTabEnnemis(mesEnnemis6,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis6,img.animation3);
                            }
                            if(fin==3)
                            {
                            /// Vague 3
                            actualiserTabEnnemis(mesEnnemis7,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis7,img.animation1);
                            actualiserTabEnnemis(mesEnnemis8,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis8,img.animation2);
                            actualiserTabEnnemis(mesEnnemis9,&gameover,&fin);
                            dessinerTabEnnemis( mesEnnemis9,img.animation3);
                            }

                            if(key[KEY_ESC] || jouer==0)  /// Retour menu
                                    {
                                        jouer=0;
                                        retourmenu=1;
                                    }
                                    if(gameover==1)    /// Ennemis arrivent à l'objectif
                                        {
                                            //fond=load_bitmap_check("images/loose1.bmp");
                                            blit(nar.gameover1,img.page,0,0,0,0,800,600);
                                            blit(img.page,screen,0,0,0,0,800,600);
                                            rest(4000);

                                            blit(nar.gameover2,img.page,0,0,0,0,800,600);
                                            blit(img.page,screen,0,0,0,0,800,600);
                                            rest(5000);
                                            jouer=0;
                                            retourmenu=1;
                                        }

                                if(fin==4)  /// 4eme vague -> sauvegarde niveau niv=niv+1 (incremente)
                                    {
                                        save_niveau(niv);
                                        //fond=load_bitmap_check("images/win1.bmp");
                                            blit(nar.win1,img.page,0,0,0,0,800,600);
                                            blit(img.page,screen,0,0,0,0,800,600);
                                            rest(4000);
                                            blit(nar.win2,img.page,0,0,0,0,800,600);
                                            blit(img.page,screen,0,0,0,0,800,600);
                                            rest(5000);
                                            jouer=0;
                                            retourmenu=1;
                                    }
                            blit(img.page,screen,0,0,0,0,800,600);
                            rest(20);

                            }
                            stop_sample(img.son1);

                        }
                    if(niv==2)   // niveau2
                        {

                            blit(nar.niv2,screen,0,0,0,0,800,600);
                            rest(20);
                            if(key[KEY_SPACE])
                            {
                            clear(screen);
                            play_sample(img.son1, 200, 128, 1000, 1);
                            jouer=1;
                            }
                            //niveauDeux(); /// meme systeme que jouer (vagues + poser defenses)
                        }
                    if(niv==3)  // niveau3
                        {

                            blit(nar.niv3,screen,0,0,0,0,800,600);
                            rest(20);
                            if(key[KEY_SPACE])
                            {
                            clear(screen);
                            play_sample(img.son1, 200, 128, 1000, 1);
                            jouer=1;
                            }

                            //niveauTrois();
                        }
                    if(key[KEY_ESC])                       /// retour au menu principale
                    {
                        clear(screen);
                        retourmenu=1;
                    }
                }

            }




*/

