//Find root of the equation 3x - cosX - 1 = 0 , by Newton Raphson Method. Correct up to six decimal places. 
// convergence condition for Newton Raphson Method. [f(x) * f" (x) / {f'(x)}^2] <1
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return (3 * (x)-cos(x) - 1);
}

float g(float x)
{
    return (3 + sin(x));
}

float H(float x)
{
    return cos(x);
}

int main()
{
    int n = 0;
    float h, x, x0, x1, x2, s, t, esp = 0.000001;
    printf("\nEnter the value of first approximation : ");
    scanf("%f", &x0);

    s = (f(x0) * H(x0));

    t = g(x0) * g(x0);

    if (fabs(s) > t)
    {
        printf("\nThe root can't found through the approximation.");
    }
    else
    {
        printf("\n \t xn+1 \t\t xn  \t\t hn \t\t f(n+1)");
        do
        {
            h = -(f(x0) / g(x0));
            x1 = x0;
            x0 = x0 + h;
            printf("\n %d \t %f \t %f \t %f \t %f \t", n, x1, x0, h, f(x0));
            n++;
        } while (fabs(x1 - x0) > esp);
        printf("\nThe root is = %f", x1);
    }
    return 0;
}