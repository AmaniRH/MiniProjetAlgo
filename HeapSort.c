#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i; // Initialiser le plus grand comme racine
    int left = 2 * i + 1; // Fils gauche
    int right = 2 * i + 2; // Fils droit

    // Si le fils gauche est plus grand que la racine
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Si le fils droit est plus grand que le plus grand jusqu'à présent
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Si le plus grand n'est pas la racine
    if (largest != i) {
        swap(&arr[i], &arr[largest]); // Échanger

        // Récursivement heapify la sous-arbre affecté
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Construire un max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Un par un extraire un élément du heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Déplacer la racine actuelle à la fin
        heapify(arr, i, 0); // Appliquer heapify sur le heap réduit
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

    // Appliquer le tri "Heap Sort"
     t1 = clock();  
    heapSort(arr, n);
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
