#ifndef MISSILE_H_INCLUDED
#define MISSILE_H_INCLUDED

typedef struct missile
{
    int x,y;
    int dx,dy;
    int coup;
    int vivant;

} t_missile;


// missile
t_missile * creermissile(int *x,int *y);
void actualisermissile(t_missile *missile);//,t_ennemi *tab[NENNEMI1]);
void dessinermissile(t_missile *missile);
#endif // MISSILE_H_INCLUDED
