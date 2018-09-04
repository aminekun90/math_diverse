#include <stdio.h>
#include <time.h>
#include "myconio.h"

#define    GAUCHE    75
#define    DROITE    77
#define    ENTER     13
#define    ESCAPE    27

int hasard(int max);

void Allumette()
{
	system("title Allumettes");
  int  increment;
  int  tour=1;
  int  enleve=0;
  int  difficulte=1;
  int  allumettes=6;
  char touche;

  textcolor(12);
  printf("LE JEU DES ALUMETTES\n\n");
  textcolor(14);
  printf("Voici un petit jeu ou devez prendre 1 2 ou 3\n");
  printf("allumettes, et le joueur qui prend la derniere\n");
  printf("allumette a perdu.");
  do
  {
    gotoxy(1,8);
    textcolor(14);
    printf("Nombre d'allumettes : ");
    textcolor(10);
    printf("%-2d",allumettes);
    touche=getch();
    if (touche==GAUCHE)
    {
      allumettes--;
      if (allumettes==5) allumettes=30;
    }
    if (touche==DROITE)
    {
      allumettes++;
      if (allumettes==31) allumettes=6;
    }
  } while (touche!=ENTER);
  do
  {
    gotoxy(1,9);
    textcolor(14);
    printf("Difficulte : ");
    textcolor(10);
    switch (difficulte)
    {
      case 1: printf("facile   ");
              break;
      case 2: printf("normal   ");
              break;
      case 3: printf("difficile");
              break;
    }
    touche=getch();
    if (touche==GAUCHE)
    {
      difficulte--;
      if (difficulte==0) difficulte=3;
    }
    if (touche==DROITE)
    {
      difficulte++;
      if (difficulte==4) difficulte=1;
    }
  } while (touche!=ENTER);
  clrscr();
  do
  {
    textcolor(10);
    for (increment=1 ; increment<=allumettes ; increment++)
    {
      gotoxy(increment*2,2);
      printf("\xDB");
      gotoxy(increment*2,3);
      printf("\xDB");
      gotoxy(increment*2,4);
      printf("\xDB");
    }
    if (tour==2)
    {
      textcolor(12);
      if (difficulte==1)
      {
        if (allumettes>3) enleve=hasard(3);
        else
        {
          if (allumettes==3) enleve=hasard(2);
          else enleve=1;
        }
      }
      if (difficulte==2)
      {
        switch (allumettes)
        {
          case 4:  enleve=3;
                   break;
          case 3:  enleve=2;
                   break;
          case 2:  enleve=1;
                   break;
          case 1:  enleve=1;
          default: enleve=hasard(3);
        }
      }
      if (difficulte==3)
      {
        enleve=0;
        increment=2;
        if (allumettes==1) enleve=1;
        while (enleve==0)
        {
          if (allumettes==increment+0) enleve=1;
          if (allumettes==increment+1) enleve=2;
          if (allumettes==increment+2) enleve=3;
          if (allumettes==increment+3) enleve=hasard(3);
          increment=increment+4;
        }
      }
      allumettes=allumettes-enleve;
      gotoxy(1,6);
      printf("L'ordinateur prend %d allumettes",enleve);
      tour=1;
    }
    else while (tour==1)
    {
      textcolor(14);
      gotoxy(1,7);
      printf("Combien d'allumettes voulez-vous prendre ? ");
      touche=getch();
      enleve=0;
      switch (touche)
      {
        case '1':  enleve=1;
                   tour=2;
                   break;
        case '2':  enleve=2;
                   tour=2;
                   break;
        case '3':  enleve=3;
                   tour=2;
                   break;
      }
      if (((enleve>=allumettes)&&(allumettes>1))||((enleve>1)&&(allumettes==1)))
      {
        gotoxy(1,7);
        if (allumettes==3) printf("Vous pouvez enlever maximum 2 allumettes ! ");
        else printf("Vous pouvez enlever maximum 1 allumette !  ");
        Sleep(2000);
        tour=1;
      }
      else allumettes=allumettes-enleve;
      if (tour==2) printf("%d",enleve);
      if (touche==ESCAPE) tour=2;
    }
    if (tour==1) textcolor(12);
    else textcolor(14);
    for (increment=1 ; increment<=enleve ; increment++)
    {
      gotoxy((increment*2)+(allumettes*2),2);
      printf("\xDB");
      gotoxy((increment*2)+(allumettes*2),3);
      printf("\xDB");
      gotoxy((increment*2)+(allumettes*2),4);
      printf("\xDB");
    }
    if (allumettes==0)
    {
      if (tour==2)
      {
        for (increment=10 ; increment<=14 ; increment++)
        {
          gotoxy(1,9);
          textcolor(increment);
          printf("##### ##### #   # #####  ##### #   # ##### #####\n");
          printf("#     #   # ## ## #      #   # #   # #     #   #\n");
          printf("#   # ##### # # # #####  #   # #   # ##### #####\n");
          printf("#   # #   # #   # #      #   #  # #  #     # #  \n");
          printf("##### #   # #   # #####  #####   #   ##### #  # \n");
          Sleep(200);
        }
        printf("\nC'est si dur que ca ?");
        getch();
      }
      else
      {
        for (increment=10 ; increment<=14 ; increment++)
        {
          gotoxy(1,9);
          textcolor(increment);
          printf("####  ##### ##### #   # #####\n");
          printf("#   # #   # #   # #   # #   #\n");
          printf("####  ##### ##### #   # #   #\n");
          printf("#   # # #   #   #  # #  #   #\n");
          printf("####  #  #  #   #   #   #####\n");
          Sleep(200);
        }
        if (difficulte==1) printf("\nMais en mode facile c'est pas dure !");
        if (difficulte==2) printf("\nPas mal, maintenant essayez en difficile !");
        if (difficulte==3) printf("\nBravo, vous avez reussi avec la plus haute difficulte !");
        getch();
      }
    }
  } while ((touche!=ESCAPE)&&(allumettes!=0));
}

/*DONNE UN NOMBRE AU HASARD DE 1 A max*/
int hasard(int max)
{
  int nombre;
  srand(time(NULL));
  nombre=rand() % max;
  nombre++;
  return nombre;
}
