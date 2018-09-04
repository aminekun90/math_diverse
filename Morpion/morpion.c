#include "cte.h"

int Jeu(int w,int m)
{

/************les VARIABLESSSSSSSSSSSSS*********/
          /*les deux image croix et rond*/
      Objet tabl[2];
           /* les deux map mode graph/nn graph*/
      char  map[LM][LaM]={NULL};
      int jeu[3][3]={NULL};
        /*    autres   */
      int t[10][3]={NULL};
      char ltr=0,pc=0;
          /* les conteurs */
      int L=0,l=0,i=0,n=1;
          /*les cordonnes du curseur*/
      int x=LaR+2,y=LR+2;
          /*les boolens*/
      long donne=1, gag=0,perd=0;

FILE* file = NULL;

    file = fopen("data.dll", "w+");
	/*if (file == NULL)
	{*/
fprintf(file,"00000000000110000110001100110000011110000011001100011000011000000000000000000000044444444004400004400440000440044000044004444444400000000000");
fclose(file);
file = fopen("data.dll", "r");
colort(0,15);system("cls");
while(i!=2)
{
while(L!=LR)
{
    while(l!=LaR)
    {tabl[i].t[L][l]=fgetc(file)-48;l++;}l=0;L++;//crois->tabl[0].t & rond->tabl[1].t
}L=0;l=0;
i++;
}
fclose(file);
/*}else
{
	colort(7,15);
	printf("Error");
	getch();
	system("cls");
}*/
l=1;L=1;
i=0;
while(L!=LM)/* puis il faut dessiner la map*/
{
    while(l!=LaM)
    {
        t[n][1]=l; t[n][2]=L;
        n++;
        Init(map,l,L,1);
        if(l==x && L==y)Init(map,l,L,2);
        l+=(LaR+1);
    }L+=(LR+1);l=1;
}
/********************DEBUT DE LA BOUCLE PRINCIPALE************/
while(donne)
{
l=0;L=0;
colort(7,1);
printf("*JOUEUR %ld*\n",(i%2)+1);
while(L!=LM)
{/*affichage*/
  colort(0,15); printf("\t\t  ");
    while(l!=LaM)
    {
        switch(map[L][l]){
            case  0: colort(3,3); break;
            case  1: colort(7,7); break;
            case  3: colort(8,8); break;
            case  4: colort(2,2); break;
            case  2: colort(2,2); break;
            default: colort(4,4); break;}
printf(" ");l++;
        }
    printf("\n");l=0; L++;
}

colort(0,15);

/**************1  :  TOUR DU PC*******************/
//si w est vrai(si lutilisateur a choisi mode 1joueur)
if(w)
{
//on entre dans le mode joeurvsordi
if(i%2==m)//si c'est le tour du pc(i est un conteur de tours ->i%2=(1 ou 0)
          //bon on gros si i%2==m(1ou0 c'est le joueur qui a chosis o debut)
{
 Init(map,x,y,-2);
 pc=genercoups(map,jeu,t,i,0);
 if(gagner(jeu)!=1){CASE=0; pc=genercoups(map,jeu,t,i,3);}
 CHANGE;
 Init(map,x,y,2);
 coler(map,x,y,tabl[i%2].t); i++;
}
else Utilisateur(map,jeu,&x,&y,&i,tabl);//else c'est le tour du joueur
}

else  Utilisateur(map,jeu,&x,&y,&i,tabl);//si w est fausse c a dire si lutilisateur a demandé
/*bon on regarde si quelqu'un a gagner*/                                         //partie 2joueurs*/
if(gagner(jeu)!=1&&gagner(jeu)!=2)
{
system("cls");}
else{

     if(gagner(jeu)==1){
     	colort(12,15);
     	printf("Termin%c !!",130);
     	getch();
     	system("cls");
     	colort(0,15);
	 GAGNE Sleep(1000);
	 }
else if(gagner(jeu)==2){
	colort(12,15);
	printf("Termin%c !!",130);
	getch();
	system("cls");
	colort(0,15);
EGALIT Sleep(1000);}
}
}

}



