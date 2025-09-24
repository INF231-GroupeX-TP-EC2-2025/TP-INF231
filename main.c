#include "matrices.h"
#include <time.h>

void demoSommeMatrices() {
    printf("\n=== SOMME DE MATRICES ===\n");
    int lignes = 3, colonnes = 3;
    
    int **matrice1 = creerMatrice(lignes, colonnes);
    int **matrice2 = creerMatrice(lignes, colonnes);
    
    printf("Matrice 1:");
    afficherMatrice(matrice1, lignes, colonnes);
    
    printf("Matrice 2:");
    afficherMatrice(matrice2, lignes, colonnes);
    
    int **resultat = sommeMatrices(matrice1, matrice2, lignes, colonnes);
    printf("Résultat de la somme:");
    afficherMatrice(resultat, lignes, colonnes);
    
    libererMatrice(matrice1, lignes);
    libererMatrice(matrice2, lignes);
    libererMatrice(resultat, lignes);
}

void demoProduitMatrices() {
    printf("\n=== PRODUIT DE MATRICES ===\n");
    int lignes1 = 2, colonnes1 = 3;
    int lignes2 = 3, colonnes2 = 2;
    
    int **matrice1 = creerMatrice(lignes1, colonnes1);
    int **matrice2 = creerMatrice(lignes2, colonnes2);
    
    printf("Matrice 1 (%dx%d):", lignes1, colonnes1);
    afficherMatrice(matrice1, lignes1, colonnes1);
    
    printf("Matrice 2 (%dx%d):", lignes2, colonnes2);
    afficherMatrice(matrice2, lignes2, colonnes2);
    
    int **resultat = produitMatrices(matrice1, matrice2, lignes1, colonnes1, lignes2, colonnes2);
    if(resultat != NULL) {
        printf("Résultat du produit (%dx%d):", lignes1, colonnes2);
        afficherMatrice(resultat, lignes1, colonnes2);
        libererMatrice(resultat, lignes1);
    }
    
    libererMatrice(matrice1, lignes1);
    libererMatrice(matrice2, lignes2);
}

void demoRechercheSequentielle() {
    printf("\n=== RECHERCHE SÉQUENTIELLE ===\n");
    int taille = 10;
    int *tableau = creerTableau(taille);
    
    printf("Tableau: ");
    afficherTableau(tableau, taille);
    
    int valeur = tableau[rand() % taille]; // Prend une valeur existante
    printf("Recherche de la valeur %d...\n", valeur);
    
    int position = rechercheSequentielle(tableau, taille, valeur);
    if(position != -1) {
        printf("Valeur trouvée à la position %d\n", position);
    } else {
        printf("Valeur non trouvée\n");
    }
    
    free(tableau);
}

void demoMultiplicationAddition() {
    printf("\n=== MULTIPLICATION PAR ADDITION ===\n");
    int a = 5, b = 4;
    printf("%d × %d = %d\n", a, b, multiplicationAddition(a, b));
    
    a = 7, b = 3;
    printf("%d × %d = %d\n", a, b, multiplicationAddition(a, b));
}

void demoEstTrie() {
    printf("\n=== TEST TABLEAU TRIÉ ===\n");
    int taille = 5;
    
    // Tableau non trié
    int tableau1[] = {3, 1, 4, 1, 5};
    printf("Tableau 1: ");
    afficherTableau(tableau1, taille);
    printf("Est trié? %s\n", estTrie(tableau1, taille) ? "OUI" : "NON");
    
    // Tableau trié
    int tableau2[] = {1, 2, 3, 4, 5};
    printf("Tableau 2: ");
    afficherTableau(tableau2, taille);
    printf("Est trié? %s\n", estTrie(tableau2, taille) ? "OUI" : "NON");
}

void demoMedian() {
    printf("\n=== CALCUL DU MÉDIAN ===\n");
    int taille = 5;
    int *tableau = creerTableau(taille);
    
    printf("Tableau original: ");
    afficherTableau(tableau, taille);
    
    float med = median(tableau, taille);
    printf("Médian: %.2f\n", med);
    
    free(tableau);
}

void demoInverserTableau() {
    printf("\n=== INVERSION DE TABLEAU ===\n");
    int taille = 6;
    int *tableau = creerTableau(taille);
    
    printf("Tableau original: ");
    afficherTableau(tableau, taille);
    
    inverserTableau(tableau, taille);
    printf("Tableau inversé: ");
    afficherTableau(tableau, taille);
    
    free(tableau);
}

void demoProduitVectoriel() {
    printf("\n=== PRODUIT VECTORIEL ===\n");
    int taille = 3;
    int vecteur1[] = {1, 2, 3};
    int vecteur2[] = {4, 5, 6};
    
    printf("Vecteur 1: ");
    afficherVecteur(vecteur1, taille);
    printf("Vecteur 2: ");
    afficherVecteur(vecteur2, taille);
    
    int *resultat = produitVectoriel(vecteur1, vecteur2, taille);
    if(resultat != NULL) {
        printf("Produit vectoriel: ");
        afficherVecteur(resultat, taille);
        free(resultat);
    }
}

void demoProduitVecteurMatrice() {
    printf("\n=== PRODUIT VECTEUR × MATRICE ===\n");
    int taille = 3;
    int vecteur[] = {1, 2, 3};
    
    int **matrice = creerMatrice(taille, taille);
    
    printf("Vecteur: ");
    afficherVecteur(vecteur, taille);
    printf("Matrice:");
    afficherMatrice(matrice, taille, taille);
    
    int *resultat = produitVecteurMatrice(vecteur, matrice, taille, taille);
    if(resultat != NULL) {
        printf("Résultat du produit: ");
        afficherVecteur(resultat, taille);
        free(resultat);
    }
    
    libererMatrice(matrice, taille);
}

void menuPrincipal() {
    int choix;
    
    do {
        printf("\n═══════════════════════════════════════════════\n");
        printf("          PROGRAMME DE MANIPULATION DE MATRICES\n");
        printf("═══════════════════════════════════════════════\n");
        printf("1. Somme de matrices\n");
        printf("2. Produit de matrices\n");
        printf("3. Recherche séquentielle\n");
        printf("4. Multiplication par addition\n");
        printf("5. Test tableau trié\n");
        printf("6. Calcul du médian\n");
        printf("7. Inversion de tableau\n");
        printf("8. Produit vectoriel\n");
        printf("9. Produit vecteur × matrice\n");
        printf("0. Quitter\n");
        printf("═══════════════════════════════════════════════\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        
        switch(choix) {
            case 1: demoSommeMatrices(); break;
            case 2: demoProduitMatrices(); break;
            case 3: demoRechercheSequentielle(); break;
            case 4: demoMultiplicationAddition(); break;
            case 5: demoEstTrie(); break;
            case 6: demoMedian(); break;
            case 7: demoInverserTableau(); break;
            case 8: demoProduitVectoriel(); break;
            case 9: demoProduitVecteurMatrice(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide!\n");
        }
        
        if(choix != 0) {
            printf("\nAppuyez sur Entrée pour continuer...");
            getchar(); getchar();
        }
        
    } while(choix != 0);
}

int main() {
    srand(time(NULL)); // Initialisation pour l'aléatoire
    
    printf("Bienvenue dans le programme de manipulation de matrices!\n");
    printf("Ce programme démontre les différentes fonctionnalités demandées.\n");
    
    menuPrincipal();
    
    return 0;
}
