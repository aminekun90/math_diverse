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

using namespace std;

void StartGame()
{
	int moveSpeed = 200;//facile
	int snakeSize = 5;
	char ch;
	cout<<"Difficult"<<(char)130<<"??"<<endl;
	cout<<"1-Facile"<<endl;
	cout<<"2-Moyen"<<endl;
	cout<<"3-Difficile"<<endl;
	cout<<"4-Impossible"<<endl;
	ch=getch();
	switch(ch)
	{
	case '1': 
	moveSpeed = 200;//facile
	snakeSize = 5;
		break;
	case '2': 
		moveSpeed = 100;
		snakeSize = 5;
		break;
	case '3': 
		moveSpeed = 50;
		snakeSize = 6;
		break;
	case '4': 
		 moveSpeed = 1;
		 snakeSize = 10;
		break;
	}
    // Vitesse
    
    
    // Taille du serpent
    
    
    
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
    cout << "Tous droits r" << char(130) << "serv" << char(130) << "s © (ou pas)";
    
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
    
}
