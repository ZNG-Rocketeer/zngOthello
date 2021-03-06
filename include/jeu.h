/*
*   Header JEU_H
*   Fonctionnalités:
*   Lancer fenetre jeu
*   Auteur: airone@airone-debian (E. LE CORNEC)
*   Création : 18/02
*   MODIFICATION camil les "tab" deviennent "plateau"
*/
#ifndef _JEU_H_
#define _JEU_H_

#ifndef VIDE
/* LES BORDS DE LA MATRICE DOIVENT ÊTRE VIDE ( égal à 0) */
#define VIDE 0  /* ne pas toucher car fonction a_voisin */
#define NOIR 1
#define BLANC 2

#endif
#include "liste.h"

typedef struct {
  char joueur_1[20];
  int niv1;
  char joueur_2[20];
  int niv2;
  int *nb_pions;
  int fen;
}info;

/* avoir la couleur de l'ennemi */
int opposant(int couleur);
/* avoir niveau IA/J ennemi */
int change_tour(int tour, info i);

/* Description jeu */
int jeu();

/* initialise le plateau */
void init_pions(int **plateau);

/* poser un pion */
int pose_pion(int couleur, int x, int y, int **plateau);


/* fonctions de vérification d'enncadrement d'un pion ennemi */
int cap_haut(int couleur, int i, int j, int **plateau);
int cap_bas(int couleur, int i, int j, int **plateau);
int cap_droit(int couleur, int i, int j, int **plateau);
int cap_gauche(int couleur, int i, int j, int **plateau);
int cap_diag_haut_droit(int couleur, int i, int j, int **plateau);
int cap_diag_haut_gauche(int couleur, int i, int j, int **plateau);
int cap_diag_bas_droit(int couleur, int i, int j, int **plateau);
int cap_diag_bas_gauche(int couleur, int i, int j, int **plateau);

/* fonction de verification de pion voisin */
int a_voisin(int i, int j, int **plateau);

/* fonction renvoyant vrai si le coup est légal */
int coup_valide(int couleur, int i, int j, int **plateau);

/* retourne le nb de pions [0]=nbdeblancs [1]=nbdenoirs */
int *nb_pions(int **plateau);

/* vérification fin de partie avec couleur le tour du joueur */
int continue_partie(int couleur, int **plateau);
/* 1 les deux peuvent jouer */
/* 2 couleur peux jouer, pas opposant */
/* 3 opposant peux jouer mais pas couleur */
/* 0 aucun ne peut jouer -> fin partie */
#endif /* end of include guard: _JEU_H_  */
