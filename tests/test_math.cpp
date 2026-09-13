/* Tests de non-regression des calculs de MathDiverse.
 *
 * Ils lient le code du programme sans main.cpp et appellent les fonctions
 * de calcul directement — pas de pilotage du menu, pas de terminal. Les
 * fonctions testees n'ecrivent rien : ce sont les seules qui soient pures.
 *
 * Lancement :  cmake --build build && ./build/tests_math
 */
#include "diverse.h"

#include <cmath>
#include <cstdio>
#include <cstring>

/* compat.h redefinit printf en macro : on utilise donc les noms C nus,
   jamais std::printf, qui ne se resoudrait pas. */

static int total = 0, echecs = 0;

static void verifier(int condition, const char* quoi)
{
	total++;
	if (!condition) { echecs++; printf("  ECHEC : %s\n", quoi); }
}

static void proche(double obtenu, double attendu, double tolerance, const char* quoi)
{
	total++;
	double ecart = std::fabs(obtenu - attendu);
	if (!(ecart <= tolerance))
	{
		echecs++;
		printf("  ECHEC : %s  (obtenu %.12g, attendu %.12g, ecart %.3g)\n",
		            quoi, obtenu, attendu, ecart);
	}
}

/* ------------------------------------------------------------ primalite */
static void test_primalite(void)
{
	printf("primalite\n");

	verifier(!est_premier(-7), "-7 n'est pas premier");
	verifier(!est_premier(0),  "0 n'est pas premier");
	verifier(!est_premier(1),  "1 n'est pas premier");   /* le bug d'origine */
	verifier( est_premier(2),  "2 est premier");
	verifier( est_premier(3),  "3 est premier");
	verifier(!est_premier(4),  "4 n'est pas premier");
	verifier(!est_premier(561), "561 (Carmichael) n'est pas premier");
	verifier(!est_premier(1105), "1105 (Carmichael) n'est pas premier");
	verifier( est_premier(2147483647LL), "2^31-1 est premier");
	verifier(!est_premier(4294967297LL), "2^32+1 = 641 x 6700417");
	verifier( est_premier(1000000007LL), "1000000007 est premier");
	verifier( est_premier(9223372036854775783LL), "9223372036854775783 est premier");
	verifier(!est_premier(9223372036854775806LL), "9223372036854775806 est pair");

	/* comptage : 168 premiers en dessous de 1000 */
	int compte = 0;
	for (int n = 2; n < 1000; n++) if (est_premier(n)) compte++;
	verifier(compte == 168, "168 premiers en dessous de 1000");
}

/* ------------------------------------------------------- Mersenne / LL */
static void test_mersenne(void)
{
	printf("Lucas-Lehmer\n");

	const int premiers[] = {2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,
	                        2203,2281,3217,4253,4423};
	const int composes[] = {11,23,29,37,41,43,47,1277,2205,4421};
	char nom[64];

	for (unsigned i = 0; i < sizeof premiers / sizeof *premiers; i++)
	{
		sprintf(nom, "M(%d) est premier", premiers[i]);
		verifier(lucas_lehmer(premiers[i]) == 1, nom);
	}
	for (unsigned i = 0; i < sizeof composes / sizeof *composes; i++)
	{
		sprintf(nom, "M(%d) n'est pas premier", composes[i]);
		verifier(lucas_lehmer(composes[i]) == 0, nom);
	}

	/* Theoreme : tout diviseur de 2^p-1 vaut 2kp+1 et +-1 mod 8. */
	printf("facteurs de Mersenne\n");
	verifier(facteur_mersenne(11, 1000) == 23,  "23 divise M(11)");
	verifier(facteur_mersenne(23, 1000) == 47,  "47 divise M(23)");
	verifier(facteur_mersenne(29, 1000) == 233, "233 divise M(29)");
	verifier(facteur_mersenne(43, 1000) == 431, "431 divise M(43)");
	verifier(facteur_mersenne(4423, 5000) == 0, "M(4423) n'a pas de petit facteur");
}

/* ---------------------------------------------- series de Taylor */
static void test_series(void)
{
	printf("series de Taylor\n");

	proche(reduire_angle(0),    0.0,          1e-12, "reduction de 0 deg");
	proche(reduire_angle(360),  0.0,          1e-12, "reduction de 360 deg");
	proche(reduire_angle(3600), 0.0,          1e-12, "reduction de 3600 deg");
	proche(reduire_angle(90),   M_PI/2,       1e-12, "reduction de 90 deg");

	/* sans reduction, la version d'origine rendait 2,9e+24 pour 3600 deg */
	proche(serie_sin(reduire_angle(3600), 40), 0.0, 1e-12, "sin(3600 deg)");
	proche(serie_sin(reduire_angle(36000), 40), 0.0, 1e-12, "sin(36000 deg)");
	proche(serie_sin(reduire_angle(30), 20), 0.5, 1e-12, "sin(30 deg) = 0,5");
	proche(serie_sin(reduire_angle(90), 20), 1.0, 1e-12, "sin(90 deg) = 1");
	/* fact2 debordait au-dela de 170! : le rang etait plafonne vers 84 */
	proche(serie_sin(reduire_angle(30), 1000), 0.5, 1e-12, "sin au rang 1000");

	proche(serie_cos(reduire_angle(0), 20),   1.0, 1e-12, "cos(0) = 1");
	proche(serie_cos(reduire_angle(60), 20),  0.5, 1e-12, "cos(60 deg) = 0,5");
	proche(serie_cos(reduire_angle(180), 30), -1.0, 1e-12, "cos(180 deg) = -1");

	/* exp(-20) rendait 3,43e-05 au lieu de 2,06e-09, exp(-40) 6,35e+13 */
	proche(serie_exp(1, 30),    std::exp(1.0),   1e-12, "exp(1)");
	proche(serie_exp(-20, 200), std::exp(-20.0), 1e-15, "exp(-20)");
	proche(serie_exp(-40, 300), std::exp(-40.0), 1e-20, "exp(-40)");
	proche(serie_exp(10, 100),  std::exp(10.0),  1e-8,  "exp(10)");

	proche(serie_ln1p(1, 100000), std::log(2.0), 1e-4, "ln(2) au rang 100000");
	proche(serie_ln1p(0.5, 80),   std::log(1.5), 1e-12, "ln(1,5)");
	proche(serie_ln1p(0, 10),     0.0,           1e-15, "ln(1) = 0");
}

/* ------------------------------------------------ arithmetique modulaire */
static void test_modulaire(void)
{
	printf("arithmetique modulaire\n");

	verifier(produit_mod(0, 0, 7) == 0, "0 x 0 mod 7");
	verifier(produit_mod(3, 4, 7) == 5, "3 x 4 mod 7 = 5");
	/* le produit deborderait 64 bits sans le passage par 128 */
	verifier(produit_mod(4000000000ULL, 4000000000ULL, 1000000007ULL)
	         == 784ULL, "produit de deux nombres de 4 milliards");
	verifier(puissance_mod(2, 10, 1000) == 24, "2^10 mod 1000 = 24");
	verifier(puissance_mod(2, 0, 7) == 1, "2^0 = 1");
	verifier(puissance_mod(3, 100, 7) == 4, "3^100 mod 7 = 4");
}

int main(void)
{
	printf("=== tests des calculs de MathDiverse ===\n\n");
	test_primalite();
	test_mersenne();
	test_series();
	test_modulaire();
	printf("\n%d verifications, %d echec%s\n",
	            total, echecs, echecs > 1 ? "s" : "");
	return echecs ? 1 : 0;
}
