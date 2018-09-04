#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>
#include "../diverse.h"
#include "menu.h"
#include "game.h"
#include "console.h"

using namespace std;
void slapsh_screen(void) {
	clearConsole();
	changeColor(GREEN);
	const char *screen[12] = {
		"+-----------------------------------------------------------------------------+",
		"|                                                               	      |",
		"|               _______  _        _______  _        _______     	      |",
        "|              (  ____ \\( (    /|(  ___  )| \\    /\\(  ____ \\	     	      |",
        "|              | (    \\/|  \\  ( || (   ) ||  \\  / /| (    \\/	     	      |",
        "|              | (_____ |   \\ | || (___) ||  (_/ / | (__       	     	      |",
        "|              (_____  )| (\\ \\) ||  ___  ||   _ (  |  __)     	     	      |",
        "|                    ) || | \\   || (   ) ||  ( \\ \\ | (        	     	      |",
        "|              /\\____) || )  \\  || )   ( ||  /  \\ \\| (____/\\HELLOW-DEV        |",
        "|              \\_______)|/    )_)|/     \\||_/    \\/(_______/  	     	      |",
		"|                                                                	      |",
		"+-----------------------------------------------------------------------------+",
	};

	for(int line = 0; line < 12; ++line) {
		puts(screen[line]);
	 Sleep(50);
	}
setCursorPos(40, 22);
    changeColor(WHITE);
    printf("Appuyez sur [ENTREE] pour continuer.");	
getch();
Sleep(500);
	ShowMenu();
}
int ShowMenu()
{

    
    bool ContinueGame = true;
     
    while (ContinueGame)
    {
    
       char choice;
        clearConsole();
        int t[4]={10,15,15,12},i=0,done=1;
         while(done)
{ 
system("cls");
        // Titre
        setCursorPos(7, 1);
        cout << "Snake Console - Hellow-dev - ";
        cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © (ou pas)";
            
               
   
        // Choix
        color(t[0],0);
        setCursorPos(3, 4);
        cout << " 1) Nouvelle Partie"<< endl;
        color(t[1],0);
        setCursorPos(3, 5);
        cout << " 2) Aide" << endl;
        color(t[2],0);
        setCursorPos(3, 6);
        cout << " 3) Retour "<<(char)133<<" MathDiverses" << endl;
        color(t[3],0);
        setCursorPos(3, 7);
        cout << " 4) Quitter" << endl;
        
        // Traitement du clavier

        
        
        
        		choice=getch();
        	if(choice==72  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choice==80 && i!=3) {t[i]=15; i++;}
          /*la méme chose avec haut*/
            t[3]=12;
			t[i]=10;   
			clearConsole();//on bouge le  curseur dans le menu
          //if(choice==27){done=0; quitter(); }
        if (choice==OK)
        {
       
        	//cout<<choice;
        	switch(i)
        	{
        	
            
            case 0:
		            	clearConsole();
		     
		            	changeColor(WHITE);
		               StartGame();
		               break;
		    case 1:system("cls");
			InfoGame();
		               break;
		               
		            
		    case 2:system("cls");
		            	
		            
		               ContinueGame = false;
		            	//menu();
		            	system("start Mathdiverse.exe");
						exit(0);
		               break;
		    case 3:system("cls"); 
					quitter();
		               
		               ContinueGame = false;
		              
		            break;
		           
            }
            
             }
        
    }

    }
    
}

void InfoGame()
{
	system("cls");
     
    // Titre
    setCursorPos(7, 1);
    cout << "Snake Console  - Hellow-dev - ";
    cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © (ou pas)";
     
    // Informations
    setCursorPos(0, 4);

    cout << " Le but du Snake est de ramasser le plus de fruit." << endl;
    cout << " Pour d" << char(130) << "placer le serpent, vous devez utiliser";
    cout << " les touches fl" << char(130) << "ch" << char(130) << "s." << endl; 
    cout << " Vous ne devez ni toucher les murs, ni vous m" << char(136) << "me, mais attention :" << endl;
    cout << " Le serpent grandit " << char(133) << " chaque fois qu'il mange un fruit !" << endl << endl;

    cout << "  ----  " << endl << endl;
    
    cout << " Bonus         Taille gagn" << char(130) << "e" << endl;
    changeColor(BLUE);
    cout << "    .               1~2" << endl;
    cout << "    +               3~4" << endl;
    cout << "    %               5~6" << endl << endl;
    changeColor(WHITE);
    cout << " Bonus         Effet" << endl;
    changeColor(YELLOW);
    cout << "    !               Taille diminu" << char(130) << "e de 1 " << char(133) << " 5" << endl;
    cout << "    *               Vitesse du jeu augment" << char(130) << "e" << endl;
    cout << "    $               Vitesse du jeu diminu" << char(130) << "e" << endl;
    cout << "    I               Invincible un court moment" << endl;
    
    getch();
     
}

void GameOver(long score, int fruit, int bonus)
{
     
    clearConsole();
    
    // Titre
    setCursorPos(7, 1);
    cout << "Snake Console - Hellow-dev - ";
    cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © (ou pas)";
    
    // Score
    setCursorPos(30, 5);
    changeColor(RED);
    cout << "GAME OVER";
    
    changeColor(WHITE);
    setCursorPos(0, 8);
    cout << "   Score : ";
    changeColor(GREEN);
    cout << formatNumber(score) << endl << endl;
    
    changeColor(WHITE);
    cout << "   Nombre de fruit mang" << char(130) << " : ";
    changeColor(BLUE);
    cout << fruit << endl;
    changeColor(WHITE);
    cout << "   Nombre de bonus attrap" << char(130) << " : ";
    changeColor(YELLOW);
    cout << bonus << endl;
    setCursorPos(40, 22);
    changeColor(WHITE);
    printf("Appuyez sur [ENTREE] pour continuer.");
    getch();
    
}
