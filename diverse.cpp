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
	setTitle("MathDiverse "VER"");
	system("cls");
			printf("\n%c bient%ct !%c\n\nLe programme va quitter tout seul patientez.",183,147,1);
			Sleep(1000);
			printf(".");
			Sleep(1000);
			printf(".");

			exit(0);//quitter
}
int menu()
{
system("title MathDiverse");
	int t[7]={10,15,15,15,15,15,12},done=1,i=0;
	char choix=0;
	 while(done)
	 {
	 	color(7,0);
	printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\t\t");gettime();
	printf("\nºMise %c Jour: ",133);JOUR;printf(" Version  %s.º",VER);
	printf("\nÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n");
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


}
int menueq()
{
	system("title Menu Equations");
	int t[4]={10,15,15,12},done=1,i=0;
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
	printf("===>3:Retour.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[3],0);
	printf("===>[ESCAPE]:Quitter.");
	color(10,0);
	printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*");

	color(10,0);
	printf("\n=================================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=3) {t[i]=15; i++;}
          /*la méme chose avec haut*/
           t[3]=12; t[i]=10;
		   system("cls");
			//on bouge le  curseur dans le menu
			if(choix==27){done=0; quitter(); }
	if(choix==OK)
	{

	switch(i)
	{
		case 0:
			eq1();
		break;
		case 1:
			eq2();
		break;
		case 2:
			system("cls");
			menu();
		break;
		case 3:
			done=0;
			quitter();
			return EXIT_SUCCESS;
		break;

	}//switch
	done=0;
		}//if
	}//while
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
if (a==0||b==0){

	printf("\nLa solution c'est 0 si b=0 sinon Erreur si a=0 !\n");

} else if(b<0)
{
	result=(-b)/a;

}
else if(b>0)
{
	 result=(-b)/a;
}
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
	d=pow(b,2)-4*a*c;
	if(d>0)
	{
		printf("\nLes solution reelles:\n");
		color(14,0);
		x1=(-b+sqrt(d))/2*a;
		x2=(-b-sqrt(d))/2*a;
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
		printf("   %f\n\n",-b/2*a);
		x1=-b/2*a;
		weq(a,b,c,x1,0,4);//weq(a,b,c,x1,x2,param);
		color(15,0);
	}

	system("pause");
	system("cls");
	menueq();
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

 int calctri(void)
 {
 	system("title Tri de Tableau");
     int nb_entiers;
	 // nombre d'entiers à entrer
	 int *tab,*temp; // tableau des entiers
	 int i,coul=0,done=1,t[6]={10,15,15,15,15,15}; // compteur
	 char choix;

	 // lire nb_entiers
	 printf("Donner le nombre d'entiers que vous voulez trier: ");
	  scanf("%d",&nb_entiers);
	  // allouer la mémoire pour tab[nb_entiers]
	  tab=(int *)malloc(nb_entiers*sizeof(int));
	  temp=(int *)malloc(nb_entiers*sizeof(int));
    // remplir tab[nb_entiers]
	printf("\n");
	for(i=0;i<nb_entiers;i++)
	{
		printf("Donner l'entier %d: ",i+1);
		scanf("%d",&tab[i]);
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
	int t[4]={10,15,15,12},done=1,i=0;
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
	printf("\n===>3:Retour.\n");
	color(t[3],0);
	printf("\n===>[ESCAPE]:Quitter.\n");
	color(10,0);
	printf("\n=======================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=3) {t[i]=15; i++;}
          /*la méme chose avec haut*/
                      t[3]=12;
					  t[i]=10;
					  system("cls");//on bouge le  curseur dans le menu
           if(choix==27){done=0; quitter(); }
	if(choix==OK)
	{

	switch(i)
	{

		case 0: system("cls");
			color(15,12);

			printf("\n<!>Attention : N'utilisez pas le calcul de factoriel plus d'une fois dans\n la m%cme session utilisation=%d\n",136,amine);

			color(15,0);
          	if(amine==0){
          		change();
          	int k;
			printf("Entrer le nombre que vous vouler savoir son factoriel :\n");
          scanf("%d",&k);
			fact(FALSE,k);
			system("pause");
			system("cls");
			menuautres();

		}else{
			change();
			color(2,0);
	printf("\nLe probl%cme sera corrig%cs dans les prochaines mises %c jour !\n",138,130,133);
	printf("\nLe Programme va red%cmarrer.",133);
	Sleep(1000);
	printf(".");
	Sleep(1000);
	printf(".");
	color(15,0);
	system("start MathDiverse.exe");
		exit(0);//quitter
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
			menu();
		break;
		case 3:
			quitter();
		break;



	}
	done=0;
    }

	}
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

			   //problem de fuite memoire !! il faut trouver une solution
   int taillet = 1001;
   int p = MAX,i,j;
   char ** f=NULL;
   //char * n=NULL;
   //n=(char*)calloc(p,sizeof(char));
   f = (char**)calloc (taillet,sizeof(char *));
   for (i = 1; i < taillet; i++)
   {
      f[i] = (char*)calloc (p,sizeof(char));

   }
			// for(i=1;i<taillet;i++)
			 //	f[i]="1";


         for(i=1;i<=1000;i++){
          multiply(i);

          strcpy(f[i],n);

         }

          if (v==FALSE)
          {
          printf("%d!\n",k);
          puts(f[k]);
        	//printf("%s\n",f[k]);
        	for (i =0; i < taillet; i++)
 			 {
 			 free (f[i]);
 			 f[i]=NULL;
 			 }
			 free (f);
			f=NULL;

          }else{

          //return (intptr_t)f[k];
		  }
		 //free(n);


         }

void premier(){
int nb, i,total=1, j;

printf("tapez votre nombre:\n");
scanf("%d", &nb);
if(nb==1 || nb==2){printf("C'est un nombre premier\n");}else{

	for(j=2;j<nb;j++)
        {
            if(nb%j==0)
            {
            printf("Ce n'est pas un nombre premier\n");
            break;
            }

            else if(nb-j==1)
                printf("C'est un nombre premier\n");
        }
}
if(nb%2==0){printf("Et il est paire\n");}else{printf("Et il est impaire\n");}
  printf("\n\nFactorisation : \n%d=",nb);while(total<nb){
	  for(i=2;i<nb;i++){
		  if(nb%i==0){

			break;}
	  }

	  printf("%d*", i);
	  total=total*i;
	  nb=nb/i;


}


printf("%d", nb);




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

	double x, s,temp;

	int i, n;
color(12,0);
 printf("\n<!> Attention:\nla valeur de x doit %ctre en degr%c.\npi en rad = 180deg\n\n",136,130);
 color(15,0);
	/* double limit test

	double test = 180;

	printf ("%lf! == %lf\n", test, fact2 (test));
*/

	printf ("Donnez une valeur pour x \n");

	scanf ("%lf", &x);
	temp=x;
x=(x*M_PI)/180;
	printf ("Donnez un entier n \n");

	scanf ("%d", &n);

	s=x;

	for (i=1; i<=n; i++)

	{

		s+=pow (-1, i)*pow (x, 2*i+1)/fact2 ((double) (2*i+1));

	}

	printf ("\nUne valeur approch%ce du sinus de %0.lf par son d%cveloppement limit%c au rang %d est %lf \n", 130,temp,130,130,n, s);

	printf ("La valeur exacte du sinus de %0.lf est %lf\n\n", temp, sin(x));



}

/*======================================================================*/

int menudl()
{
	int t[4]={10,15,15,12},done=1,i=0;
	system("title Développement Limité");
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
	printf("===>2:D%cveloppement exp.(Bient%ct)",144,147);
	color(10,0);
	printf("\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[2],0);
	printf("===>3:Retour.");
	color(10,0);
	printf("\t\t\t\t\t*\n");printf("\t\t\t\t\t\t*\n");
	color(t[3],0);
	printf("===>[ESCAPE]:Quitter.");
	color(10,0);
	printf("\t\t\t\t*\n");printf("\t\t\t\t\t\t*");
	color(10,0);
	printf("\n=================================================\n\n");
	color(15,0);
	choix=getch();
	if(choix==BAS  && i!=0) {t[i]=15; i--;}
          /*si l'utilisateur a clicker sur bas et que le curseur n'egale pas zéro
          on descend le curseur dans le menu*/
          if(choix==HAUT && i!=3) {t[i]=15; i++;}
          /*la méme chose avec haut*/
            t[3]=12;
			t[i]=10;
			system("cls");//on bouge le  curseur dans le menu
          if(choix==27){done=0; quitter(); }
	if(choix==OK)//si l'utilisateur a cliqué sur entreé
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
			menudl();
		break;
		case 2:
			system("cls");
			menu();
		break;
		case 3:
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
		printf("ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\t\t");
	printf("\nºhttps://github.com/aminekun90º");
	printf("\nÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼");
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
int gettime()
{
SYSTEMTIME t;
GetSystemTime(&t);
printf("%d/%d/%d %d:%d:%d ",t.wDay,t.wMonth,t.wYear,t.wHour,t.wMinute,t.wSecond);
}
 /////////////////////////////////////////////////////////////////////////

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

