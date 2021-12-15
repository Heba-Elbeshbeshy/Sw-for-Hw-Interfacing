#include <stdio.h> 

int Factorial(int number)
{  
  int fact =1;
  for(int itr=1; itr <= number; itr++) 
    fact=fact*itr; 

  return fact;
}

int power(int base, int power_number){

  int itr, result = 1;
  if (power_number == 0)
    return result;

  else if (power_number >= 1)
  {
    for(itr=1; itr <= power_number; itr++)
      result *= base;

    return result;
  }       
}

double Exp_Taylor(int exponent, int number_of_iteration)
{
  double term=0;

  if (number_of_iteration == 1)
    return 1;

  else 
  {
    for(int itr=1; itr <= number_of_iteration; itr++)
      term += (double)power(exponent, itr)/(double)Factorial(itr);

    return term;
  }  
} 

int main ()
{
  int exponent , number_of_iteration;
  double Exp;
  printf("Enter the exponent: "); 
  scanf("%d",&exponent); 
  printf("Enter the number of iteration : ");  
  scanf("%d",&number_of_iteration);
  
  Exp = Exp_Taylor(exponent, number_of_iteration);
  printf("The exponential function using Taylor series is: %lf", Exp);  
  return 0;
}
