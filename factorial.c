#include <stdio.h>

long factorial(int n);

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %ld\n", n, factorial(n));
    return 0;
}


long factorial(int n) {
    long fact = 1;
    if(n < 0)
        return n;
    else if(n < 2)
        return 1;
    else
        while(n > 1) {
            fact *= n--;
        }
        return fact;
}