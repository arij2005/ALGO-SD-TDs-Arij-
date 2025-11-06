#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap_int(int *a, int *b);
int is_sorted_nondecreasing(int *tab, int n);
void copy_array(int *src, int *dest, int n);


void selection_sort(int *tab, int n);
void insertion_sort(int *tab, int n);
void bubble_sort(int *tab, int n);


void merge_sort(int *tab, int left, int right);
void quick_sort(int *tab, int left, int right);

// Comparaison des temps
void compare_sort_algorithms(int *tab, int n);

#endif
