#include <stdio.h>
#include <math.h>

#define LIMIT 15


long factorial(int);
double deg_to_rad(double);
double sine(double);

int main() {
    int i;
    double deg, rad, value;
    printf("Enter the value in degree: ");
    scanf("%lf", &deg);
    rad = deg_to_rad(deg);
    value = sine(rad);
    printf("sin(%.2lf)  =  %.2lf\n", deg, value);
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

double deg_to_rad(double deg) {
    return M_PI * deg / 180.0;
}

double sine(double rad) {
    int i, flag = 1;
    double sum = 0.0;

    for(i=1; i<LIMIT; i+=2) {
        sum += flag * pow(rad, i) / factorial(i);
        flag *= -1;
    }
    return sum;
}