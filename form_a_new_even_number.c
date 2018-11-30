#include<stdio.h>

int evenDigits(int n)
{
  if(n<0)
  {
    return -evenDigits(-n);
  }
  if(n<10 && n%2==0)
  {
    return n;
  }
  if((n%10)%2==0)
  {
    return 10*(evenDigits(n/10))+n%10;
  }
  else
    return evenDigits(n/10);
  
}
int main()
{
	int num,final;
	printf("Enter the number :\n");
	scanf("%d",&num);
	final=evenDigits(num);
	printf("The new number is :\n");
	printf("%d",final);
	return 0;
}

