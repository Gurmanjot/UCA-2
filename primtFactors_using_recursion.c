#include <stdio.h>
int isPrime(int num)
{
   int q,flag;
 
  for(q=2;q<=num;q++)
  {
    if(num%q==0)
    {
      flag=q;
      break;
    }
    
  }
  if(flag==num)
  {
   return 1;
  }
  else
    return 0;
}
int factors(int i)
{
  int q,check;
  if(i==0)
  {
    return 0;
  }
  for(q=2;q<=i;q++)
  {
    check=isPrime(q);
    if(check==1 && (i%q==0))
    {
      printf("%d\n",q);
      return factors(i/q);
    }
    else
      continue;
  }
}
int main()
{
   int number;
   printf("Enter a number :\n");
   scanf("%d",&number);
   printf("Factors are :\n");
   factors(number);
   return 0;
}
