#include <stdio.h>
#include "premiers.h"

int main() {
    int n = 10;
    int compteur = 0;

    for (int i = 2; i <= n; i++) {
        if (est_premier(i)) {
            compteur++;
        }
    }
    printf("Il y a %d nombres premiers entre 1 et %d\n", compteur, n);

    n = 20;
    afficher_nombres_premiers(n);

    return 0;
}
