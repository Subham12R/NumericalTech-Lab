#include <stdio.h>
#include <math.h>

#define f1(x,y,z) (17 - y + 2*z) / 20
#define f2(x,y,z) (-18 - 3*x + z) / 20
#define f3(x,y,z) (25 - 2*x + 3*y) / 20

int main() {
    float x0 = 0, y0 = 0, z0 = 0; 
    float x1, y1, z1;
    float e1, e2, e3;
    float e = 0.0001;  
    int step = 1;

    printf("Gauss-Seidel Method\n");

    do {
    
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);  
        z1 = f3(x1, y1, z0);  

        // Calculate errors
        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);

        printf("Step %d: x = %.4f, y = %.4f, z = %.4f\n", step, x1, y1, z1);

        // Update values
        x0 = x1;
        y0 = y1;
        z0 = z1;

        step++;

    } while (e1 > e || e2 > e || e3 > e);

    printf("\nSolution: x = %.4f, y = %.4f, z = %.4f\n", x1, y1, z1);

    return 0;
}