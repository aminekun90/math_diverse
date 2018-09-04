#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include<conio.h>
#define CHANGE  x=t[pc][1];y=t[pc][2]
#define ERASE jeu[y/7][x/10]=0;
#define BOUGE_CURSEUR deplaser(map,&(*x),&(*y),
#define DOWN 0,LR+1)
#define UP 0,-LR-1)
#define LEFT -LaR-1,0)
#define RIGHT LaR+1,0)
#define som1 t[0][0]+t[1][1]+t[2][2]
#define som2 t[2][0]+t[1][1]+t[0][2]
#define som3 t[L][0]+t[L][1]+t[L][2]
#define som4 t[0][l]+t[1][l]+t[2][l]
#define LR  7
#define LaR 10
#define LM  (LR*3)+4
#define LaM (LaR*3)+4
#define GAGNE  printf("\n\n\n\n\n\n\n\n\n***********LE JOEUR %ld GAGNE************\n\n\n\n\n\n\n\n\n",((i%2)+1)*-1 + 3);donne=0;
#define EGALIT printf("\n\n\n\n\n\n\n\n\n************EGALITE!!!*************\n\n\n\n\n\n\n\n\n");donne=0;
#define DEBUT  colort(7,0);printf("*********BIENVENU DANS MORPION********\n\n\n\n\n\n\n\n\n\n\n");
#define HAUT 72
#define BAS  80
#define GAUCHE 75
#define DROIT 77
#define OK 13

#define CASE jeu[t[pc][2]/7][t[pc][1]/10]
#define CROIX  (i%2) + 4
#define ROND   ((i+1)%2) + 4
#define OBJ    ((i+s)%2) + 4

typedef struct Objet Objet ;
struct Objet{char t[LR][LaR];};


int genercoups(char map[][LaM],int jeu[][3],int t[10][3],int i,int s);
long genCor(long MIN  , long MAX );

void Utilisateur(char map[][LaM],int jeu[][3],int *x,int *y,int *i,Objet* tabl);

int Jeu(int,int);

void coler(char map[][LaM],int x,int y,char ini[][LaR]);
void Init(char map[][LaM],int x,int y,int ini);
void colort(int couleurDuTexte,int couleurDeFond);
void deplaser(char map[LM][LaM],int *x,int *y,int X,int Y);

int gagner(int t[][3]);
