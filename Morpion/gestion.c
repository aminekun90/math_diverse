#include "cte.h"
void deplaser(char map[LM][LaM],int *x,int *y,int X,int Y)
{
    Init(map,*x,*y,-2);
    *y+=Y;
    *x+=X;
    Init(map,*x,*y,2);
}
void Init(char map[][LaM],int x,int y,int ini)
{
   int L=0,l=0;
    while(L!=LR)
    {while(l!=LaR){map[y+L][x+l]+=ini;l++;}L++;l=0;}
}

void colort(int T,int F)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,F*16+T);
}

void coler(char map[][LaM],int x,int y,char ini[][LaR])
{
 int L=0,l=0;
    while(L!=LR)
    {while(l!=LaR){map[y+L][x+l]+=ini[L][l];l++;}L++;l=0;}
}
int gagner(int t[][3])
{
   int E=0,l=0,L=0,somt=0;

 while(L!=3){
if((som3==12||som3==15)||(som4==12||som4==15)||(som1==12||som1==15)||(som2==12||som2==15))E=1;
    somt+=som3;
    L++;l++;
}
if(somt==40 && !E)E=2;
return E;
}
long genCor(long MIN  , long MAX )
{
     long nM=0;
srand(time(NULL));
nM = (rand() % (MAX - MIN + 1)) + MIN;
return nM ;
}
int genercoups(char map[][LaM],int jeu[][3],int t[10][3],int i,int s)
{
int pc=0,d=1,q=0,gag;
    while(d)
    {
        do{pc++;}while(CASE!=0);
        q++;
        CASE=OBJ;
        if(gagner(jeu)!=0 || q==9-i){ d=0; gag=gagner(jeu);}
        CASE=0;
    }
    if(!gag) do{ pc=genCor(1,9); }while(CASE!=0);
     CASE=CROIX;
   return pc;
}

void Utilisateur(char map[][LaM],int jeu[][3],int *x,int *y,int *i,Objet *tabl)
{
/*tour du joueur*/
 char ltr=getch();//on stock la touche pressé pas ce dernier

 if( ltr==BAS && *y!=(LR*2)+3 )   BOUGE_CURSEUR DOWN ;
 if( ltr==HAUT && *y!=1 )         BOUGE_CURSEUR UP ;
 if( ltr==DROIT && *x!=(LaR*2)+3) BOUGE_CURSEUR RIGHT ;
 if( ltr==GAUCHE && *x!=1 )       BOUGE_CURSEUR LEFT ;
 if( ltr==13 && map[*y+1][*x+1]==3 ){
 jeu[*y/7][*x/10]=(*i%2) + 4;
 coler(map,*x,*y,tabl[*i%2].t);
*i+=1; }
 }
