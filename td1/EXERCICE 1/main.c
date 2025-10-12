#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main() {
    int n = 40;
    clock_t start, end;
    double temps;

    printf("Entrez n : ");
    scanf("%d", &n);

 
    start = clock();
    int resultat_naif = fibonacci_naif(n);
    end = clock();
    temps = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Naif      : F(%d) = %d | Temps = %.6f secondes\n", n, resultat_naif, temps);


    start = clock();
    int resultat_dynamique = fibonacci_dynamique(n);
    end = clock();
    temps = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Dynamique : F(%d) = %d | Temps = %.6f secondes\n", n, resultat_dynamique, temps);

    return 0;
}
