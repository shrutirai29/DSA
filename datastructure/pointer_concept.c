#include <stdio.h>

void swap(int* x, int* y) {
    int t;
    t = *x;
    *x = *y;
    *y = t;
}

void xyz(int x, int y) {
    int t;
    t = x;
    x = y;
    y = t;
}

int main() {
    int a = 10, b = 20;
    swap(&a, &b); 
    printf("Call by refrence: a = %d b = %d \n", a, b);
    xyz(a, b);
    printf("Call by value: a = %d b = %d", a, b);
    return 0;
}