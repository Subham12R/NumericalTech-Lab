#include <stdio.h>

int main()
{
    int i, j, k, n;
    float a[20][20], x[20], ratio, sum;

    printf("Enter number of equations: ");
    scanf("%d", &n);

    printf("Enter augmented matrix coefficients:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward Elimination
    for(j = 0; j < n - 1; j++)
    {
        for(i = j + 1; i < n; i++)
        {
            ratio = a[i][j] / a[j][j];
            for(k = 0; k <= n; k++)
            {
                a[i][k] = a[i][k] - ratio * a[j][k];
            }
        }
    }

    // Back Substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for(j = i + 1; j < n; j++)
        {
            sum = sum + a[i][j] * x[j];
        }
        x[i] = (a[i][n] - sum) / a[i][i];
    }

    // Output
    printf("\nSolution:\n");
    for(i = 0; i < n; i++)
    {
        printf("x%d = %.2f\n", i + 1, x[i]);
    }

    return 0;
}