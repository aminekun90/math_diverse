#include "cte.h"
#include "tictactoe.h"

/*****************************************************************
					Morpion Hellow DEV
 *****************************************************************/

int tictactoe()
{/*menu principale*/
    int w=0,t[3]={15,15,10},done=1,i=2,m=0;
    char choix=0;
    while(1){
       while(done){//tan que done est vari (tant que lutilisateur n'a pas cliqué sur entreé
          DEBUT/*on affiche le msg de l'aceuille*/
          /*puis le menu*/
          colort(t[2],0);printf("\t\t\t1-Partie un joueur\n");
          colort(t[1],0);printf("\t\t\t2-Partie deux jour\n");
          colort(t[0],0);printf("\t\t\t3-Quiter le jeu   \n");
          choix=getch();//on stock la touche pressé par l'utilisateur dans choix
          if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=2) {t[i]=15; i++;}
          /*la méme chose avec haut*/
            t[i]=10;   system("cls");//on bouge le  curseur dans le menu
          if(choix==OK)//si l'utilisateur a cliqué sur entreé
          {
              switch(i)
              {
                  case 2://si i=2 (le curseur etait sur le choix partie un joueur
                  done=0;
                  while(!done)
                  {
                  system("cls");
                  printf("\n\n\n\n\n\n\n\t\tqui commance??\n\t\t\t1->toi\n\t\t\t2->pc\n");
                  choix=getch()-48;
                  if(choix==1||choix==2){ m=2-choix; done=1;}
                  }
                  w=1;//on renvoi w & m
                  break;
                  case 1: w=0; break; //si il  a choisi partie 2joueurs
                  case 0:  return 0;break;//si il a choisi de quité on ferme le prog
              }
              done=0;//pour finir la boucle
          }

          }
  while(done!=2)
  {
              Jeu(w,m); done=0; system("cls");//on apelle la fonction jeu ol lui envoiant les 2 parametre que le joueur
                                              //a donné
              while(done==0)
              {
              printf("\n\n\n\n\n\n\t\t\tveux-tu recommancer?\?(o/n):");
              choix=getch();
              if(choix=='o') done=1;//on continuer le programe
              if(choix=='n'){ done=2;  colort(7,0);}//retoure au menu P
              system("cls");
              }
  }
}}


