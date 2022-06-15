#include <iostream>

// a >= b
int euclid_iterative(int a, int b) {
    while (a % b > 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

// a >= b, a > 0
int euclid_rec(int a, int b) {
    if (b == 0) {
        return a;
    }
    return euclid_rec(b, a % b);
}