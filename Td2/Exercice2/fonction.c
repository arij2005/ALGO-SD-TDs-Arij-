#include "fonctions.h"


void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int is_sorted_nondecreasing(int *tab, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (tab[i] > tab[i + 1])
            return 0;
    }
    return 1;
}


void copy_array(int *src, int *dest, int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}


void selection_sort(int *tab, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (tab[j] < tab[min_index])
                min_index = j;
        }
        swap_int(&tab[i], &tab[min_index]);
    }
}

void insertion_sort(int *tab, int n) {
    for (int i = 1; i < n; i++) {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}


void bubble_sort(int *tab, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tab[j] > tab[j + 1])
                swap_int(&tab[j], &tab[j + 1]);
        }
    }
}


void merge(int *tab, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = tab[left + i];
    for (int j = 0; j < n2; j++) R[j] = tab[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            tab[k++] = L[i++];
        else
            tab[k++] = R[j++];
    }
    while (i < n1) tab[k++] = L[i++];
    while (j < n2) tab[k++] = R[j++];

    free(L);
    free(R);
}


void merge_sort(int *tab, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(tab, left, mid);
        merge_sort(tab, mid + 1, right);
        merge(tab, left, mid, right);
    }
}


int partition(int *tab, int left, int right) {
    int pivot = tab[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (tab[j] <= pivot) {
            i++;
            swap_int(&tab[i], &tab[j]);
        }
    }
    swap_int(&tab[i + 1], &tab[right]);
    return i + 1;
}

void quick_sort(int *tab, int left, int right) {
    if (left < right) {
        int pi = partition(tab, left, right);
        quick_sort(tab, left, pi - 1);
        quick_sort(tab, pi + 1, right);
    }
}


void compare_sort_algorithms(int *tab, int n) {
    clock_t start, end;
    double t;

    int *tmp = malloc(n * sizeof(int));

    printf("\nComparaison des algorithmes de tri :\n");

    copy_array(tab, tmp, n);
    start = clock();
    selection_sort(tmp, n);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tri par sélection : %.6f s\n", t);

    copy_array(tab, tmp, n);
    start = clock();
    insertion_sort(tmp, n);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tri par insertion : %.6f s\n", t);

    copy_array(tab, tmp, n);
    start = clock();
    bubble_sort(tmp, n);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tri à bulles      : %.6f s\n", t);

    copy_array(tab, tmp, n);
    start = clock();
    merge_sort(tmp, 0, n - 1);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tri fusion        : %.6f s\n", t);

    copy_array(tab, tmp, n);
    start = clock();
    quick_sort(tmp, 0, n - 1);
    end = clock();
    t = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tri rapide        : %.6f s\n", t);

    free(tmp);
}
