#include <stdio.h>
#include <math.h>

int main()
{
    float x[10], y[10], p;
    float t, sum = 0;
    int i, j, n;

    printf("How many data values will be entered: ");
    scanf("%d", &n);

    /* Input x and f(x) values */
    for(i = 0; i < n; i++)
    {
        printf("\nEnter value of x[%d]: ", i);
        scanf("%f", &x[i]);

        printf("Enter value of f(x[%d]): ", i);
        scanf("%f", &y[i]);
    }

    /* Value to interpolate */
    printf("\nEnter the value of x for which f(x) is required: ");
    scanf("%f", &p);

    /* Lagrange Interpolation */
    for(i = 0; i < n; i++)
    {
        t = 1;
        for(j = 0; j < n; j++)
        {
            if(j != i)
            {
                t = t * ((p - x[j]) / (x[i] - x[j]));
            }
        }
        sum = sum + t * y[i];
    }

    printf("\nThe value of f(%0.2f) = %0.4f", p, sum);

    return 0;
}