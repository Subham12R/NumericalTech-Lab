//Solve the linear system of equations using the Gauss-Seidel method upto 6 decimal places of accuracy.

// 10x1 + 3x2 + 2x3 = 15
// 4x1 + 6x2 + 2x3 = 12
// 3x1 + 5x2 + 8x3 = 16

#include <stdio.h>
#include <math.h>

int main() {
    double a11, a12, a13, b1;
    double a21, a22, a23, b2;
    double a31, a32, a33, b3;

    double x1_0, x2_0, x3_0;
    double x1, x2, x3;
    double e1, e2, e3;

    const double e = 0.000001;
    int step = 1;

    printf("Enter coefficients and constants for:\n");
    printf("a11*x1 + a12*x2 + a13*x3 = b1\n");
    printf("a21*x1 + a22*x2 + a23*x3 = b2\n");
    printf("a31*x1 + a32*x2 + a33*x3 = b3\n\n");

    printf("Enter a11 a12 a13 b1: ");
    scanf("%lf %lf %lf %lf", &a11, &a12, &a13, &b1);

    printf("Enter a21 a22 a23 b2: ");
    scanf("%lf %lf %lf %lf", &a21, &a22, &a23, &b2);

    printf("Enter a31 a32 a33 b3: ");
    scanf("%lf %lf %lf %lf", &a31, &a32, &a33, &b3);

    if (a11 == 0 || a22 == 0 || a33 == 0) {
        printf("Diagonal coefficients (a11, a22, a33) must be non-zero.\n");
        return 1;
    }

    printf("\nEnter initial guess for x1, x2, x3: ");
    scanf("%lf %lf %lf", &x1_0, &x2_0, &x3_0);

    printf("\nGauss-Seidel Method\n");

    do {
        x1 = (b1 - a12 * x2_0 - a13 * x3_0) / a11;
        x2 = (b2 - a21 * x1 - a23 * x3_0) / a22;
        x3 = (b3 - a31 * x1 - a32 * x2) / a33;

        e1 = fabs(x1 - x1_0);
        e2 = fabs(x2 - x2_0);
        e3 = fabs(x3 - x3_0);

        printf("Step %d: x1 = %.6lf, x2 = %.6lf, x3 = %.6lf\n", step, x1, x2, x3);

        x1_0 = x1;
        x2_0 = x2;
        x3_0 = x3;
        step++;
    } while (e1 > e || e2 > e || e3 > e);

    printf("\nSolution: x1 = %.6lf, x2 = %.6lf, x3 = %.6lf\n", x1, x2, x3);

    return 0;
}