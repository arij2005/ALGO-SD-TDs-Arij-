#include <stdio.h>
#include "premiers.h"

int est_premier(int n) {
    if (n <= 1) return 0; 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; 
    }
    return 1; 
}

void afficher_nombres_premiers(int n) {
    int tableau[1000];
    for (int i = 0; i <= n; i++) {
        tableau[i] = 1;
    }

    for (int i = 2; i * i <= n; i++) {
        if (tableau[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                tableau[j] = 0;
            }
        }
    }

    printf("Nombres premiers entre 1 et %d : ", n);
    for (int i = 2; i <= n; i++) {
        if (tableau[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

