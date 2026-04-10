#include <stdio.h>

float f(float x) {
    return x / (1 + x);
}

int main() {
    int n, i;
    float a, b, h, sum_odd = 0, sum_even = 0, result;

    printf("Enter lower limit (a): ");
    scanf("%f", &a);

    printf("Enter upper limit (b): ");
    scanf("%f", &b);

    printf("Enter number of intervals (even n): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Error! n must be even.\n");
        return 1;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i += 2) {
        sum_odd += f(a + i * h);
    }

    for (i = 2; i < n; i += 2) {
        sum_even += f(a + i * h);
    }

    result = (h / 3) * (f(a) + f(b) + 4 * sum_odd + 2 * sum_even);

    printf("Approximate value of integral = %.4f\n", result);

    return 0;
}