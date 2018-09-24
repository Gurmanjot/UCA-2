#include<stdio.h>
int main(){
	int arr[]={1,3,5,5,6,8},num,i,flag=-1;
	printf("enter the no\n");
	scanf("%d",&num);
	int left=0,right=6,mid;
	while(left<right)
	{
		mid=(left+right)/2;
	    if(num>arr[mid])
		{
			left=mid+1;
		}
		else 
		{
             right=mid;  			
		}
	}
	printf("lower = %d \n",right);
	left=0,right=6;
	while(left<right)
	{
			mid=(left+right)/2;
		if(num<arr[mid])
		{
			right=mid;
		}
		else
		{
			left=mid+1;
		}
	}
	printf("upper = %d \n",right);
    return 0;	
}
