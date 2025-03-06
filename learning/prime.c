#include <stdio.h>

int main(){
    int n, i;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (i = 2; i*i < n; i++){
        if (n % i == 0){
            printf("Not a prime number\n");
            break;
        }
        else{
            printf("Prime number\n");
            break;
        }
    }
}