#include "fonctions.h"

int main() {
    int n = 100000; 
    int *tab = malloc(n * sizeof(int));

   
    for (int i = 0; i < n; i++)
        tab[i] = i * 2; 

    int value = 98764; 

    printf("Comparaison des algorithmes de recherche :\n");
    compare_search_algorithms(tab, n, value);

    free(tab);
    return 0;
}


