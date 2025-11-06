#include "fonctions.h"

int main() {
    int n = 10000; 
    int *tab = malloc(n * sizeof(int));

    
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100000;

  
    compare_sort_algorithms(tab, n);

    free(tab);
    return 0;
}
