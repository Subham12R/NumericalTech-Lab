#include <stdio.h>

// Function f(x, y) = x + y
float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, xn;
    float x, y, k1, k2, k3, k4;

    printf("Enter x0, y0: ");
    scanf("%f %f", &x0, &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter xn: ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    while (x < xn) {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;

        printf("x = %.2f, y = %.5f\n", x, y);
    }

    printf("\nFinal value at x = %.2f is y = %.5f\n", xn, y);

    return 0;
}