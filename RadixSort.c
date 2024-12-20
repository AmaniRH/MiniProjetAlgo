#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <time.h>

int key(int x, int i) {
    return (x / (int)pow(10, i)) % 10;
}

void auxiliaire_SortAux(int arr[], int n, int exp) {
    int output[n]; // tableau de sortie
    int count[10] = {0}; // tableau de comptage

    // Compter les occurrences
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modifier count[i] pour qu'il contienne la position réelle de ce chiffre dans output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Construire le tableau de sortie
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copier le tableau de sortie dans arr[], pour que arr[] contienne les nombres triés selon le chiffre courant
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void RadixSort(int arr[], int n) {
    // Trouver le maximum pour déterminer le nombre de chiffres
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Appliquer counting sort pour chaque chiffre
    for (int exp = 1; max / exp > 0; exp *= 10) {
        auxiliaire_SortAux(arr, n, exp);
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

    // Appliquer le tri "RadixSort"
     t1 = clock();
    RadixSort(arr, n);
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

