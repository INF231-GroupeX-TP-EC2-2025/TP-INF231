#ifndef MATRICES_H
#define MATRICES_H

#include <stdio.h>
#include <stdlib.h>

// Fonctions d'affichage
void afficherMatrice(int **matrice, int lignes, int colonnes);
void afficherTableau(int *tableau, int taille);
void afficherVecteur(int *vecteur, int taille);

// Fonctions de création
int** creerMatrice(int lignes, int colonnes);
int* creerTableau(int taille);
void libererMatrice(int **matrice, int lignes);

// Opérations sur les matrices
int** sommeMatrices(int **matrice1, int **matrice2, int lignes, int colonnes);
int** produitMatrices(int **matrice1, int **matrice2, int lignes1, int colonnes1, int lignes2, int colonnes2);

// Opérations sur les tableaux
int rechercheSequentielle(int *tableau, int taille, int valeur);
int multiplicationAddition(int a, int b);
int estTrie(int *tableau, int taille);
float median(int *tableau, int taille);
void inverserTableau(int *tableau, int taille);

// Produits vectoriels
int* produitVectoriel(int *vecteur1, int *vecteur2, int taille);
int* produitVecteurMatrice(int *vecteur, int **matrice, int lignes, int colonnes);

// Fonctions utilitaires
void trierTableau(int *tableau, int taille);
void copierTableau(int *source, int *destination, int taille);

#endif