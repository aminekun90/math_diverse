#ifndef DEF_DIVERSE
#define DEF_DIVERSE
#define CURL_STATICLIB
//#include <curl/curl.h>
//#include <curl/types.h>
//#include <curl/easy.h>

#include<iostream>
/* MinGW fournissait unistd.h, MSVC non : le projet n'a jamais visé MSVC. */
#ifndef _MSC_VER
#include <unistd.h>//sleep();
#endif
#include <stdio.h>/*Biblio*/
#include <stdlib.h>/*standards*/
#ifndef _WIN32
#include "platform/compat.h"
#endif
#ifdef _WIN32
#include <conio.h>/*entrée-sortie*/
#ifdef _WIN32
#include <windows.h>//system();
#else
#include "platform/compat.h"
#endif
#endif
#include <math.h>//pow();cos();sin();...
#include <string.h>//chaines de caractères
#define VER "1.06b"//version
#define VERP "1.06"//version sans b
#define JOUR printf("31 Ao%ct 2014",150);//Jour
#define LIMIT 10//taille limite matrice
#define TRUE 1 //vrai
#define FALSE 0 //faux
#define MAX 2600//Pour fact();
#define HAUT 80//
#define BAS  72//Pour les menu LOL ;)
#define OK 13//
using namespace std;
//prototype des fonctions
int main();
int menu();
void apropos(void);
int menueq();
int quitter();
//les équations
int eq1();
int eq2();
//determinant
int chckdgnl(float(*)[LIMIT],int);
float deter(float(*)[LIMIT],int);
void calcdet(void);
//trie de tableau
void tri_a_bulle(int*, int) ;
void tri_selection(int*, int);
void tri_permutation(int*, int);
void tri_insertion(int*, int);
void fusion(int*,int,int,int);
void tri_fusion_bis(int*,int,int);
void tri_fusion(int*,int);
void echanger(int*, int, int);
int partition(int*, int, int);
void tri_rapide_bis(int*, int,int);
void tri_rapide(int*,int);
int calctri(void);
//Autres
int menuautres();
void multiply(int);//factoriel très amélioré !! 2000!
void fact(int,int);
void premier();
//DL
int menudl();
int calcsin(void);
double fact2 (double);
//System couleur et heure
int gettime();
void color(int,int);//couleur de la console
//ecriture de fichiers
int wdeter(float(*)[LIMIT],int,float);
int weq(float,float,float,float,float,int);
int wtab(int*,int*,int,int);

void change();
//jeux
void menujeux();
/* Calculs ajoutes en 2026 */
int calcexp(void);
int calccos(void);
int calcln(void);
int pgcdppcm(void);
int conversion(void);
int stats(void);
int systeme2(void);

#endif
