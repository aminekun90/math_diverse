#ifndef DEF_ALLUMETTE
#define DEF_ALLUMETTE

/* Implémenté en C (allumettes.c) mais appelé depuis du C++ : sans extern "C",
   l'éditeur de liens cherche un symbole décoré et ne le trouve pas. */
#ifdef __cplusplus
extern "C" {
#endif

void Allumette();

#ifdef __cplusplus
}
#endif

#endif
