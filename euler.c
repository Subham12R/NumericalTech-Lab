#include <stdio.h>

float f(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, h, xn;
    float x, y, y_predict, y_correct;

    printf("Enter initial x0, y0: ");
    scanf("%f %f", &x0, &y0);

    printf("Enter step size h: ");
    scanf("%f", &h);

    printf("Enter value of xn: ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    while (x < xn) {
        
        y_predict = y + h * f(x, y);
        y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_predict));

        x = x + h;
        y = y_correct;

        printf("x = %.2f, y = %.4f\n", x, y);
    }

    printf("\nFinal value at x = %.2f is y = %.4f\n", xn, y);

    return 0;
}