#include "fonctions.h"


int is_sorted_nondecreasing(int *tab, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (tab[i] > tab[i + 1])
            return 0;
    }
    return 1;
}


int min_int(int *tab, int n) {
    int min = tab[0];
    for (int i = 1; i < n; i++) {
        if (tab[i] < min)
            min = tab[i];
    }
    return min;
}


int linear_search(int *tab, int n, int value) {
    for (int i = 0; i < n; i++) {
        if (tab[i] == value)
            return i;
    }
    return -1;
}


int jump_search(int *tab, int n, int value) {
    if (!is_sorted_nondecreasing(tab, n)) return -1;

    int step = sqrt(n);
    int prev = 0;

    while (tab[(step < n ? step : n) - 1] < value) {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    for (int i = prev; i < step && i < n; i++) {
        if (tab[i] == value)
            return i;
    }
    return -1;
}


int binary_search(int *tab, int n, int value) {
    if (!is_sorted_nondecreasing(tab, n)) return -1;

    int gauche = 0, droite = n - 1;
    while (gauche <= droite) {
        int milieu = (gauche + droite) / 2;

        if (tab[milieu] == value)
            return milieu;
        else if (tab[milieu] < value)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }
    return -1;
}

// Compare les temps d'exécution
void compare_search_algorithms(int *tab, int n, int value) {
    clock_t start, end;
    double time_linear, time_jump, time_binary;
    int index;

    // Linear search
    start = clock();
    index = linear_search(tab, n, value);
    end = clock();
    time_linear = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Linear Search: index=%d, temps=%.6f s\n", index, time_linear);

    // Jump search
    start = clock();
    index = jump_search(tab, n, value);
    end = clock();
    time_jump = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Jump Search  : index=%d, temps=%.6f s\n", index, time_jump);

    // Binary search
    start = clock();
    index = binary_search(tab, n, value);
    end = clock();
    time_binary = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Binary Search: index=%d, temps=%.6f s\n", index, time_binary);
}
