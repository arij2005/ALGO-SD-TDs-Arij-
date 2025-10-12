#include "fibonacci.h"


int fibonacci_naif(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naif(n - 1) + fibonacci_naif(n - 2);
}


int fibonacci_dynamique(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, temps;
    for (int i = 2; i <= n; i++) {
        temps = a + b;
        a = b;
        b = temps;
    }
    return b;
}
