#include "matrices.h"

// Affichage d'une matrice
void afficherMatrice(int **matrice, int lignes, int colonnes) {
    printf("\n");
    for(int i = 0; i < lignes; i++) {
        for(int j = 0; j < colonnes; j++) {
            printf("%4d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Affichage d'un tableau
void afficherTableau(int *tableau, int taille) {
    printf("[ ");
    for(int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }
    printf("]\n");
}

// Affichage d'un vecteur
void afficherVecteur(int *vecteur, int taille) {
    printf("( ");
    for(int i = 0; i < taille; i++) {
        printf("%d ", vecteur[i]);
    }
    printf(")\n");
}

// Création d'une matrice
int** creerMatrice(int lignes, int colonnes) {
    int **matrice = (int**)malloc(lignes * sizeof(int*));
    for(int i = 0; i < lignes; i++) {
        matrice[i] = (int*)malloc(colonnes * sizeof(int));
        for(int j = 0; j < colonnes; j++) {
            matrice[i][j] = rand() % 10; // Valeurs aléatoires entre 0 et 9
        }
    }
    return matrice;
}

// Création d'un tableau
int* creerTableau(int taille) {
    int *tableau = (int*)malloc(taille * sizeof(int));
    for(int i = 0; i < taille; i++) {
        tableau[i] = rand() % 100; // Valeurs aléatoires entre 0 et 99
    }
    return tableau;
}

// Libération de mémoire d'une matrice
void libererMatrice(int **matrice, int lignes) {
    for(int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

// Somme de deux matrices
int** sommeMatrices(int **matrice1, int **matrice2, int lignes, int colonnes) {
    int **resultat = (int**)malloc(lignes * sizeof(int*));
    for(int i = 0; i < lignes; i++) {
        resultat[i] = (int*)malloc(colonnes * sizeof(int));
        for(int j = 0; j < colonnes; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }
    return resultat;
}

// Produit de deux matrices
int** produitMatrices(int **matrice1, int **matrice2, int lignes1, int colonnes1, int lignes2, int colonnes2) {
    if(colonnes1 != lignes2) {
        printf("Erreur: Dimensions incompatibles pour le produit matriciel\n");
        return NULL;
    }
    
    int **resultat = (int**)malloc(lignes1 * sizeof(int*));
    for(int i = 0; i < lignes1; i++) {
        resultat[i] = (int*)malloc(colonnes2 * sizeof(int));
        for(int j = 0; j < colonnes2; j++) {
            resultat[i][j] = 0;
            for(int k = 0; k < colonnes1; k++) {
                resultat[i][j] += matrice1[i][k] * matrice2[k][j];
            }
        }
    }
    return resultat;
}

// Recherche séquentielle dans un tableau
int rechercheSequentielle(int *tableau, int taille, int valeur) {
    for(int i = 0; i < taille; i++) {
        if(tableau[i] == valeur) {
            return i; // Retourne l'indice si trouvé
        }
    }
    return -1; // Retourne -1 si non trouvé
}

// Multiplication utilisant uniquement l'addition
int multiplicationAddition(int a, int b) {
    if(a < 0 || b < 0) {
        printf("Erreur: Les nombres doivent être positifs\n");
        return -1;
    }
    
    int resultat = 0;
    for(int i = 0; i < b; i++) {
        resultat += a;
    }
    return resultat;
}

// Vérifier si un tableau est trié
int estTrie(int *tableau, int taille) {
    for(int i = 0; i < taille - 1; i++) {
        if(tableau[i] > tableau[i + 1]) {
            return 0; // Non trié
        }
    }
    return 1; // Trié
}

// Trier un tableau (tri à bulles)
void trierTableau(int *tableau, int taille) {
    for(int i = 0; i < taille - 1; i++) {
        for(int j = 0; j < taille - i - 1; j++) {
            if(tableau[j] > tableau[j + 1]) {
                int temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }
}

// Copier un tableau
void copierTableau(int *source, int *destination, int taille) {
    for(int i = 0; i < taille; i++) {
        destination[i] = source[i];
    }
}

// Calcul du médian d'un tableau
float median(int *tableau, int taille) {
    int *copie = (int*)malloc(taille * sizeof(int));
    copierTableau(tableau, copie, taille);
    trierTableau(copie, taille);
    
    float resultat;
    if(taille % 2 == 0) {
        resultat = (copie[taille/2 - 1] + copie[taille/2]) / 2.0;
    } else {
        resultat = copie[taille/2];
    }
    
    free(copie);
    return resultat;
}

// Inverser un tableau
void inverserTableau(int *tableau, int taille) {
    for(int i = 0; i < taille / 2; i++) {
        int temp = tableau[i];
        tableau[i] = tableau[taille - 1 - i];
        tableau[taille - 1 - i] = temp;
    }
}

// Produit vectoriel (pour vecteurs de taille 3)
int* produitVectoriel(int *vecteur1, int *vecteur2, int taille) {
    if(taille != 3) {
        printf("Erreur: Le produit vectoriel est défini pour les vecteurs de taille 3\n");
        return NULL;
    }
    
    int *resultat = (int*)malloc(3 * sizeof(int));
    resultat[0] = vecteur1[1] * vecteur2[2] - vecteur1[2] * vecteur2[1];
    resultat[1] = vecteur1[2] * vecteur2[0] - vecteur1[0] * vecteur2[2];
    resultat[2] = vecteur1[0] * vecteur2[1] - vecteur1[1] * vecteur2[0];
    
    return resultat;
}

// Produit vecteur × matrice
int* produitVecteurMatrice(int *vecteur, int **matrice, int lignes, int colonnes) {
    if(lignes != colonnes) {
        printf("Erreur: La matrice doit être carrée pour ce produit\n");
        return NULL;
    }
    
    int *resultat = (int*)malloc(colonnes * sizeof(int));
    for(int j = 0; j < colonnes; j++) {
        resultat[j] = 0;
        for(int i = 0; i < lignes; i++) {
            resultat[j] += vecteur[i] * matrice[i][j];
        }
    }
    return resultat;
}