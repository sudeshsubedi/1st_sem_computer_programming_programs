#include <stdio.h>

int main()
{
    int max, m, temp, n, a[25][25], j, i;
    printf("Enter the no row and columns of the matrix: \n");
    scanf("%d%d", &m, &n);
    printf("Enter the elements of matrix: \n");
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[j][i]);
        }
    }
    max = (m > n)?m:n;
    for(j=0; j<max; j++)
    {
        for(i=j; i<max; i++)
        {
            temp = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = temp;
        }
    }
    temp = m;
    m = n;
    n = temp;
    printf("The transposed matrix: \n");
    for(j=0; j<m; j++)
    {
        for(i=0; i<n; i++)
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}
