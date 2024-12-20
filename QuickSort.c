#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choisir le dernier élément comme pivot
    int i = (low - 1); // Index de l'élément plus petit

    for (int j = low; j < high; j++) {
        // Si l'élément actuel est plus petit ou égal au pivot
        if (arr[j] <= pivot) {
            i++; // Incrémenter l'index de l'élément plus petit
            swap(&arr[i], &arr[j]); // Échanger
        }
    }
    swap(&arr[i + 1], &arr[high]); // Placer le pivot à sa position correcte
    return (i + 1); // Retourner l'index du pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi est l'index de partitionnement
        int pi = partition(arr, low, high);

        // Tri des éléments avant et après la partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
    int* arr = (int*)malloc(n * sizeof(int));
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

    // Appliquer le tri Quick Sort
    t1 = clock();
    quickSort(arr, 0, n - 1);
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
