#include<stdio.h>

int i, n; 

int main()
{
    scanf("%d", &n);
    int x[n];
    x[0] = 0;
    x[1] = 1; 

    for (i=1; i <= n; i++)
    {     
        x[i+1] =  x[i] + x[i-1];
        printf("%d ", x[i-1]);
    }
    return 0;
}