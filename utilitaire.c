///Ici est regroupé l'ensemble des sous-programmes essentiels à lancer allegro et ses fonctions redondantes
///Lire Niveau sert à gérer les fichiers pour la sauvegarde de même que quitter
///Save_niveau et sauvegarde servent à pouvoir accéder au jeu pour reprendre à l'instant t
///charger_image_son et charger_Narration servent à définitivement déclarée les structure t_image img et t_Narration
///Regles et MenuInterface sont 2 sous-programmes "d'affichage" et non deux fonctions purement affiliées aux mécanismes du jeu
#include "utilitaire.h"


t_Narration nar;

void lancerToutAllegro(int largeur, int hauteur)
{
    allegro_init();
    install_keyboard();
    install_mouse();

    /// OUVERTURE MODE GRAPHIQUE (ouverture fenêtre allegro)
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,NULL);

}

BITMAP * load_bitmap_check(char *nomImage)
{
    BITMAP *bmp;
    bmp=load_bitmap(nomImage,NULL);
    if (!bmp)
    {
        allegro_message("pas pu trouver %s",nomImage);
        exit(EXIT_FAILURE);
    }
    return bmp;
}
int lireniveau()
{
    int nivx;
        FILE *f;
        int get = 1;

        if((f = fopen("niveaux.txt", "r")) == NULL)
                {
                    get = 0;
                }
        if(get == 1)
                {
                    fscanf(f, "%d", &nivx);
                }
        fclose(f);
        return nivx;
}
void quitter()
{
        int niv=1;
        FILE *f;
        int get =1;

        if((f=fopen("niveaux.txt", "w")) == NULL)
                {
                    get = 0;
                }
        if(get==1)
                {
                   fprintf(f, "%d", niv);
                }
        fclose(f);

}
void save_niveau(int nivx)
{
        FILE *f;
        int get =1;

        if((f = fopen("niveaux.txt", "w")) == NULL)
            {
                    get = 0;
                    printf("ERREUR SAUVEGARDE NIVEAUX");
            }
        if(get==1)
            {
                    fprintf(f, "%d", nivx+1);
            }
        fclose(f);
}
void sauvegarde(int nivx)
{
        FILE *f;
        int get =1;

        if((f = fopen("niveaux.txt", "w")) == NULL)
            {
                    get = 0;
                    printf("ERREUR SAUVEGARDE NIVEAUX");
            }
        if(get==1)
            {
                    fprintf(f, "%d", nivx);
            }
        fclose(f);
}

void charger_image_son()
{
    img.page=create_bitmap(SCREEN_W,SCREEN_H);
    img.defense=create_bitmap(SCREEN_W,SCREEN_H);
    img.son=load_wav("sons/ost.wav");
    img.son1=load_wav("sons/jeu.wav");
    img.menu=load_bitmap_check("images/menu.bmp");
    img.base=load_bitmap_check("images/w.bmp");
    img.id=load_bitmap_check("images/nain.bmp");
    img.mine1=load_bitmap_check("images/mur.bmp");
    img.mine2=load_bitmap_check("images/fire.bmp");
    img.menuHaut=load_bitmap_check("images/interface.bmp");
    ///Les images sont des exemples mais libres de droits, je garde les liens ;)
    img.exit1=load_bitmap_check("images/porte.bmp");
     int i,j,k;
    char nomfichier[256];

         for (i=0;i<NIMAGE;i++)
    {
        sprintf(nomfichier,"images/s%d.bmp",i);
        img.animation1[i] = load_bitmap(nomfichier, NULL);
        if (!img.animation1[i])
        {
            allegro_message("pas pu trouver %s", nomfichier);
            exit(EXIT_FAILURE);
        }
    }
    for (k=0;k<NIMAGE;k++)
    {
        sprintf(nomfichier,"images/dragon%d.bmp",k);
        img.animation3[k] = load_bitmap(nomfichier, NULL);
        if (!img.animation1[k])
        {
            allegro_message("pas pu trouver %s", nomfichier);
            exit(EXIT_FAILURE);
        }
    }
     for (j=0;j<NIMAGE;j++)
    {
        sprintf(nomfichier,"images/g%d.bmp",j);
        img.animation2[j] = load_bitmap(nomfichier, NULL);
        if (!img.animation2[j])
        {
            allegro_message("pas pu trouver %s", nomfichier);
            exit(EXIT_FAILURE);
        }
    }
}

void charger_Narration()
{
    nar.regle1=load_bitmap_check("images/regles1.bmp");
    nar.regle2=load_bitmap_check("images/regles2.bmp");
    nar.niv1=load_bitmap_check("images/debutNiv1.bmp");
    nar.niv2=load_bitmap_check("images/debutNiv2.bmp");
    nar.niv3=load_bitmap_check("images/debutNiv3.bmp");
    nar.gameover1=load_bitmap_check("images/loose1.bmp");
    nar.gameover2=load_bitmap_check("images/loose2.bmp");
    nar.win1=load_bitmap_check("images/win1.bmp");
    nar.win2=load_bitmap_check("images/win2.bmp");
}

void regles()
{
    int valeur=0;

    while(!key[KEY_ESC])
    {
        if(valeur==0)
        {
            blit(nar.regle1, screen,0,0,0,0,800,600);
        }
        if(key[KEY_SPACE])
        {
            valeur=1;
        }
        if(valeur==1)
        {

            blit(nar.regle2, screen,0,0,0,0,800,600);
        }
    }
}

///Pour afficher l'interface du joueur
///Devra recevoir les BITMAPs des défenses et des bitmaps de l'attaque à voir si on veut défendre comme ça, (un perso jdr éventuellement pour id joueur), un Exit en pancarte?
void menuInterface()
{
    masked_blit(img.id, img.menuHaut,0,0,0,0, 100, 100);
    masked_blit(img.base, img.menuHaut, 0,0,100,0, 100, 100);
    masked_blit(img.mine1, img.menuHaut,0,0,300,0, 100, 100);
    masked_blit(img.mine2, img.menuHaut,0,0,500,0, 100, 100);
    masked_blit(img.exit1, img.menuHaut,0,0,700,0, 100, 100);

}



