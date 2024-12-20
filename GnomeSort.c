#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void gnomeSort(int arr[], int n) {
    int pos = 0; // Position actuelle

    while (pos < n) {
        if (pos == 0 || arr[pos] >= arr[pos - 1]) {
            pos++; // Avancer si dans l'ordre
        } else {
            // Échanger les éléments
            int temp = arr[pos];
            arr[pos] = arr[pos - 1];
            arr[pos - 1] = temp;
            pos--; // Reculer
        }
    }
}

int main() {
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

    // Appliquer le tri Gnome Sort
     t1 = clock();
    gnomeSort(arr, n);
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


