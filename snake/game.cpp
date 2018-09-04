#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include<conio.h>
#include "game.h"
#include "menu.h"
#include "console.h"
#include "snake.h"
#include "apple.h"
#include "wall.h"
#include "../diverse.h"
using namespace std;

void StartGame()
{
	clearConsole();
	 int t[5]={10,15,15,15,15},coul=0,done=1;
        char choice;
        // Vitesse
	int moveSpeed = 200;//Facile
	// Taille du serpent
	int snakeSize = 5;
	
	
	 
         while (done)
        { 
        // Titre
        setCursorPos(7, 1);
        cout << "Snake Console - Hellow-dev - ";
        cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © (ou pas)";
        
        	//cout<<coul;
        // Choix
        setCursorPos(3, 4);
        cout << " Difficult"<<char(130)<< endl;
        setCursorPos(3, 5);
        color(t[0],0);
        cout << " 1) Facile"<< endl;
        setCursorPos(3, 6);
        color(t[1],0);
        cout << " 2) Moyen" << endl;
        setCursorPos(3, 7);
        color(t[2],0);
        cout << " 3) Difficile "<< endl;
        setCursorPos(3, 8);
        color(t[3],0);
        cout << " 4) Impossible" << endl;
         color(t[4],0);
        setCursorPos(3, 9);
        cout << " 5) Retour" << endl;
	
        
       
        	
        	choice=getch();
        	if(choice==72  && coul!=0) {t[coul]=15; coul--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choice==80 && coul!=4) {t[coul]=15; coul++;}
          /*la méme chose avec haut*/
            
			t[coul]=10;   
			clearConsole();//on bouge le  curseur dans le menu
          if(choice==27){done=0; quitter(); }
        	
        	if(choice==13)
        	{
        
		        	switch(coul)
		        {
		        	//1-facile
		            case 0:moveSpeed = 200;
					snakeSize = 5;
				done=0;
					break;
					//2-Moyen
		        	case 1:moveSpeed = 100;
					snakeSize = 5;
					done=0;
					break;
		        	//3-Difficile
		        	case 2:moveSpeed = 50;
					snakeSize = 6;
					done=0;
					break;
		        	//4-Impossible
		        	case 3:moveSpeed = 0;
					snakeSize = 10;
					done=0;
					break;
					//4-Retour
					case 4:
						done=0;
						ShowMenu();
				
					break;
		        }
        	}
    }
    clearConsole();
	for(int counter=3;counter>=1;counter--)
		          {
		           
			      	system("cls");
			      	 changeColor(GREEN);
			      setCursorPos(30, 13);
			       cout<<"Le jeu commence dans "<<counter;
			       changeColor(WHITE);
			       setCursorPos(15, 15);
			    cout << "utiliser les touches " << char(24)<<" "<<char(25)<<" "<<char(26)<<" "<<char(27) << " pour d" << char(130) << "riger le serpent ";
				
			       	 setCursorPos(30, 16);
			       	 cout<<"Et [ESCAPE] pour Quitter";
					   Sleep(1000);
		            	
		          }
    // Invulnerabilité
    bool invulnerable = false;
    int timeLeft = 0;
    int invulColor = GREY;
    
    // Score
    long score = 0;
    
    // Statistiques
    int fruit = 0;
    int bonus = 0;
    
    // Position principale
    int snakeX = 10;
    int snakeY = 10;
    
    // Mouvement actuel
    int snakeMoveX = 1;
    int snakeMoveY = 0;
    bool hasMoved = false;
    
    

    // Liste des points
    vector<int> snakePosX(snakeSize);
    vector<int> snakePosY(snakeSize);

    // Liste des obstacles
    int mapObject[78][25] = {0};

    // Position de la pomme actuelle
    int appleX = 0;
    int appleY = 0;
    int appleLenght = 0;
    int bonusType = 0;

    // Initialisation
    clearConsole();
    initSnake(snakeX, snakeY, snakeSize, snakePosX, snakePosY);
    
    // Texte
    setCursorPos(7, 1);
    cout << "Snake Console - Hellow-dev - ";
    cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © [ESC] pour Quitter";
    
    // Génération des obstacles de base
    generateWallBase(mapObject);
    generateRandomWalls(mapObject, snakePosX, snakePosY, 20);
    
    // Génération de la pomme
    GenerateApple(&appleX, &appleY, &bonusType, &appleLenght, snakeSize, snakePosX, snakePosY, mapObject);
    
    while (1)
    {
        // Enregistrement de la dernière position
        
        int tempX = snakePosX.back();
        int tempY = snakePosY.back();
        
        // Gestion de l'invicibilité
        
        if (invulnerable)
        {
            timeLeft--;
            invulColor = GREY;
            switch(timeLeft)
            {
               case 16:
               case 12:
               case 8:
               case 4:
                    colorSnake(GREEN, snakeSize, snakePosX, snakePosY);
                    invulColor = GREEN;
                    break;
               case 14:
               case 10:
               case 6:
               case 2:
                    colorSnake(GREY, snakeSize, snakePosX, snakePosY);
                    break;
               case 0:
                    invulnerable = false;
                    colorSnake(GREEN, snakeSize, snakePosX, snakePosY);
                    break;
            }
        }
        
        // Décalage
        
        for (int i = snakeSize - 1; i > 0 ; i--) 
        {
            snakePosX.at(i) = snakePosX.at(i - 1);
            snakePosY.at(i) = snakePosY.at(i - 1);
        }
        
        // Mouvement principal
        
        snakeX += snakeMoveX;
        snakeY += snakeMoveY;
        
        snakePosX.front() = snakeX;
        snakePosY.front() = snakeY;
        
        // Effacement
        
        if (!isSnake(tempX, tempY, snakeSize, snakePosX, snakePosY))
        {
            setCursorPos(tempX, tempY);
            if ( mapObject[tempX][tempY] == 2 )
            {
               changeColor(WHITE);
               cout << "#";
            } else {
               cout << " ";       
            }
               
        }
        
        // Vérification d'une colision
        
        if ( mapObject[snakeX][snakeY] == 1 )
        {
           GameOver(score, fruit, bonus);
           return;
        }   
        if ( (mapObject[snakeX][snakeY] == 2) && !invulnerable )
        {
           GameOver(score, fruit, bonus);
           return;
        }   
        if (isSnake(snakeX, snakeY, snakeSize, snakePosX, snakePosY) && !invulnerable)
        {
           GameOver(score, fruit, bonus);
           return;
        }
        
        // Vérification de la pomme
        
        if ((snakeX == appleX) && (snakeY == appleY))
        {
            
            if (appleLenght < 0)
            {
               for (int i = 1; i < abs(appleLenght) + 1; i++)
               {
                   setCursorPos(snakePosX.at(snakeSize - i), snakePosY.at(snakeSize - i));
                   cout << " ";
               }
               bonus++;
            }
            else if (bonusType != 0)
            {
                bonus++;
                switch (bonusType)
                {
                    case 1:
                         moveSpeed += 20;
                         if (moveSpeed > 130)
                            moveSpeed = 130;
                         break;
                            
                    case 2:
                         moveSpeed -= 20;
                         if (moveSpeed < 30)
                            moveSpeed = 30;
                         break;
                         
                    case 3:
                         invulnerable = true;
                         timeLeft = 150;
                         colorSnake(GREY, snakeSize, snakePosX, snakePosY);
                         break;
                }
                
            } else {
              fruit++;
            }
            
            snakeSize += appleLenght;
            
            snakePosX.resize(snakeSize, 0);
            snakePosY.resize(snakeSize, 0);
            
            // Augmentation du score
            score += abs(appleLenght) * 100 + bonusType * 150 + snakeSize * 10;
            
            GenerateApple(&appleX, &appleY, &bonusType, &appleLenght, snakeSize, snakePosX, snakePosY, mapObject);
        }
        
        // Affichage
        
        if (!invulnerable)
           changeColor(GREEN);
        else
           changeColor(invulColor);
        setCursorPos(snakePosX.at(1), snakePosY.at(1));
        cout << "o";
        setCursorPos(snakePosX.front(), snakePosY.front());
        cout << "O";
        
        // Attente et vérification du clavier
        
        hasMoved = false;
        for (int i = 1; i <= 3; i++)
        {
            checkMove(&snakeMoveX, &snakeMoveY, &hasMoved);
            Sleep(moveSpeed / 3);
        }
        
        // +1 Score
        score++;
                
    }
    done=1;
   ShowMenu(); 
}
