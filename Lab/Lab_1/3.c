// #include <stdio.h>

// int main()
// {
//     int sec, h, m, s;
//     printf("Input Seconds: ");
//     scanf("%d", &sec);
    
//     h = sec / 3600;
//     m =(sec - (3600*h))/ 60;
//     s =(sec - (3600*h) - (60*m));

//     printf("H:M:S - %d:%d:%d\n", h, m, s);
//     return 0;
// }

#include<stdio.h> 
int  main() 
{ 
   unsigned int x = -1; 
   int y = ~0; 
   if (x == y) 
      printf("same"); 
   else
      printf("not same"); 
   return 0; 
}