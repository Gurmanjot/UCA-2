#include<stdio.h>
int decimalToBinary(int num)
{
 if(num == 0)
   return 0;
  
  return 10 * decimalToBinary ( num / 2 ) + ( num % 2 );
}
int main()
{
	int ans,num;
	scanf("%d",&num);
	ans = decimalToBinary(num);
	printf("%d",ans);
	return 0;
}

