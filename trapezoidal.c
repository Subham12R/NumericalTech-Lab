#include <stdio.h>

double func(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    int n, i = 1;
    double a, b, h, sum, result, x;

    printf("Enter lower limit (a): ");
    scanf("%lf", &a);

    printf("Enter upper limit (b): ");
    scanf("%lf", &b);

    printf("Enter number of intervals (n): ");
    scanf("%d", &n);

    h = (b - a) / n;

    sum = func(a) + func(b);

    while (i < n) {
        x = a + i * h;
        sum = sum + 2 * func(x);
        i++;
    }

    result = (h * sum) / 2;

    printf("\nApproximate value of integral = %.6lf\n", result);

    return 0;
}