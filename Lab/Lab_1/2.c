#include <stdio.h> 
int main ()
{
    int a , b, c, Smallest, Largest;
    float AVG , Summ,  Product;

    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    
    AVG = (a + b + c) / 3;
    Summ = a + b + c ;
    Product = a * b * c;

    Smallest = a < b ? a : b ;
    Smallest = c < Smallest ? c : Smallest ;
    
    Largest = a > b ? a : b;
    Largest = c > Largest ? c : Largest;

    printf("The AVg : %f\n", AVG);
    printf("The Sum : %f\n", Summ);
    printf("The Product : %f\n", Product);
    printf("The Smallest : %d\n", Smallest);
    printf("The Largest : %d\n", Largest);
    return 0;
}