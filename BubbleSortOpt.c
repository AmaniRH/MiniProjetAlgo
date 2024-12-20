#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void BubbleSortOpt(int A[], int n) {
    int m = n - 1;
    int  Change = 1; //  quand il n’y a aucun échange le tableau est trié
    while (Change) {
        Change = 0;
        for (int i = 0; i < m; i++) {
            if (A[i] > A[i + 1]) {
                // Échange
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                Change = 1;
            }
        }
        m--; // réduire l'intervalle
    }
}

int main ()
{

 int n;
double delta;
    clock_t t1  ;
     clock_t t2  ;
    // Demander à l'utilisateur la taille du tableau
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    // Vérifier que la taille est positive
    if (n <= 0) {
        printf("La taille du tableau doit être un nombre positif.\n");
        return 1;
    }

    // Allocation dynamique de mémoire pour le tableau
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Erreur d'allocation de mémoire.\n");
        return 1;
    }

    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    // Remplir le tableau avec des valeurs aléatoires entre 0 et 99
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Valeurs aléatoires entre 0 et 99
    }

    printf("Tableau initial : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Appliquer le tri à bulles optimisé
     t1 = clock();
    BubbleSortOpt(arr, n);
    t2 = clock();
    delta = (double)(t2 - t1) / CLOCKS_PER_SEC;

    // Afficher le tableau trié
    printf("Tableau trié : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
     printf("\n");
    printf("la complexity tomporele de cet algorithme est : %f seconds", delta);

    // Libérer la mémoire allouée
    free(arr);

    return 0;
  
}