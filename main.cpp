/*
Code source MathDiverse
main.c
diverse.c
diverse.h
Auteur: Mohamed Amine Bouzahar
Email: med.amine.b90@gmail.com
Twitter: @amineb90
Version 1.0.4.0 Beta
LICENCE MIT
*/

#include "diverse.h"
#include "snake/console.h"

using namespace std;
void SetWindow(int Width, int Height) 
    { 
    // Get console window handle
	HWND wh = GetConsoleWindow();

	// Move window to required position
	MoveWindow(wh, 100, 100, Width, Height, TRUE);
	
    }
    
int main() 
{
	setTitle("MathDiverse "VER"");
	SetWindow(800, 500);
color(2,15);
setCursorPos(0, 5);
	const char *screen[12] = {
		"+-----------------------------------------------------------------------------+",
        "|   ##     ## ########  #### ##     ## ######## ########   ######  ########   |",
        "|   ###   ### ##     ##  ##  ##     ## ##       ##     ## ##    ## ##         |",
        "|   #### #### ##     ##  ##  ##     ## ##       ##     ## ##       ##         |",
        "|   ## ### ## ##     ##  ##  ##     ## ######   ########   ######  ######     |",
        "|   ##     ## ##     ##  ##   ##   ##  ##       ##   ##         ## ##         |",
        "|   ##     ## ##     ##  ##    ## ##   ##       ##    ##  ##    ## ##         |",
        "|   ##     ## ########  ####    ###    ######## ##     ##  ######  ########   |",
		"+------------------------Par-HELLOW-DEV-----------------------------"VERP"beta--+",
	};

        	color(2,0);
		for(int line = 0; line < 12; ++line) {
			
		puts(screen[line]);
	 Sleep(50);
	 
	}	
Sleep(1000);

	system("mkdir txt");
	system("cls");
	color(14,0);
	setCursorPos(5, 10);
	printf("Bienvenu dans le nouveau MathDiverse %s B%cta Les menus ont %ct%c repens%cs\n",VERP,136,130,130,130);
    setCursorPos(6, 11);
    printf("D%csormet vous pouvez utiliser les fl%cches du clavier pour naviguer %c\n",130,138,1);
	setCursorPos(40, 22);
    changeColor(WHITE);
    printf("Appuyez sur [ENTREE] pour continuer.");
	getch();
	system("cls");
	int t[6]={10,15,15,12},done=1,i=0;
char choix=0;
while(done)
{
	label:
		color(7,0);
	 printf("�����������������������������������������ͻ\t\t");gettime();
	printf("\n�Mise %c Jour: ",133);JOUR;printf(" Version  %s.�",VER);
	printf("\n�����������������������������������������ͼ\n");
	 changeColor(WHITE);
	//printf("%d",i);
	setCursorPos(5, 10);
	printf("Que voulez Vous faire ?");
	setCursorPos(5, 11);
	color(t[0],0);
	printf("1-Calculer");
	color(t[1],0);
	setCursorPos(5, 12);
	printf("2-Jouer");
	color(t[2],0);
	setCursorPos(5, 13);
	printf("3-%c Propos.",183);
	color(t[3],0);
	setCursorPos(5, 14);
	printf("4-Quiter");
	setCursorPos(40, 22);
    changeColor(WHITE);
    printf("Appuyez sur [ENTREE] pour continuer.");
    setCursorPos(40, 23);
    printf("Ou sur [ESC] pour Quitter.");
    choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas z�ro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=3) {t[i]=15; i++;}
          /*la m�me chose avec haut*/
            t[3]=12;
			t[i]=10;   
			system("cls");//on bouge le  curseur dans le menu
          if(choix==27){done=0; quitter(); }
	if(choix==OK)//si l'utilisateur a cliqu� sur entre�
          {
	switch(i)
	{
	case 0:menu();goto label;break;
	case 1:menujeux();
	goto label;
	break;
	case 2:apropos();
	goto label;
	break;	
	case 3: quitter();break;	
	}
}
}
	
	return 0;
}

