#include<stdio.h>

int evenDigits ( int num ) {
  if ( num < 0 ) {
    return -evenDigits ( -num );
  }
  if( num < 10 && num%2 == 0 ) {
    return num;
  }
  if( ( num % 10 ) % 2 == 0 ) {
    return 10*(evenDigits(num/10))+num%10;
  }
  else
    return evenDigits(num/10);
}
int main() {
	int num,final;
	printf("Enter the number :\n");
	scanf("%d",&num);
	final=evenDigits ( num );
	printf("The new number is :\n");
	printf("%d",final);
	return 0;
}

