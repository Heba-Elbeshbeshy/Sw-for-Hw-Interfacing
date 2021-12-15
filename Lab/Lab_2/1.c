#include<stdio.h>

unsigned char x, n, x_left, x_right; 

int main()
{
    scanf("%hhu", &x);
    scanf("%hhu", &n);

    x_left  = (x<<n) | (x>>(8-n));
    x_right = (x>>n) | (x<<(8-n));

    printf("%d\n", x_left);
    printf("%d\n", x_right);

    return 0;
}
