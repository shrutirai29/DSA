#include<stdio.h>

int fact(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * fact(n - 1);
}

int main(){
    printf("Enter the value of n and k: ");
    int n, k;
    scanf("%d %d", &n, &k);
    int result = fact(n) / (fact(k) * fact(n - k));
    printf("Binomial Coefficient of %d and %d is %d\n", n, k, result);
}