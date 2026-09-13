#include "diverse.h"
#include "tetris.h"
#include "snake/menu.h"
#include "Morpion/tictactoe.h"
#include "alumette.h"
#include"snake/console.h"
//char f[1001][MAX]={"1"};

char n[MAX]="1";
int quitter()
{
	setTitle("MathDiverse " VER "");
	system("cls");
			printf("\n%c bient%ct !%c\n\nLe programme va quitter tout seul patientez.",183,147,1);
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");

			exit(0);//quitter
	return 0;   /* la fonction est declaree int : sans return, comportement indefini */
}
int menu()
{
system("title MathDiverse");
	int t[7]={10,15,15,15,15,15,12},done=1,i=0;
	char choix=0;
	 while(done)
	 {
	 	color(7,0);
	printf("╔═════════════════════════════════════════╗\t\t");gettime();
	printf("\n║Mise %c Jour: ",133);JOUR;printf(" Version  %s.║",VER);
	printf("\n╚═════════════════════════════════════════╝\n");
	color(10,0);
	printf("==================MENU===================\n");
	color(10,0);printf("\t\t\t\t\t*\n");
	color(15,0);
	printf("Choisissez:");color(10,0);printf("\t\t\t\t*\n");printf("\t\t\t\t\t*\n");color(t[0],0);
	printf("===>1:D%cterminant d'une matrice.",130);color(10,0);printf("\t*\n");printf("\t\t\t\t\t*\n");color(t[1],0);
	printf("===>2:Menu des %cquations.",144);color(10,0);printf("\t\t*\n");printf("\t\t\t\t\t*\n");color(t[2],0);
	printf("===>3:Trie de Tableau.");color(10,0);printf("\t\t\t*\n");printf("\t\t\t\t\t*\n");color(t[3],0);
	printf("===>4:Autres Calculs.");color(10,0);printf("\t\t\t*\n");printf("\t\t\t\t\t*\n");color(t[4],0);
	printf("===>5:D%cveloppement Limitee.",130);color(10,0);printf("\t\t*\n");printf("\t\t\t\t\t*\n");color(t[5],0);
	printf("===>6:Retour.");color(10,0);printf("\t\t\t\t*\n");printf("\t\t\t\t\t*\n");
	color(t[6],0);
	printf("===>[ESCAPE]:Quitter.");color(10,0);printf("\t\t\t*\n");printf("\t\t\t\t\t*\n");

	printf("=========================================");
	color(15,0);
	choix=getch();

	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/

          if(choix==HAUT && i!=6) {t[i]=15; i++;}

          /*la méme chose avec haut*/
           t[6]=12; t[i]=10;
		   system("cls");
			//on bouge le  curseur dans le menu
			//printf("%d",i);
			if(choix==27){done=0; quitter(); }
	if(choix==OK)
	{
	switch(i)
	{
		case 0:
		system("cls");
			calcdet();
			system("cls");
			menu();
		break;
		case 1:
	system("cls");
		menueq();
		break;
		case 2:
			system("cls");
		calctri();
		system("cls");
		menu();
		break;
		case 3:
		system("cls");
		menuautres();
		break;
		case 4:
				system("cls");
			menudl();
		break;
		case 5:
			system("cls");

			break;

		case 6:
			system("cls");
			quitter();
		break;


	}//switch
	done=0;//pour arrêter la boucle
		}//ifOK


	}//While


	return 0;   /* la fonction est declaree int : sans return, comportement indefini */
}
int menueq()
{
	system("title Menu Equations");
	int t[5]={10,15,15,15,12},done=1,i=0;
char choix=0;
while (done)
{

	color(10,0);
	printf("\n\n=================MENU %cquation===================\n",144);printf("\t\t\t\t\t\t*\n");
	color(15,0);
	printf("Choisissez:");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[0],0);
	printf("===>1:%cquations premier degre.",144);
	color(10,0);
	printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[1],0);
	printf("===>2:%cquations deuxieme degre.",144);
	color(10,0);
	printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[2],0);
	printf("===>3:Syst%cme 2x2 (Cramer).",138);
	color(10,0);
	printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[3],0);
	printf("===>4:Retour.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[4],0);
	printf("===>[ESCAPE]:Quitter.");
	color(10,0);
	printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*");

	color(10,0);
	printf("\n=================================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          if(choix==HAUT && i!=4) {t[i]=15; i++;}
           t[4]=12; t[i]=10;
		   system("cls");
			if(choix==27){done=0; quitter(); }
	if(choix==OK)
	{

	switch(i)
	{
		case 0:
			system("cls");
			eq1();
		break;
		case 1:
			system("cls");
			eq2();
		break;
		case 2:
			system("cls");
			systeme2();
			system("pause");
			system("cls");
			menueq();
		break;
		case 3:
			system("cls");
			menu();
		break;
		case 4:
			quitter();
		break;
		default:
			printf("\nError 01\n\a");
			system("pause");
			system("cls");
			menueq();
		break;
	}//Switch
	done=0;
	}//If
}//while
	return 0;
}

int eq1()
{
	system("title Equation de premier degré");
float a,b,result;

system("cls");
printf("\nVotre Equation est sous la forme ax+b=0");
printf("\nDonnez a ensuite b\n");
scanf("%f%f",&a,&b);
printf("a=%0.f ; b=%0.f",a,b);

/* Corrige deux bugs d'origine :
   - result n'etait affecte que si b != 0, et etait affiche non initialise
     dans tous les autres cas ;
   - le message confondait les trois cas degeneres. Avec a != 0 et b == 0,
     la solution est x = 0, ce n'est pas une erreur. */
if (a == 0)
{
	color(12,0);
	if (b == 0)
		printf("\n0 = 0 : tout reel est solution.\n");
	else
		printf("\n%0.f = 0 est impossible : aucune solution.\n", b);
	color(15,0);
	system("pause");
	system("cls");
	menueq();
	return 0;
}

result = (-b) / a;
printf("\nLe resultat est : %f\n",result);
weq(a,b,0,result,0,1);//weq(a,b,c,x1,x2,param);
system("pause");
system("cls");
menueq();
}

int eq2()
{
	system("title Equation de deuxième degré");
	system("cls");
	printf("\nVotre Equation est sous la forme: ax^2+bx+c=0\n");
	float a,b,c,d,x1,x2;
	printf("Donner a et b et c:\n");
	scanf("%f%f%f",&a,&b,&c);
	printf("\na=%0.f ; b=%0.f ; c=%0.f\n",a,b,c);
	/* a == 0 : ce n'est plus une equation du second degre, et 2*a au
	   denominateur diviserait par zero. */
	if (a == 0)
	{
		color(12,0);
		printf("\na vaut 0 : l'equation est du premier degre.\n");
		color(15,0);
		system("pause");
		system("cls");
		eq1();
		return 0;
	}

	d=pow(b,2)-4*a*c;
	if(d>0)
	{
		printf("\nLes solution reelles:\n");
		color(14,0);
		x1=(-b+sqrt(d))/(2*a);   /* et non /2*a : (x/2)*a n'est pas x/(2a) */
		x2=(-b-sqrt(d))/(2*a);
		printf(" \nx1=%f\nx2=%f\n\n",x1,x2);
			weq(a,b,c,x1,x2,2);//weq(a,b,c,x1,x2,param);
		color(15,0);
	}else if(d<0)
	{
		printf("\nSolutions Complexe:\n\n");
		color(14,0);
		printf("x1=(-(%0.f)-i%f)/%0.f\n",b,sqrt(-d),2*a);
		printf("x2=(-(%0.f)+i%f)/%0.f\n\n",b,sqrt(-d),2*a);
		weq(a,b,c,sqrt(-d),0,3);//weq(a,b,c,x1,x2,param);
		color(15,0);
	}else
	{

		printf("\nSolution Unique:\n");
		color(14,0);
		printf("   %f\n\n",-b/(2*a));
		x1=-b/(2*a);
		weq(a,b,c,x1,0,4);//weq(a,b,c,x1,x2,param);
		color(15,0);
	}

	system("pause");
	system("cls");
	menueq();
	return 0;   /* la fonction est declaree int : sans return, comportement indefini */
}
void calcdet(void)
{
	system("title Déterminant d'une Matrice");
	float a[LIMIT][LIMIT],temp[LIMIT][LIMIT],value;
  int i,j,order;
  printf("Taille de votre matrice :");
  scanf("%d",&order);
  for(i=0;i<order;i++)
  {
 for(j=0;j<order;j++)
 {
   printf("La case [%d,%d]:",i+1,j+1);
   scanf("%f",&a[i][j]);
   temp[i][j]=a[i][j];
 }
  }
  printf("\nVotre Matrice :\n");
for(i=0;i<order;i++)
  {
  	printf("|");
 for(j=0;j<order;j++)
 {
   printf("%0.f|",a[i][j]);

 }
printf("\n");
  }
  if(chckdgnl(a,order)==0)
  {value=0;}
  else
  {value=deter(a,order);}
  color(14,0);
  printf("Le Determinent est : %0.f",value);
  color(15,0);
  wdeter(temp,order,value);
  getch();
}
float deter(float a[][LIMIT],int forder)
{
  int i,j,k;
  float mult;
  float deter=1;
  for(i=0;i<forder;i++)
  {
 for(j=0;j<forder;j++)
 {
   mult=a[j][i]/a[i][i];
   for(k=0;k<forder;k++)
   {
  if(i==j) break;
  a[j][k]=a[j][k]-a[i][k]*mult;
   }
 }
  }
  for(i=0;i<forder;i++)
  {
 deter=deter*a[i][i];
  }
  return(deter);
}


int chckdgnl(float array[][LIMIT],int forder)
{
  int i,j,k;
  for(i=0;i<forder;i++)
  {
  if(array[i][i]==0)
  {
  for(j=0;j<forder;j++)
  {
    if(array[i][j]!=0)
    {
    k=j;
    break;
    }
    if(j==(forder)) //forder-1
    return(0);
  }
  for(j=0;j<forder;j++)
  {
    array[j][i]=array[j][i]-array[j][k];
  }
  }
  }
  return(1);
}

void tri_a_bulle(int *t, int n)
{
int k=n;
int j   = 0;
int tmp = 0;
int en_desordre = 1;
	while(en_desordre)
	{
		en_desordre = FALSE;
		for(j = 0 ; j < k- 1 ; j++)
		 {
			 if(t[j] > t[j+1])
			 {
				 tmp = t[j+1];
				 t[j+1] = t[j];
				 t[j] = tmp;
				 en_desordre = TRUE;
			 }
 		}
		 k=k-1;  //version optimisé
 	}
 }
// tri par sélection
void tri_selection(int *t, int n)
{
int i, min, j , tmp;
	for(i = 0 ; i < n - 1 ; i++)
	{
		min = i;
		for(j = i+1 ; j < n ; j++)
		if(t[j] < t[min])
		 min = j;
		 if(min != i)
		 {
			 tmp = t[i];
			 t[i] = t[min];
			  t[min] = tmp;
		  }

	}

}

// tri par permutation
void tri_permutation(int *t, int n)
{
	int i,s=0,k;
	int nb[n];
	int res [n];
	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)
		{
			if(t[i]>t[k]) s++;
		    nb[i]=s;
		}
		res[s]=t[i];
		s=0;
	}
	for( i=0;i<n;i++)
		t[i]=res[i];
}

// tri par insertion
void tri_insertion(int *t, int n)
{
	int i,p,j;    int x;
    for (i = 1; i < n; i++)
	{
		x = t[i];
		p = i-1;
		while (t[p] > x && p-- > 0) {}
		p++;
		for (j = i-1; j >= p; j--)
		{
		 t[j+1] = t[j];
		}
		t[p] = x;
	}
}

// tri par fusion
void fusion(int *t,int deb1,int fin1,int fin2)
{
	int *table1;
	int deb2=fin1+1;
	int compt1=deb1;
	int compt2=deb2;
	int i;
	table1=(int *)malloc((fin1-deb1+1)*sizeof(int));
	for(i=deb1;i<=fin1;i++)
	table1[i-deb1]=t[i];
	for(i=deb1;i<=fin2;i++)
	{
		if (compt1==deb2) break;
			else if (compt2==(fin2+1))
					{
						t[i]=table1[compt1-deb1];
						compt1++;
						}
							else if (table1[compt1-deb1]<t[compt2])
							{
								t[i]=table1[compt1-deb1];
								compt1++;
							}
								else
								{
									t[i]=t[compt2];
									compt2++;
								}
	}    free(table1);
}

void tri_fusion_bis(int *t,int deb,int fin)
{
	if (deb!=fin)
	{
		int milieu=(fin+deb)/2;
		 tri_fusion_bis(t,deb,milieu);
		 tri_fusion_bis(t,milieu+1,fin);
		 fusion(t,deb,milieu,fin);
	}
}
void tri_fusion(int *t,int n)
{
	if (n>0) tri_fusion_bis(t,0,n-1);
}
// tri rapide
void echanger(int *t, int i, int j)
{
	int tmp;
	tmp=t[i];
	t[i]=t[j];
	t[j]=tmp;
}
int partition(int *t, int deb, int fin)
{
	int compt=deb;
	int pivot=t[deb];
	int i;
    for(i=deb+1;i<=fin;i++)
	{
		if(t[i]<pivot)
		{
			compt++;
			echanger(t,compt,i);
		}
	}
	echanger(t,compt,deb);
	return(compt);
}
void tri_rapide_bis(int *t, int debut,int fin)
{
	if(debut<fin)
	{
		int pivot=partition(t,debut,fin);
		tri_rapide_bis(t,debut,pivot-1);
		tri_rapide_bis(t,pivot+1,fin);
	}
}
void tri_rapide(int *t,int n)
{
	tri_rapide_bis(t,0,n-1);
}

 /* Fin de la définition des fonctions de tri */

 /* Saisie robuste d'un entier.
   scanf("%d") laisse le caractere fautif dans le tampon quand la lecture
   echoue : le rappeler dans une boucle produit une boucle infinie a pleine
   vitesse — c'est exactement ce qui arrivait dans calctri(). On vide donc la
   ligne, et on rend 0 pour que l'appelant decide quoi faire. */
int lire_entier(const char* invite, int* sortie)
{
	int c;
	printf("%s", invite);
	if (scanf("%d", sortie) == 1) return 1;

	while ((c = getchar()) != '\n' && c != EOF) { }   /* vider la ligne fautive */
	color(12,0);
	printf("\nSaisie invalide.\n");
	color(15,0);
	return 0;
}

int calctri(void)
 {
 	system("title Tri de Tableau");
     int nb_entiers;
	 // nombre d'entiers à entrer
	 int *tab,*temp; // tableau des entiers
	 int i,coul=0,done=1,t[6]={10,15,15,15,15,15}; // compteur
	 char choix;

	 // lire nb_entiers
	 /* nb_entiers n'etait pas initialise et le retour de scanf n'etait pas
	    teste : une saisie non numerique laissait une valeur quelconque, sur
	    laquelle malloc et la boucle partaient. Et comme scanf ne consomme
	    pas le caractere fautif, la boucle de remplissage tournait ensuite
	    indefiniment a pleine vitesse. */
	 nb_entiers = 0;
	 if (!lire_entier("Donner le nombre d'entiers que vous voulez trier: ", &nb_entiers))
		 return 0;

	 if (nb_entiers < 1 || nb_entiers > 1000)
	 {
		 color(12,0);
		 printf("\nIl en faut entre 1 et 1000.\n");
		 color(15,0);
		 return 0;
	 }

	  tab=(int *)malloc(nb_entiers*sizeof(int));
	  temp=(int *)malloc(nb_entiers*sizeof(int));
	  if (!tab || !temp)
	  {
		  free(tab); free(temp);
		  color(12,0);
		  printf("\nM%cmoire insuffisante.\n", 130);
		  color(15,0);
		  return 0;
	  }
    // remplir tab[nb_entiers]
	printf("\n");
	for(i=0;i<nb_entiers;i++)
	{
		char invite[64];
		sprintf(invite, "Donner l'entier %d: ", i+1);
		if (!lire_entier(invite, &tab[i]))
		{
			free(tab); free(temp);
			return 0;
		}
		temp[i]=tab[i];
	}
	while(done)
	{

		system("cls");
		printf("Votre Tableau: \n");
		color(14,0);
		for(i=0;i<nb_entiers;i++)
	{
		printf("|%d| ",tab[i]);

	}

	color(10,0);
	 printf("\n\n=================MENU==================\n\n");
	color(15,0);
	// liste des algorithmes de tri
	color(t[0],0);
	printf("\n1. Le tri %c bulle\n\n",133);
	color(t[1],0);
	printf("2. Le tri par s%cl%cction\n\n",130,130);
	color(t[2],0);
	printf("3. Le tri par permutation\n\n");
	color(t[3],0);
	printf("4. Le tri par insertion\n\n");
	color(t[4],0);
	printf("5. Le tri par fusion\n\n");
	color(t[5],0);
	printf("6. Le tri rapide\n");
	color(10,0);
	 printf("\n=======================================\n\n");
	color(15,0);
	// choisir l'algorithme à appliquer

	printf("\nVeuillez choisir le num%cro de de l'algorithme de tri %c appliquer et puis \nappuiyez sur [Enter] ",130,133);
	choix=getch();

	 	if(choix==BAS  && coul!=0) {t[coul]=15; coul--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && coul!=5) {t[coul]=15; coul++;}
          /*la méme chose avec haut*/
           t[coul]=10;
		   system("cls");
			//on bouge le  curseur dans le menu

	// appliquer l'algorithme choisi
	if(choix==OK)
	{

	switch(coul)
	{

		case 0: tri_a_bulle(tab,nb_entiers);
		wtab(tab,temp,nb_entiers,1);
		break;
		case 1: tri_selection(tab,nb_entiers);
		wtab(tab,temp,nb_entiers,2);
		break;
		case 2: tri_permutation(tab, nb_entiers);
		wtab(tab,temp,nb_entiers,3);
		break;
		case 3: tri_insertion(tab,nb_entiers);
		wtab(tab,temp,nb_entiers,4);
		break;
		case 4: tri_fusion(tab,nb_entiers);
		wtab(tab,temp,nb_entiers,5);
		break;
		case 5: tri_rapide(tab,nb_entiers);
		wtab(tab,temp,nb_entiers,6);
		break;

	}//switch
	done=0;
	}//for
	}//while

	 // résultat
	 system("cls");
	 printf("\nAvant le trie! :\n ");
	 color(14,0);
	 for(i=0;i<nb_entiers;i++)
	 printf("|%d|",temp[i]);
	  color(15,0);
	 printf("\nTRI%cS! :\n ",144);
	   color(14,0);
	 for(i=0;i<nb_entiers;i++)
	 printf("|%d|",tab[i]);
	 printf("\n\n");
	 color(15,0);
	 system("PAUSE");
}

/*======================================================================*/
int amine=0;
void change()
{
	amine++;
}
int menuautres()
{
	system("title Menu Autres Calculs");
	int t[10]={10,15,15,15,15,15,15,15,15,12},done=1,i=0;
char choix=0;
while (done)
{

	color(10,0);
	printf("\n\n=================MENU==================\n\n");
	color(15,0);
	printf("Choisissez:\n");
	color(t[0],0);
	printf("\n===>1:Calcul Factoriel.\n");
	color(t[1],0);
	printf("\n===>2:Nombres Premiers.\n");
	color(t[2],0);
	printf("\n===>3:Facteurs premiers.\n");
	color(t[3],0);
	printf("\n===>4:Crible d'%cratosth%cne.\n",144,138);
	color(t[4],0);
	printf("\n===>5:Nombres de Mersenne (Lucas-Lehmer).\n");
	color(t[5],0);
	printf("\n===>6:PGCD et PPCM.\n");
	color(t[6],0);
	printf("\n===>7:Conversion de bases.\n");
	color(t[7],0);
	printf("\n===>8:Statistiques.\n");
	color(t[8],0);
	printf("\n===>9:Retour.\n");
	color(t[9],0);
	printf("\n===>[ESCAPE]:Quitter.\n");
	color(10,0);
	printf("\n=======================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          if(choix==HAUT && i!=9) {t[i]=15; i++;}
                      t[9]=12;
					  t[i]=10;
					  system("cls");
           if(choix==27){done=0; quitter(); }
	if(choix==OK)
	{

	switch(i)
	{
		case 0:
		{
			system("cls");
			/* Le garde-fou « une seule fois par session » a saute avec la
			   correction du tampon global dans fact() : le calcul est
			   maintenant rejouable autant de fois qu'on veut. */
			int k;
			printf("Entrer le nombre que vous vouler savoir son factoriel :\n");
			if (scanf("%d",&k) == 1)
				fact(FALSE,k);
			system("pause");
			system("cls");
			menuautres();
		}
		break;
		case 1:
			system("cls");
			premier();
			printf("\n\n");
			system("pause");
			system("cls");
			menuautres();
		break;
		case 2:
			system("cls");
			facteurs();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 3:
			system("cls");
			crible();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 4:
			system("cls");
			mersenne();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 5:
			system("cls");
			pgcdppcm();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 6:
			system("cls");
			conversion();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 7:
			system("cls");
			stats();
			system("pause");
			system("cls");
			menuautres();
		break;
		case 8:
			system("cls");
			menu();
		break;
		case 9:
			quitter();
		break;
	}
	done=0;
    }

	}
	return 0;
}

void multiply(int k)
{
     char tampon[MAX];

     int l=strlen(n),i;
     for(i=0;i<l;i++)
      tampon[i]=n[l-i-1];
      tampon[l]=0;
      int rest=0;

      for( i=0;i<l;i++)
      {int x=k*(tampon[i]-'0')+rest;
      rest=x/10;
      tampon[i]=x%10+'0';
      }
      while(rest!=0)
        {tampon[i++]=rest%10+'0';
        rest/=10;
        }
     tampon[i]=0;
     int L=strlen(tampon);
     for(i=0;i<L;i++) n[i]=tampon[L-i-1];
     n[L]=0;
}
void fact(int v,int k){
	system("title Factorielle");

	/* Corrige la limitation que l'auteur avait notee : « N'utilisez pas le
	   calcul de factoriel plus d'une fois dans la meme session ».
	   La cause etait le tampon global n, jamais remis a "1" entre deux
	   appels : le second calcul repartait de 1000! et donnait n'importe quoi.

	   Au passage, on ne calcule plus systematiquement les 1000 premieres
	   factorielles ni ne reserve 2,6 Mo pour n'en afficher qu'une seule. */
	const int MAX_FACT = 1000;
	int i;

	if (k < 0 || k > MAX_FACT)
	{
		color(12,0);
		printf("\nLe rang doit %ctre compris entre 0 et %d.\n\n", 136, MAX_FACT);
		color(15,0);
		return;
	}

	strcpy(n, "1");              /* <- la correction */
	for (i = 2; i <= k; i++)
		multiply(i);

	if (v == FALSE)
	{
		printf("%d!\n", k);
		puts(n);
	}
}

/* Test de primalite.
   La version d'origine avait trois defauts :
     - elle declarait 1 premier, ce qu'il n'est pas ;
     - pour 0 et les negatifs, la boucle ne tournait pas et AUCUN verdict
       n'etait affiche ;
     - elle divisait jusqu'a n-1 au lieu de sqrt(n), soit 2 milliards
       d'iterations et une seconde de calcul pour 2147483647.

   Un diviseur va toujours par paire avec n/d, donc le plus petit des deux
   est <= sqrt(n) : s'arreter la suffit. Avec en plus la roue 6k+-1 — tout
   premier > 3 est de cette forme — on teste deux candidats sur six.
   Pour 2147483647 : environ 15 000 iterations au lieu de 2 147 483 645. */
/*=======================================================================*/
/*  Arithmetique modulaire et grands entiers, pour les nombres premiers.  */
/*=======================================================================*/

/* a*b mod m sans debordement : le produit de deux 64 bits tient sur 128.
   __uint128_t est une extension GCC/Clang — le projet est construit avec
   cette famille de compilateurs sur les trois plateformes. */
unsigned long long produit_mod(unsigned long long a, unsigned long long b, unsigned long long m)
{
	return (unsigned long long)((__uint128_t)a * b % m);
}

/* a^e mod m par exponentiation rapide. */
unsigned long long puissance_mod(unsigned long long a, unsigned long long e, unsigned long long m)
{
	unsigned long long r = 1;
	a %= m;
	while (e)
	{
		if (e & 1ULL) r = produit_mod(r, a, m);
		a = produit_mod(a, a, m);
		e >>= 1;
	}
	return r;
}

/* Test de primalite : Miller-Rabin deterministe sur 64 bits.
   La version d'origine divisait jusqu'a n-1 (2 milliards d'iterations et
   une seconde pour 2147483647) et declarait 1 premier, sans rien afficher
   pour 0 ni les negatifs.

   Miller-Rabin est probabiliste en general, mais il devient un test EXACT
   si l'on teste toutes les bases de la liste ci-dessous : c'est demontre
   pour tout n < 3,3 * 10^24, donc pour tout entier 64 bits. 15 microsecondes
   au pire, contre une seconde. */
int est_premier(long long valeur)
{
	static const unsigned long long bases[12] =
		{2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL};
	unsigned long long n, d, x;
	int i, j, s;

	if (valeur < 2) return 0;
	n = (unsigned long long)valeur;

	for (i = 0; i < 12; i++)
		if (n % bases[i] == 0) return n == bases[i];

	d = n - 1; s = 0;
	while ((d & 1ULL) == 0) { d >>= 1; s++; }

	for (i = 0; i < 12; i++)
	{
		int temoin = 1;
		x = puissance_mod(bases[i], d, n);
		if (x == 1ULL || x == n - 1ULL) continue;
		for (j = 1; j < s; j++)
		{
			x = produit_mod(x, x, n);
			if (x == n - 1ULL) { temoin = 0; break; }
		}
		if (temoin) return 0;
	}
	return 1;
}

void premier(){
	long long nb;

	printf("tapez votre nombre:\n");
	if (scanf("%lld", &nb) != 1)
	{
		color(12,0);
		printf("Entr%ce invalide.\n", 130);
		color(15,0);
		return;
	}

	if (nb < 0)
	{
		color(12,0);
		printf("La primalit%c ne se d%cfinit que sur les entiers positifs.\n", 130, 130);
		color(15,0);
		return;
	}

	color(14,0);
	if (nb < 2)
		/* 1 n'est premier ni compose : il n'a qu'un seul diviseur. */
		printf("%lld n'est pas un nombre premier.\n", nb);
	else if (est_premier(nb))
		printf("C'est un nombre premier\n");
	else
		printf("Ce n'est pas un nombre premier\n");
	color(15,0);
}



/* Decomposition en facteurs premiers, par divisions successives. */

/*=======================================================================*/
/*  Nombres de Mersenne et test de Lucas-Lehmer.                          */
/*                                                                        */
/*  Un nombre de Mersenne s'ecrit M(p) = 2^p - 1. Lucas-Lehmer decide de  */
/*  sa primalite en p-2 iterations de s <- s^2 - 2 modulo M(p), en        */
/*  partant de s = 4 : M(p) est premier si et seulement si le dernier s   */
/*  vaut 0. C'est ce test — et lui seul — qui a fourni tous les records   */
/*  de plus grand nombre premier connu depuis 1952.                       */
/*                                                                        */
/*  La reduction modulo 2^p - 1 est gratuite en binaire : 2^p vaut 1      */
/*  modulo M(p), donc il suffit d'additionner la partie haute a la        */
/*  partie basse, et de recommencer.                                      */
/*=======================================================================*/

static int  MERS_P  = 0;      /* exposant courant */
static int  MERS_NW = 0;      /* nombre de mots de 64 bits */

static void mers_set_M(unsigned long long* m)
{
	int i, bit = MERS_P & 63;
	for (i = 0; i < MERS_NW; i++) m[i] = ~0ULL;
	if (bit) m[MERS_NW-1] = (1ULL << bit) - 1ULL;
}

static int mers_vaut_M(const unsigned long long* v)
{
	unsigned long long* m = (unsigned long long*)malloc((size_t)MERS_NW * 8);
	int i, egal = 1;
	if (!m) return 0;
	mers_set_M(m);
	for (i = 0; i < MERS_NW; i++) if (v[i] != m[i]) { egal = 0; break; }
	free(m);
	return egal;
}

static void mers_ajouter_M(unsigned long long* v)
{
	unsigned long long* m = (unsigned long long*)malloc((size_t)MERS_NW * 8);
	unsigned long long retenue = 0;
	int i;
	if (!m) return;
	mers_set_M(m);
	for (i = 0; i < MERS_NW; i++)
	{
		__uint128_t t = (__uint128_t)v[i] + m[i] + retenue;
		v[i] = (unsigned long long)t;
		retenue = (unsigned long long)(t >> 64);
	}
	free(m);
}

/* prod occupe 2*NW mots ; en sortie il est reduit dans les NW premiers. */
static void mers_reduire(unsigned long long* prod)
{
	int mot = MERS_P >> 6, bit = MERS_P & 63, i;
	unsigned long long* haut = (unsigned long long*)malloc((size_t)2 * MERS_NW * 8);
	if (!haut) return;

	for (;;)
	{
		int reste = 0;
		unsigned long long retenue = 0;

		for (i = 0; i < 2*MERS_NW; i++)
		{
			unsigned long long x = 0;
			int src = i + mot;
			if (src < 2*MERS_NW)
			{
				x = bit ? (prod[src] >> bit) : prod[src];
				if (bit && src + 1 < 2*MERS_NW) x |= prod[src+1] << (64 - bit);
			}
			haut[i] = x;
			if (x) reste = 1;
		}
		if (!reste) break;

		for (i = mot + 1; i < 2*MERS_NW; i++) prod[i] = 0;
		if (bit) prod[mot] &= (1ULL << bit) - 1ULL; else prod[mot] = 0;

		for (i = 0; i < 2*MERS_NW; i++)
		{
			__uint128_t t = (__uint128_t)prod[i] + haut[i] + retenue;
			prod[i] = (unsigned long long)t;
			retenue = (unsigned long long)(t >> 64);
		}
	}
	free(haut);

	if (mers_vaut_M(prod)) for (i = 0; i < MERS_NW; i++) prod[i] = 0;   /* M vaut 0 mod M */
}


/* --- Mise au carre de Karatsuba -------------------------------------
   La methode scolaire coute n^2 multiplications de mots. Karatsuba en
   coute n^1.585 : en decoupant A = A1*B + A0, on obtient

       A^2 = A1^2*B^2 + ((A0+A1)^2 - A0^2 - A1^2)*B + A0^2

   soit trois carres de demi-taille au lieu de quatre produits. Mesure a
   p = 60000 : 3,85 fois plus rapide, pour un resultat identique au bit
   pres. En dessous de SEUIL mots, la recursion coute plus qu'elle ne
   rapporte et on repasse a la methode scolaire. */
#define KARA_SEUIL 28

static void mers_add_into(unsigned long long* dst, const unsigned long long* src, int n)
{
	unsigned long long c = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		__uint128_t t = (__uint128_t)dst[i] + src[i] + c;
		dst[i] = (unsigned long long)t;
		c = (unsigned long long)(t >> 64);
	}
	for (i = n; c; i++)
	{
		__uint128_t t = (__uint128_t)dst[i] + c;
		dst[i] = (unsigned long long)t;
		c = (unsigned long long)(t >> 64);
	}
}

static void mers_sub_from(unsigned long long* dst, const unsigned long long* src, int n)
{
	unsigned long long emprunt = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		unsigned long long ancien = dst[i];
		__uint128_t a_retirer = (__uint128_t)src[i] + emprunt;
		if ((__uint128_t)ancien < a_retirer)
		{
			dst[i] = (unsigned long long)((__uint128_t)ancien + ((__uint128_t)1 << 64) - a_retirer);
			emprunt = 1;
		}
		else { dst[i] = (unsigned long long)(ancien - (unsigned long long)a_retirer); emprunt = 0; }
	}
	for (i = n; emprunt; i++) { emprunt = (dst[i] == 0); dst[i] -= 1; }
}

static void mers_carre_scolaire(const unsigned long long* a, int n, unsigned long long* out)
{
	int i, j, q;
	memset(out, 0, (size_t)2*n*8);
	for (i = 0; i < n; i++)
	{
		unsigned long long c = 0;
		if (!a[i]) continue;
		for (j = 0; j < n; j++)
		{
			__uint128_t cur = (__uint128_t)a[i]*a[j] + out[i+j] + c;
			out[i+j] = (unsigned long long)cur;
			c = (unsigned long long)(cur >> 64);
		}
		q = i + n;
		while (c)
		{
			__uint128_t cur = (__uint128_t)out[q] + c;
			out[q] = (unsigned long long)cur;
			c = (unsigned long long)(cur >> 64);
			q++;
		}
	}
}

static void mers_carre(const unsigned long long* a, int n,
                       unsigned long long* out, unsigned long long* scratch)
{
	int bas, haut, m;
	unsigned long long *somme, *z1, *suite;

	if (n <= KARA_SEUIL) { mers_carre_scolaire(a, n, out); return; }

	bas = n / 2; haut = n - bas; m = haut + 1;
	somme = scratch; z1 = scratch + m; suite = scratch + m + 2*m;

	mers_carre(a,       bas,  out,         suite);
	mers_carre(a + bas, haut, out + 2*bas, suite);

	memset(somme, 0, (size_t)m*8);
	memcpy(somme, a, (size_t)bas*8);
	mers_add_into(somme, a + bas, haut);
	mers_carre(somme, m, z1, suite);

	mers_sub_from(z1, out,         2*bas);
	mers_sub_from(z1, out + 2*bas, 2*haut);
	mers_add_into(out + bas, z1, 2*m);
}

/* --- Pre-filtre : la forme des diviseurs de 2^p - 1 -----------------
   Theoreme. Si p est un premier impair et q divise 2^p - 1, alors
       q = 2kp + 1   et   q = +1 ou -1 modulo 8.
   Preuve. L'ordre de 2 modulo q vaut p, donc p divise q-1 ; q etant
   impair, 2p divise q-1. Par ailleurs 2 = (2^((p+1)/2))^2 modulo q est
   un residu quadratique, ce qui equivaut a q = +-1 mod 8.

   Chercher un diviseur ne coute donc que quelques microsecondes, et
   elimine 57 % des exposants premiers testes sous 2000 sans jamais
   lancer Lucas-Lehmer. */
long long facteur_mersenne(int p, long kmax)
{
	long k;
	for (k = 1; k <= kmax; k++)
	{
		unsigned long long q = 2ULL * (unsigned long long)k * (unsigned long long)p + 1ULL;
		int reste8 = (int)(q & 7ULL);
		if (reste8 != 1 && reste8 != 7) continue;
		if (!est_premier((long long)q)) continue;
		if (puissance_mod(2ULL, (unsigned long long)p, q) == 1ULL) return (long long)q;
	}
	return 0;
}

int lucas_lehmer(int p)
{
	unsigned long long *s, *t, *scratch;
	int k, i, nul;

	if (p == 2) return 1;
	if (!est_premier((long long)p)) return 0;   /* p compose => M(p) compose */

	MERS_P = p;
	MERS_NW = (p + 63) / 64;
	/* Karatsuba a besoin de place pour ses appels recursifs, et les
	   additions de mers_add_into peuvent propager une retenue au-dela
	   de la longueur nominale : on voit large. */
	s = (unsigned long long*)calloc((size_t)2*MERS_NW + 16, 8);
	t = (unsigned long long*)calloc((size_t)2*MERS_NW + 16, 8);
	scratch = (unsigned long long*)calloc((size_t)16*MERS_NW + 256, 8);
	if (!s || !t || !scratch) { free(s); free(t); free(scratch); return 0; }

	s[0] = 4;
	for (k = 0; k < p - 2; k++)
	{
		unsigned long long emprunt;

		memset(t, 0, (size_t)2*MERS_NW*8);
		mers_carre(s, MERS_NW, t, scratch);
		mers_reduire(t);

		emprunt = 2;                            /* t <- t - 2 */
		for (i = 0; i < MERS_NW && emprunt; i++)
		{
			unsigned long long ancien = t[i];
			t[i] = ancien - emprunt;
			emprunt = (ancien < emprunt) ? 1ULL : 0ULL;
		}
		if (emprunt) mers_ajouter_M(t);         /* sous-depassement : +M */

		memcpy(s, t, (size_t)MERS_NW*8);
		memset(s + MERS_NW, 0, (size_t)MERS_NW*8);
	}

	nul = 1;
	for (i = 0; i < MERS_NW; i++) if (s[i]) { nul = 0; break; }
	free(s); free(t); free(scratch);
	return nul;
}

int mersenne(void)
{
	system("title Nombres de Mersenne");

	int p;

	printf("\nTest de Lucas-Lehmer sur M(p) = 2^p - 1.\n");
	color(10,0);
	printf("   s = 4, puis p-2 fois  s <- s%c - 2  modulo M(p)\n", 253);
	printf("   M(p) est premier si et seulement si le dernier s vaut 0.\n\n");
	color(15,0);
	color(12,0);
	printf("<!> Au-del%c de p = 30000 le calcul devient long : la mise au\n", 133);
	printf("    carre est en O(p%c) ici, la faute a la methode scolaire.\n\n", 253);
	color(15,0);

	printf("Donnez l'exposant p : ");
	if (scanf("%d", &p) != 1) return 0;

	if (p < 2 || p > 60000)
	{
		color(12,0);
		printf("\np doit %ctre compris entre 2 et 60000.\n\n", 136);
		color(15,0);
		return 0;
	}

	if (!est_premier((long long)p))
	{
		color(14,0);
		printf("\np = %d n'est pas premier, donc M(p) ne l'est pas non plus.\n\n", p);
		color(15,0);
		return 0;
	}

	/* Pre-filtre : chercher un diviseur de la forme 2kp+1 coute quelques
	   microsecondes et evite Lucas-Lehmer dans plus de la moitie des cas. */
	{
		/* Le filtrage coute environ 0,2 us par candidat k. On le dimensionne
		   sur p pour qu'il reste une fraction du cout de Lucas-Lehmer, qui
		   croit en p^3 : a p = 4423 un kmax fixe a 200000 coutait 38 ms
		   pour un test qui n'en prend que 17. */
		long kmax = (long)p * 5L;
		long long f;
		if (kmax < 2000L)   kmax = 2000L;
		if (kmax > 200000L) kmax = 200000L;
		f = facteur_mersenne(p, kmax);
		if (f)
		{
			color(14,0);
			printf("\nM(%d) n'est pas premier : il est divisible par %lld.\n", p, f);
			color(10,0);
			printf("Trouv%c sans lancer Lucas-Lehmer — tout diviseur de 2^p-1\n", 130);
			printf("est de la forme 2kp+1 et vaut +-1 modulo 8.\n\n");
			color(15,0);
			return 0;
		}
	}

	printf("\nCalcul en cours (%d it%crations)...\n", p - 2, 130);

	if (lucas_lehmer(p))
	{
		color(10,0);
		printf("\nM(%d) = 2^%d - 1 EST PREMIER.\n", p, p);
		printf("Il compte %.0f chiffres d%ccimaux.\n\n", (double)p * 0.30103 + 1.0, 130);
		color(15,0);
	}
	else
	{
		color(14,0);
		printf("\nM(%d) = 2^%d - 1 n'est pas premier.\n\n", p, p);
		color(15,0);
	}
	return 0;
}

int facteurs(void)
{
	system("title Facteurs premiers");

	long long n, d, reste;
	int premierFacteur = 1;

	printf("\nD%ccomposition en facteurs premiers.\n\n", 130);
	printf("tapez votre nombre:\n");
	if (scanf("%lld", &n) != 1) return 0;

	if (n < 2)
	{
		color(12,0);
		printf("\nLa d%ccomposition n'a de sens qu'%c partir de 2.\n\n", 130, 133);
		color(15,0);
		return 0;
	}

	reste = n;
	color(14,0);
	printf("\n%lld = ", n);

	for (d = 2; d * d <= reste; d += (d == 2 ? 1 : 2))
	{
		int exposant = 0;
		while (reste % d == 0) { reste /= d; exposant++; }
		if (exposant)
		{
			if (!premierFacteur) printf(" x ");
			premierFacteur = 0;
			if (exposant == 1) printf("%lld", d);
			else               printf("%lld^%d", d, exposant);
		}
	}
	if (reste > 1)
	{
		if (!premierFacteur) printf(" x ");
		printf("%lld", reste);
		premierFacteur = 0;
	}
	printf("\n\n");
	color(15,0);
	return 0;
}

/* Liste des nombres premiers jusqu'a N, par le crible d'Eratosthene. */
int crible(void)
{
	system("title Crible d'Eratosthene");

	const long LIMITE = 10000000L;   /* 10 Mo de marqueurs, une seconde environ */
	long n, i, j, total = 0;
	char* compose;

	printf("\nListe des nombres premiers jusqu'%c N, par le crible d'%cratosth%cne.\n\n", 133, 144, 138);
	printf("N (2 %c %ld) : ", 133, LIMITE);
	if (scanf("%ld", &n) != 1) return 0;

	if (n < 2 || n > LIMITE)
	{
		color(12,0);
		printf("\nN doit %ctre compris entre 2 et %ld.\n\n", 136, LIMITE);
		color(15,0);
		return 0;
	}

	compose = (char*)calloc((size_t)n + 1, sizeof(char));
	if (!compose)
	{
		color(12,0);
		printf("\nM%cmoire insuffisante.\n\n", 130);
		color(15,0);
		return 0;
	}

	/* On barre les multiples de chaque premier, en partant de son carre :
	   les multiples plus petits ont deja ete barres par un premier plus petit. */
	for (i = 2; i * i <= n; i++)
		if (!compose[i])
			for (j = i * i; j <= n; j += i)
				compose[j] = 1;

	for (i = 2; i <= n; i++) if (!compose[i]) total++;

	color(14,0);
	printf("\n%ld nombres premiers jusqu'%c %ld.\n", total, 133, n);
	color(15,0);

	if (total <= 500)
	{
		int colonne = 0;
		printf("\n");
		for (i = 2; i <= n; i++)
			if (!compose[i])
			{
				printf("%8ld", i);
				if (++colonne % 8 == 0) printf("\n");
			}
		if (colonne % 8) printf("\n");
	}
	else
	{
		printf("Trop nombreux pour %ctre affich%cs ; les 40 premiers :\n\n", 136, 130);
		int colonne = 0;
		for (i = 2; i <= n && colonne < 40; i++)
			if (!compose[i])
			{
				printf("%8ld", i);
				if (++colonne % 8 == 0) printf("\n");
			}
		if (colonne % 8) printf("\n");
	}
	printf("\n");

	free(compose);
	return 0;
}
/*======================================================================*/


/* La fonction factorielle simple:

Arguments :

x : le nombre dont il faut calculer la factorielle

Resultat :

la factorielle de x

*/

double fact2 (double c)

{

	double i;

	double result = 1.0f;

	for (i = 1.0f ; i <= c; i += 1.0f)

		result *= i;

	return result;

}



int calcsin (void)
{
	system("title Sinus");

	double x, temp, s;
	int n;

	color(12,0);
	printf("\n<!> La valeur de x doit %ctre en degr%c.\npi en rad = 180deg\n\n", 136, 130);
	color(15,0);

	printf ("Donnez une valeur pour x \n");
	if (scanf("%lf", &x) != 1) return 0;
	temp = x;
	/* Reduction dans ]-180, 180] : sans elle, sin(3600 deg) rendait 2,9e+24. */
	x = reduire_angle(x);

	printf ("Donnez un entier n \n");
	if (scanf("%d", &n) != 1) return 0;
	if (n < 0) { printf("\nLe rang doit %ctre positif.\n", 136); return 0; }

	s = serie_sin(x, n);

	printf ("\nUne valeur approch%ce du sinus de %0.lf par son d%cveloppement limit%c au rang %d est %lf \n", 130, temp, 130, 130, n, s);
	printf ("La valeur exacte du sinus de %0.lf est %lf\n", temp, sin(x));
	printf ("Erreur absolue : %g\n\n", fabs(s - sin(x)));
	return 0;
}

/*======================================================================*/

int menudl()
{
	int t[7]={10,15,15,15,15,15,12},done=1,i=0;
	system("title Developpement Limite");
char choix=0;
 while(done){
	color(10,0);
	printf("\n\n================MENU D%cveloppement===============\n",144);printf("\t\t\t\t\t\t*\n");
	color(15,0);
	printf("Choisissez:");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[0],0);
	printf("===>1:D%cveloppement sinus.",130);
	color(10,0);
	printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[1],0);
	printf("===>2:D%cveloppement exp.",130);
	color(10,0);
	printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[2],0);
	printf("===>3:D%cveloppement cosinus.",130);
	color(10,0);
	printf("\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[3],0);
	printf("===>4:D%cveloppement ln(1+x).",130);
	color(10,0);
	printf("\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[4],0);
	printf("===>5:D%cveloppement tangente.",130);
	color(10,0);
	printf("\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[5],0);
	printf("===>6:Retour.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[6],0);
	printf("===>[ESCAPE]:Quitter.");
	color(10,0);
	printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*");
	color(10,0);
	printf("\n=================================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          if(choix==HAUT && i!=6) {t[i]=15; i++;}
            t[6]=12;
			t[i]=10;
			system("cls");
          if(choix==27){done=0; quitter(); }
	if(choix==OK)
          {
	switch(i)
	{
		case 0:
			system("cls");
			calcsin();
			system("pause");
			system("cls");
			menudl();
		break;
		case 1:
			system("cls");
			calcexp();
			system("pause");
			system("cls");
			menudl();
		break;
		case 2:
			system("cls");
			calccos();
			system("pause");
			system("cls");
			menudl();
		break;
		case 3:
			system("cls");
			calcln();
			system("pause");
			system("cls");
			menudl();
		break;
		case 4:
			system("cls");
			calctan();
			system("pause");
			system("cls");
			menudl();
		break;
		case 5:
			system("cls");
			menu();
		break;
		case 6:
			quitter();
		break;
		default:
			printf("\nError 01\n\a");
			system("pause");
			system("cls");
			menudl();
		break;
	}//Switch
	done=0;
	}//If
	}//while
	return 0;
}



/*======================================================================*/

int wdeter(float a[][LIMIT],int forder,float value)
{
	int i=0,j=0;
    FILE* fichier = NULL;

    fichier = fopen("txt/Determinent.txt", "a+");

    if (fichier != NULL)
    {// On peut lire et écrire dans le fichier
    fprintf(fichier,"===================================\nVotre Matrice:\n");
    	for(i=0;i<forder;i++)
		  {
				  	fprintf(fichier,"|");
				 for(j=0;j<forder;j++)
				 {
				   fprintf(fichier,"%0.f|",a[i][j]);

				 }
				fprintf(fichier,"\n");
		  }
		  fprintf(fichier,"\nLe Determinant est: %0.f",value);

        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Error File :Impossible de creer le fichier");
    }

    return 0;
}

int weq(float a,float b,float c, float x1,float x2,int param)//weq(a,b,c,x1,x2,param);
{

    FILE* fichier = NULL;

    fichier = fopen("txt/Equations.txt", "a+");

    if (fichier != NULL)
    {// On peut lire et écrire dans le fichier
    if(param==1)
    {

    fprintf(fichier,"\n===================================\nVotre Equation:\n%0.fx+%0.f=0",a,b);
    	if(a!=0){

		fprintf(fichier,"\nSolution: %f",x1);	}else
		{
		fprintf(fichier,"\nErreur");
		}
	}else if(param==2)
	{
	fprintf(fichier,"\n===================================\nVotre Equation:\n%0.fx^2+%0.fx+%0.f=0",a,b,c);

		fprintf(fichier,"\nSolutions:\nx1=%f\nOu\nx2=%f\n",x1,x2);
	}else if(param==4)
	{
	fprintf(fichier,"\n===================================\nVotre Equation:\n%0.fx^2+%0.fx+%0.f=0",a,b,c);

		fprintf(fichier,"\nSolution:\nx1=%f\n",x1);
	}else{
		fprintf(fichier,"\n===================================\nVotre Equation:\n%0.fx^2+%0.fx+%0.f=0",a,b,c);

		fprintf(fichier,"\nSolutions Complexe:\n\n");
		fprintf(fichier,"x1=(-(%0.f)-i%f)/%0.f\n",b,x1,2*a);
		fprintf(fichier,"x2=(-(%0.f)+i%f)/%0.f\n\n",b,x1,2*a);
	}

        fclose(fichier);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Error File :Impossible de creer le fichier");
    }

    return 0;
}
int wtab(int *t,int *temp,int nb_entiers,int param)
{
	int i;
    FILE* fichier = NULL;

    fichier = fopen("txt/Trietableau.txt", "a+");

	if (fichier != NULL)
    {// On peut lire et écrire dans le fichier
    fprintf(fichier,"===================================\nVotre Tableau:");

	fprintf(fichier,"\nAvant le trie! :\n ");

	 for(i=0;i<nb_entiers;i++)
	 fprintf(fichier,"|%d|",temp[i]);
	switch(param)
	{

		case 1:
		 fprintf(fichier,"\nTri a bulle:\n ");
		break;
		case 2:
		 fprintf(fichier,"\nTri par selection:\n ");
		break;
		case 3:
		 fprintf(fichier,"\nTri par permutation:\n ");
		break;
		case 4:
		 fprintf(fichier,"\nTri par insertion:\n ");
		break;
		case 5:
		 fprintf(fichier,"\nTri par fusion:\n ");
		break;
		case 6:
		 fprintf(fichier,"\nTri rapide:\n ");
		break;
		default:
		 printf("\nErreur parametre d'ecriture\n\a");
		break;
	}
	 for(i=0;i<nb_entiers;i++)
	 fprintf(fichier,"|%d|",t[i]);
	 fprintf(fichier,"\n");

        fclose(fichier);
    }
    else
    {
    // On affiche un message d'erreur si on veut
        printf("Error File :Impossible de creer le fichier");
    }
	return 0;
}

/*======================================================================*/

void apropos(void)
{
	char down;
	system("cls");
	color(10,0);
	printf("======================%c Propos MathDiverse %s==============================\n\n",183,VER);
	color(12,0);
	printf("Atention:\n\nPour le bon fonctionnement de ce programme on vous conseil de:\n\n-Eviter de taper n'importe quoi sur le clavier lorsque des choix sont propos%cs\n\nou de taper un caract%cre lorsque un nombre est demand%c. Merci !\n\n-V%crifier si une mise %c jour est disponible sur :\n",130,138,130,130,133);
	color(2,0);
		printf("╔═════════════════════════════╗\t\t");
	printf("\n║https://github.com/aminekun90║");
	printf("\n╚═════════════════════════════╝");
	color(0,15);
	printf("\nDes id%ces d'am%clioration ? contactez nous!.%c",130,130,1);
	color(10,0);
	printf("\n\n===============================================================================\n\n");
	color(15,0);
//	printf("Voulez-vous v%crifier si une mise %c jour est disponible ? \n\n[Oui]: tapez 'O'.\n\n[Non]: tapez 'N'",130,133);
	printf("Tapez une touche pour revenir",130,133);
	down=getch();
	printf("Voulez-vous v%crifier si une mise %c jour est disponible ? \n\n[Oui]: tapez 'O'.\n\n[Non]: tapez 'N'",130,133);
	system("cls");
//	switch(down)
//	{
//		    case 'O':
//			case 'o':
//			system("start download.exe");
//			exit(0);
//
//		break;
//		case 'n':
//			case 'N':
//			system("cls");
//
//		break;
//		default:
//		system("cls");
//		apropos();break;
//	}
}

/*======================================================================*/
void menujeux()
{
	system("title Menu Jeux");
	system("cls");
	int t[6]={10,15,15,15,15,12},done=1,i=0;
char choix;
while(done)
{
label:
	color(10,0);
	printf("\n\n====================MENU JEUX====================\n",144);printf("\t\t\t\t\t\t*\n");
	color(15,0);
	printf("Choisissez:");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[0],0);
	printf("===>1:Jouer %c Snake.",133);color(10,0);printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[1],0);
	printf("===>2:Jouer %c Allumettes.",133);color(10,0);printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[2],0);
	printf("===>3:Jouer %c TicTacToe.",133);color(10,0);printf("\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[3],0);
	printf("===>3:Jouer %c Tetris.",133);color(10,0);printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[4],0);
	printf("===>4:Retour.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[5],0);
	printf("===>5:Quitter.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*");

	color(10,0);
	printf("\n=================================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=5) {t[i]=15; i++;}
          /*la méme chose avec haut*/
            t[5]=12;
			t[i]=10;
			system("cls");//on bouge le  curseur dans le menu
        //if(choix==27){done=0; quitter(); }
	if (choix==OK)
	{

	switch(i)
	{
		case 0:
			system("cls");

			//system("start Snake.exe");
		snaky();

			//return EXIT_SUCCESS;
		break;
		case 1:
			system("cls");
			Allumette();
			menujeux();
		break;
		case 2:
		system("cls");
		tictactoe();
		menujeux();
		break;
		case 3:
		system("cls");
		TET();
		system("start Mathdiverse.exe");
		exit(0);
		//menujeux();
		//return;
		break;
		case 4:
				system("cls");


		break;

		case 5:
			quitter();
		break;
}//switch
	done=0;
	}//if
}//while
}

/*======================================================================*/

/* color(x,y); à l'endroit où l'on veut mettre les couleurs
x correspond à la couleur du texte
y correspond à la couleur de fond

les valeurs:
0: noir
1: bleu foncé
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc
=========================================================================*/
void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    	SetConsoleTextAttribute(H,f*16+t);
}

/*=======================================================================*/
/*  Series de Taylor : calcul par recurrence, et reduction de l'angle.    */
/*                                                                        */
/*  La version d'origine calculait chaque terme par pow(x,k)/fact2(k).    */
/*  Trois limites mesurees :                                              */
/*    - fact2 deborde le double au-dela de 170! : les termes de rang      */
/*      superieur devenaient 0 et la serie cessait de progresser ;        */
/*    - sans reduction d'angle, sin(3600 deg) rendait 2,9e+24 au lieu     */
/*      de 0 — les termes intermediaires enormes s'annulent mal ;         */
/*    - exp(-20) rendait 4,99e-09 au lieu de 2,06e-09, soit 142 %         */
/*      d'erreur, par la meme annulation catastrophique.                  */
/*                                                                        */
/*  La recurrence terme_k = terme_(k-1) * facteur ne calcule jamais ni    */
/*  puissance ni factorielle : rien ne deborde, et c'est lineaire.        */
/*=======================================================================*/

/* Ramene un angle en degres dans ]-180, 180], puis le convertit en radians.
   sin et cos sont 360-periodiques : c'est exact, pas une approximation. */
double reduire_angle(double degres)
{
	double r = fmod(degres, 360.0);
	if (r >  180.0) r -= 360.0;
	if (r <= -180.0) r += 360.0;
	return (r * M_PI) / 180.0;
}

/* sin(x) = x - x^3/3! + x^5/5! - ...   terme_k = terme_(k-1) * -x^2/((2k)(2k+1)) */
double serie_sin(double x, int n)
{
	double terme = x, somme = x;
	int k;
	for (k = 1; k <= n; k++)
	{
		terme *= -(x * x) / ((2.0 * k) * (2.0 * k + 1.0));
		somme += terme;
	}
	return somme;
}

/* cos(x) = 1 - x^2/2! + x^4/4! - ...   terme_k = terme_(k-1) * -x^2/((2k-1)(2k)) */
double serie_cos(double x, int n)
{
	double terme = 1.0, somme = 1.0;
	int k;
	for (k = 1; k <= n; k++)
	{
		terme *= -(x * x) / ((2.0 * k - 1.0) * (2.0 * k));
		somme += terme;
	}
	return somme;
}

/* exp(x) = 1 + x + x^2/2! + ...   terme_k = terme_(k-1) * x/k
   Pour x < 0 on calcule exp(|x|) puis on inverse : la serie alternee perd
   sinon tous ses chiffres significatifs par annulation. */
double serie_exp(double x, int n)
{
	double ax = fabs(x), terme = 1.0, somme = 1.0;
	int k;
	for (k = 1; k <= n; k++)
	{
		terme *= ax / (double)k;
		somme += terme;
	}
	return (x < 0.0) ? 1.0 / somme : somme;
}

/* ln(1+x) = x - x^2/2 + x^3/3 - ...   converge sur ]-1, 1] */
double serie_ln1p(double x, int n)
{
	double puissance = x, somme = 0.0;
	int k;
	for (k = 1; k <= n; k++)
	{
		somme += ((k % 2) ? puissance : -puissance) / (double)k;
		puissance *= x;
	}
	return somme;
}

/*=======================================================================*/
/*  Calculs ajoutes en 2026 — meme style que l'existant : accents ecrits  */
/*  en codes CP850 via %c, pour rester lisibles sur la console Windows    */
/*  comme sur un terminal UTF-8.                                          */
/*=======================================================================*/

/* Developpement limite de exp(x) au rang n : somme des x^k / k!
   C'etait l'entree « Bientot » du menu depuis 2014. */
int calcexp(void)
{
	system("title Developpement exponentielle");

	double x, s;
	int n;

	printf("\nD%cveloppement limit%c de exp(x) en 0 :\n", 130, 130);
	color(10,0);
	printf("   exp(x) = 1 + x + x%c/2! + x%c/3! + ...\n\n", 253, 179);
	color(15,0);

	printf("Donnez une valeur pour x \n");
	if (scanf("%lf", &x) != 1) return 0;
	printf("Donnez un entier n \n");
	if (scanf("%d", &n) != 1) return 0;
	if (n < 0) { printf("\nLe rang doit %ctre positif.\n", 136); return 0; }

	/* Pour x < 0, serie_exp calcule exp(|x|) puis inverse : la serie
	   alternee perdait sinon tous ses chiffres (exp(-20) etait faux de 142 %). */
	s = serie_exp(x, n);

	printf("\nUne valeur approch%ce de exp(%g) par son d%cveloppement limit%c au rang %d est %g\n",
	       130, x, 130, 130, n, s);
	printf("La valeur exacte de exp(%g) est %g\n", x, exp(x));
	printf("Erreur absolue : %g\n\n", fabs(s - exp(x)));
	return 0;
}

/* Developpement limite de cos(x) : somme des (-1)^k x^(2k) / (2k)! */
int calccos(void)
{
	system("title Developpement cosinus");

	double x, temp, s;
	int n;

	color(12,0);
	printf("\n<!> La valeur de x doit %ctre en degr%c.\npi en rad = 180deg\n\n", 136, 130);
	color(15,0);

	printf("Donnez une valeur pour x \n");
	if (scanf("%lf", &x) != 1) return 0;
	temp = x;
	x = reduire_angle(x);

	printf("Donnez un entier n \n");
	if (scanf("%d", &n) != 1) return 0;
	if (n < 0) { printf("\nLe rang doit %ctre positif.\n", 136); return 0; }

	s = serie_cos(x, n);

	printf("\nUne valeur approch%ce du cosinus de %0.lf par son d%cveloppement limit%c au rang %d est %lf\n",
	       130, temp, 130, 130, n, s);
	printf("La valeur exacte du cosinus de %0.lf est %lf\n", temp, cos(x));
	printf("Erreur absolue : %g\n\n", fabs(s - cos(x)));
	return 0;
}

/* Developpement limite de ln(1+x) : somme des (-1)^(k+1) x^k / k
   Ne converge que sur ]-1, 1]. */
int calcln(void)
{
	system("title Developpement logarithme");

	double x, s;
	int n;

	printf("\nD%cveloppement limit%c de ln(1+x) en 0 :\n", 130, 130);
	color(10,0);
	printf("   ln(1+x) = x - x%c/2 + x%c/3 - ...\n", 253, 179);
	color(15,0);
	color(12,0);
	printf("<!> La s%crie ne converge que pour -1 < x <= 1\n\n", 130);
	color(15,0);

	printf("Donnez une valeur pour x \n");
	if (scanf("%lf", &x) != 1) return 0;

	if (x <= -1.0 || x > 1.0)
	{
		color(12,0);
		printf("\nx = %g est hors du domaine de convergence.\n\n", x);
		color(15,0);
		return 0;
	}

	printf("Donnez un entier n \n");
	if (scanf("%d", &n) != 1) return 0;
	if (n < 1) { printf("\nLe rang doit valoir au moins 1.\n"); return 0; }

	s = serie_ln1p(x, n);

	printf("\nUne valeur approch%ce de ln(1+%g) au rang %d est %lf\n", 130, x, n, s);
	printf("La valeur exacte est %lf\n", log(1.0 + x));
	printf("Erreur absolue : %g\n\n", fabs(s - log(1.0 + x)));
	return 0;
}

/* PGCD par l'algorithme d'Euclide, PPCM par a*b/pgcd. */
/* Tangente : quotient des deux series. Il n'y en avait pas jusqu'ici. */
int calctan(void)
{
	system("title Developpement tangente");

	double x, temp, sc, cc, s;
	int n;

	color(12,0);
	printf("\n<!> La valeur de x doit %ctre en degr%c.\n", 136, 130);
	printf("tan n'est pas d%cfinie en 90 deg modulo 180.\n\n", 130);
	color(15,0);

	printf("Donnez une valeur pour x \n");
	if (scanf("%lf", &x) != 1) return 0;
	temp = x;
	x = reduire_angle(x);

	printf("Donnez un entier n \n");
	if (scanf("%d", &n) != 1) return 0;
	if (n < 0) { printf("\nLe rang doit %ctre positif.\n", 136); return 0; }

	sc = serie_sin(x, n);
	cc = serie_cos(x, n);

	if (fabs(cc) < 1e-12)
	{
		color(12,0);
		printf("\ncos(%0.lf) vaut 0 : la tangente n'est pas d%cfinie.\n\n", temp, 130);
		color(15,0);
		return 0;
	}

	s = sc / cc;

	printf("\nUne valeur approch%ce de la tangente de %0.lf au rang %d est %lf\n", 130, temp, n, s);
	printf("La valeur exacte de la tangente de %0.lf est %lf\n", temp, tan(x));
	printf("Erreur absolue : %g\n\n", fabs(s - tan(x)));
	return 0;
}

int pgcdppcm(void)
{
	system("title PGCD et PPCM");

	long a, b, x, y, r, pgcd;

	printf("\nCalcul du PGCD et du PPCM de deux entiers.\n\n");
	printf("Donnez a et b \n");
	if (scanf("%ld %ld", &a, &b) != 2) { printf("\nEntr%ce invalide.\n", 130); return 0; }

	if (a == 0 && b == 0)
	{
		color(12,0);
		printf("\nPGCD(0,0) n'est pas d%cfini.\n\n", 130);
		color(15,0);
		return 0;
	}

	x = a < 0 ? -a : a;
	y = b < 0 ? -b : b;

	/* Euclide : le PGCD est le dernier reste non nul. */
	while (y != 0) { r = x % y; x = y; y = r; }
	pgcd = x;

	color(14,0);
	printf("\nPGCD(%ld, %ld) = %ld\n", a, b, pgcd);
	if (a != 0 && b != 0)
		printf("PPCM(%ld, %ld) = %ld\n\n", a, b, (a / pgcd) * (b < 0 ? -b : b));
	else
		printf("PPCM(%ld, %ld) = 0\n\n", a, b);
	color(15,0);
	return 0;
}

/* Conversion d'un entier entre les bases 2, 8, 10 et 16. */
int conversion(void)
{
	system("title Conversion de bases");

	static const char* digits = "0123456789ABCDEF";
	char saisie[65], sortie[70];
	long valeur = 0;
	int base_in, base_out, i, len = 0;

	printf("\nConversion d'un entier positif entre bases.\n\n");
	printf("Base de d%cpart (2, 8, 10 ou 16) : ", 130);
	if (scanf("%d", &base_in) != 1) return 0;
	if (base_in != 2 && base_in != 8 && base_in != 10 && base_in != 16)
	{ color(12,0); printf("\nBase non support%ce.\n\n", 130); color(15,0); return 0; }

	printf("Nombre : ");
	if (scanf("%64s", saisie) != 1) return 0;

	for (i = 0; saisie[i]; i++)
	{
		char c = saisie[i];
		int chiffre;
		if      (c >= '0' && c <= '9') chiffre = c - '0';
		else if (c >= 'a' && c <= 'f') chiffre = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F') chiffre = c - 'A' + 10;
		else chiffre = 99;

		if (chiffre >= base_in)
		{
			color(12,0);
			printf("\n'%c' n'est pas un chiffre valide en base %d.\n\n", c, base_in);
			color(15,0);
			return 0;
		}
		valeur = valeur * base_in + chiffre;
	}

	printf("Base d'arriv%ce (2, 8, 10 ou 16) : ", 130);
	if (scanf("%d", &base_out) != 1) return 0;
	if (base_out != 2 && base_out != 8 && base_out != 10 && base_out != 16)
	{ color(12,0); printf("\nBase non support%ce.\n\n", 130); color(15,0); return 0; }

	if (valeur == 0) { sortie[len++] = '0'; }
	while (valeur > 0) { sortie[len++] = digits[valeur % base_out]; valeur /= base_out; }

	color(14,0);
	printf("\nR%csultat : ", 130);
	for (i = len - 1; i >= 0; i--) putchar(sortie[i]);
	printf("  (base %d)\n\n", base_out);
	color(15,0);
	return 0;
}

/* Moyenne, mediane et ecart-type d'une serie saisie au clavier. */
int stats(void)
{
	system("title Statistiques");

	double serie[100], somme = 0.0, moyenne, variance = 0.0, mediane;
	int n, i, j;

	printf("\nMoyenne, m%cdiane et %ccart-type d'une s%crie.\n\n", 130, 130, 130);
	printf("Combien de valeurs (1 %c 100) ? ", 133);
	if (scanf("%d", &n) != 1) return 0;
	if (n < 1 || n > 100)
	{ color(12,0); printf("\nIl en faut entre 1 et 100.\n\n"); color(15,0); return 0; }

	for (i = 0; i < n; i++)
	{
		printf("  valeur %d : ", i + 1);
		if (scanf("%lf", &serie[i]) != 1) return 0;
		somme += serie[i];
	}

	moyenne = somme / n;
	for (i = 0; i < n; i++)
		variance += (serie[i] - moyenne) * (serie[i] - moyenne);
	variance /= n;

	/* Tri par insertion, il faut la serie ordonnee pour la mediane. */
	for (i = 1; i < n; i++)
	{
		double v = serie[i];
		for (j = i - 1; j >= 0 && serie[j] > v; j--) serie[j+1] = serie[j];
		serie[j+1] = v;
	}
	mediane = (n % 2) ? serie[n/2] : (serie[n/2 - 1] + serie[n/2]) / 2.0;

	color(14,0);
	printf("\nEffectif      : %d\n", n);
	printf("Somme         : %g\n", somme);
	printf("Moyenne       : %g\n", moyenne);
	printf("M%cdiane       : %g\n", 130, mediane);
	printf("Variance      : %g\n", variance);
	printf("%ccart-type    : %g\n", 144, sqrt(variance));
	printf("Minimum       : %g\n", serie[0]);
	printf("Maximum       : %g\n\n", serie[n-1]);
	color(15,0);
	return 0;
}

/* Systeme de deux equations a deux inconnues, par la methode de Cramer. */
int systeme2(void)
{
	system("title Systeme 2x2");

	double a, b, c, d, e, f, det, x, y;

	printf("\nSyst%cme de deux %cquations %c deux inconnues :\n", 138, 130, 133);
	color(10,0);
	printf("   a*x + b*y = c\n");
	printf("   d*x + e*y = f\n\n");
	color(15,0);

	printf("Donnez a, b et c \n");
	if (scanf("%lf %lf %lf", &a, &b, &c) != 3) return 0;
	printf("Donnez d, e et f \n");
	if (scanf("%lf %lf %lf", &d, &e, &f) != 3) return 0;

	det = a * e - b * d;

	if (det == 0.0)
	{
		color(12,0);
		/* Determinant nul : soit les droites sont confondues, soit paralleles. */
		if (a * f - c * d == 0.0 && c * e - b * f == 0.0)
			printf("\nD%cterminant nul : une infinit%c de solutions.\n\n", 130, 130);
		else
			printf("\nD%cterminant nul : aucune solution.\n\n", 130);
		color(15,0);
		return 0;
	}

	x = (c * e - b * f) / det;
	y = (a * f - c * d) / det;

	color(14,0);
	printf("\nD%cterminant = %g\n", 130, det);
	printf("x = %g\n", x);
	printf("y = %g\n\n", y);
	color(15,0);
	return 0;
}
/*=======================================================================*/
int gettime()
{
SYSTEMTIME t;
GetSystemTime(&t);
printf("%d/%d/%d %d:%d:%d ",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);
	return 0;   /* la fonction est declaree int : sans return, comportement indefini */
}
 /////////////////////////////////////////////////////////////////////////

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

