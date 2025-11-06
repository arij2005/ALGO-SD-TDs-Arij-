#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


int is_sorted_nondecreasing(int *tab, int n);


int min_int(int *tab, int n);


int linear_search(int *tab, int n, int value);
int jump_search(int *tab, int n, int value);
int binary_search(int *tab, int n, int value);


void compare_search_algorithms(int *tab, int n, int value);

#endif

