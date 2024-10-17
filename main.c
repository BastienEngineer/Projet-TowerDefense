#include "utilitaire.h"
#include "ennemi.h"
#include "listemissile.h"
#include "defenses.h"

/// Sources
/*
Extraits de code récupérés de la page sur le site de Mr Fercoq :
https://fercoq.bitbucket.io/allegro/

-Acteurs en quantité variable et collision
https://fercoq.bitbucket.io/allegro/Alleg_C3/2_0_acteurs_en_quantite_variable.html
https://fercoq.bitbucket.io/allegro/Alleg_C3/2_1_acteurs_en_quantite_variable.html
-Cours 5 (Factoriser le code)
https://fercoq.bitbucket.io/allegro/notes/alleg_cours_5_chap_1_et_2.pdf
-TP4 Gestion Acteurs et Animation
https://fercoq.bitbucket.io/allegro/tp4/tp4_etape4.zip
https://fercoq.bitbucket.io/allegro/tp4/allegro_tp4.pdf

Images :
https://nielscoueffe.files.wordpress.com/2014/05/mur.jpg
https://image.freepik.com/free-vector/landscape-background-with-river-trees_1196-602.jpg?3
https://image.freepik.com/vecteurs-libre/ghost-enemies-jeux-sprites_7814-477.jpg
https://www.spriters-resource.com/download/43902/
https://celcliptipsprod.s3-ap-northeast-1.amazonaws.com/tips_article_body/ab13/550569/2d70ed25eb4cb85d3488d18febf5f9d0
https://i.pinimg.com/originals/ef/48/d2/ef48d217dc8e23a49277afc4dcf403c3.png
https://www.pngkit.com/png/detail/8-89026_wizard-simple-drawing-png-wizard-sprite.png
https://cdnb.artstation.com/p/assets/images/images/005/731/017/original/david-bautista-fire.gif?1493342833https://www.publicdomainpictures.net/fr/view-image.php?image=90938&picture=eglise-porte-vintage
https://www.piqsels.com/en/public-domain-photo-swssj
https://pbs.twimg.com/profile_images/1166610806705987584/jvsb5MhA_400x400.jpg
http://labandeasimplette.l.a.pic.centerblog.net/fzqgn2hk.jpg
http://www.penofchaos.com/warham/bd/images/fondecran-chiantos-16001200.jpg
https://www.pexels.com/fr-fr/photo/ancien-antiquite-arriere-plan-art-235985/

Disclaimer :
L'utilisation de la licence Naheulbeuk et des illustrations liées à cette licence n'ont aucune fin de diffusion massive.


Sons :
https://youtu.be/gEDeHHD_faw
https://youtu.be/q6nDogAgd6M
*/

t_images img;
t_Narration nar;



int main(int argc, char *argv[])
{
    /// Parametres du menu
    int niv=0;
    int jouer=0;
    int gameover=0;
    int fin=1;
    int jeu=0;
    int retourmenu=0;
    /// Parametre vagues ennemis
    int speed=-1;
    int speed2=-2;
    int speed3=-3;
    ///Temporisation souris
    int click=0;
    ///Pour sélectionner une défense ou la sortie
    int cas=0;
    ///Taille des tableaux
    int taille=20;
    //int taile2=10;
    //int taille3=8;
    /// en fct des niveaux

    ///Pour récupérer les coordonnées
    int posx,posy;
    /// INITIALISATION ALLEGRO
    lancerToutAllegro(800,600);
    t_ennemi * mesEnnemis1[NENNEMI1];
    t_ennemi * mesEnnemis2[NENNEMI1];
    t_ennemi * mesEnnemis3[NENNEMI1];
    t_ennemi * mesEnnemis4[NENNEMI2];
    t_ennemi * mesEnnemis5[NENNEMI2];
    t_ennemi * mesEnnemis6[NENNEMI2];
    t_ennemi * mesEnnemis7[NENNEMI3];
    t_ennemi * mesEnnemis8[NENNEMI3];
    t_ennemi * mesEnnemis9[NENNEMI3];
    t_listemissiles* missiles;
    t_listeDef * defenses;


    BITMAP *fond;
    charger_image_son();
    charger_Narration();
    show_mouse(screen);
    /// AVANT BOUCLE
    blit(img.menu,screen,0,0,0,0,800,600);
    play_sample(img.son, 200, 128, 1000, 1);
    remplirTabEnnemis(mesEnnemis1,&speed);
    remplirTabEnnemis(mesEnnemis2,&speed);
    remplirTabEnnemis(mesEnnemis3,&speed);
    remplirTabEnnemis(mesEnnemis4,&speed2);
    remplirTabEnnemis(mesEnnemis5,&speed2);
    remplirTabEnnemis(mesEnnemis6,&speed2);
    remplirTabEnnemis(mesEnnemis7,&speed3);
    remplirTabEnnemis(mesEnnemis8,&speed3);
    remplirTabEnnemis(mesEnnemis9,&speed3);
    missiles=creerListemissiles(1);
    defenses=creerListeDef(taille);
    clear_to_color(img.defense, makecol(255, 0, 255));

/// Boucle de Jeu
    while(jeu==0)
    {
        if(mouse_b&1)
        {
            if(mouse_x>300 && mouse_x<473 && mouse_y<160 && mouse_y>100)
            {
                stop_sample(img.son);
                niv=lireniveau();   /// Affichage du niveau par fichier de sauvegarde
                clear(screen);
                while(retourmenu!=1)
                {
                    if(niv==1)  /// Niveau 1
                    {

                        //fond=load_bitmap_check("images/debutNiv1.bmp");
                        blit(nar.niv1,screen,0,0,0,0,800,600);
                        rest(20);
                        if(key[KEY_SPACE])
                        {
                            clear(screen);
                            play_sample(img.son1, 200, 128, 1000, 1);
                            jouer=1;
                        }
                        while(jouer==1)
                        {
                            fond=load_bitmap_check("images/decorniv1.bmp");
                            ///Afficher l'interface
                            ///Afficher le terrain
                            ///Aficher sur la bitmap et le terrain
                            blit(fond,img.page,0,0,0,0,800,600);
                            menuInterface();
                            draw_sprite(img.page,img.menuHaut,0,0);
                            draw_sprite(img.page, fond, 0, 100);
                            draw_sprite(img.page, img.defense, 0, 100);
                            // bouger tout le missile
                            actualiserListemissiles(missiles);
                            // afficher tout le missile
                            dessinerListemissiles(img.page,missiles);
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

                            ///Placement base opérationnel, affichage ///appels de sous-programme de défenses
                            ///Ne marchait plus en tant que sous programme GestionSouris donc réintégré ici
                            if(mouse_b&1)
                            {
                                if(click==0) ///Pour temporiser la vitesse de la souris
                                {
                                    {


                                        ///Cas où on doit placer une base (ne marche que si une des zones est sélectionnée (conditions des if suivants)
                                        ///Ici seulement (*cas)!=0 doit avoir des modifications pour les sprites
                                        if((cas)!=0 && mouse_y>100)
                                        {
                                            if((cas)==1)
                                            {
                                                ///A envoyer pour créer la défense après avoir vérifier le placement
                                                posx=mouse_x;
                                                posy=mouse_y;
                                                AfficherDefenser(defenses, posx, posy, cas, taille);
                                                ajoutermissile(missiles,&posx,&posy);
                                            }
                                            if((cas)==2)
                                            {
                                                ///A envoyer pour créer la défense après avoir vérifier le placement
                                                posx=mouse_x;
                                                posy=mouse_y;
                                                AfficherDefenser(defenses, posx, posy, cas, taille);

                                            }
                                            if((cas)==3)
                                            {
                                                ///A envoyer pour créer la défense après avoir vérifier le placement
                                                posx=mouse_x;
                                                posy=mouse_y;
                                                AfficherDefenser(defenses, posx, posy, cas, taille);
                                            }
                                        }

                                        ///Pour Quitter
                                        if(mouse_x>700 && mouse_x<800 && mouse_y<100)
                                        {
                                            jouer=0;
                                        }

                                        ///Pour Placer une base on la sélectionne avant tout donc ici on change seulement (cas)
                                        if(mouse_x<200 && mouse_x>100 && mouse_y<100)
                                        {
                                            (cas)=1;
                                        }
                                        if(mouse_x<400 && mouse_x>300 && mouse_y<100)
                                        {
                                            (cas)=2;
                                        }
                                        if(mouse_x<600 && mouse_x>500 && mouse_y<100)
                                        {
                                            (cas)=3;
                                        }



///Pour organiser la Gestion en cas de besoin (prévu mais non développé)
                                        /*
                                                            if(mouse_x<300 && mouse_x>200 && mouse_y<100)
                                                            {
                                                                printf("\n\n\n\t\t\tOn est dans la Def 1\n\n\n");
                                                            }
                                                            if(mouse_x<500 && mouse_x>400 && mouse_y<100)
                                                            {
                                                                printf("\n\n\n\t\t\tOn est dans la Def 2\n\n\n");
                                                            }
                                                            if(mouse_x<700 && mouse_x>600 && mouse_y<100)
                                                            {
                                                                printf("\n\n\n\t\t\tOn est dans la Def 3\n\n\n");
                                                            }
                                        */
                                    }
                                    click=1;
                                }

                            }
                            else if(!mouse_b&1)
                            {
                                click=0;
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
                    if(niv==2)
                    {
                        /*
                        blit(nar.niv2,screen,0,0,0,0,800,600);
                        rest(20);
                        if(key[KEY_SPACE])
                        {
                        clear(screen);
                        play_sample(img.son1, 200, 128, 1000, 1);
                        jouer=1;
                        }*/
                        //niveauDeux();
                    }
                    if(niv==3)
                    {
                        /*
                        blit(nar.niv3,screen,0,0,0,0,800,600);
                        rest(20);
                        if(key[KEY_SPACE])
                        {
                        clear(screen);
                        play_sample(img.son1, 200, 128, 1000, 1);
                        jouer=1;
                        }
                        */
                        //niveauTrois();
                    }
                    if(key[KEY_ESC])                       /// retour au menu principale
                    {
                        clear(screen);
                        retourmenu=1;
                    }
                }

            }

            if(mouse_x>300 && mouse_x<475 && mouse_y<237 && mouse_y>180)  /// Regles
            {
                stop_sample(img.son);
                clear(screen);
                regles();
                /*
                //fond=load_bitmap_check("images/regles1.bmp"); /// Regles
                blit(fond,screen,0,0,0,0,800,600);
                rest(10000);
                clear(screen);
                //fond=load_bitmap_check("images/regles2.bmp"); /// Regles
                blit(fond,screen,0,0,0,0,800,600);
                rest(1000);
                */
                while(retourmenu!=1)
                {
                    if(key[KEY_ESC])                       /// retour au menu principale
                    {
                        clear(screen);
                        retourmenu=1;
                    }
                }
            }
            if((mouse_x>300)&&(mouse_x<475)&&(mouse_y>260)&&(mouse_y<310)) /// Quitter
            {
                stop_sample(img.son);
                jeu=1;
                quitter();
            }
            retourmenu=0;
            blit(img.menu,screen,0,0,0,0,800,600);
            play_sample(img.son, 200, 128, 1000, 1);
            rest(20);
        }
    }
    destroy_sample(img.son); ///Enleve son
    return 0;
}
END_OF_MAIN();
