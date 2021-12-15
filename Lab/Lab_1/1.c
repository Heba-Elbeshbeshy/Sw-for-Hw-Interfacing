#include<stdio.h>

int main()
{
    float u,a,t,v,s;
 
    printf("Enter initial velocity: ");
    scanf("%f",&u);
    printf("Enter acceleration: ");
    scanf("%f",&a);
    printf("Enter time required: "); 
    scanf("%f",&t); 

    v=u+a*t;
    s=(u*t)+(0.5*a*t*t);

    printf("\n%f",v);
    printf("\n%f\n",s);
}

