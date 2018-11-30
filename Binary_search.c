#include<stdio.h>
int main()
{
	int size;
	printf("Enter the size of the sorted array :\n");
	scanf("%d",&size);
	int i;
	int arr[size];
	printf("Enter %d elements :\n",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	int number;
	printf("Enter thr number whose position you want to find :\n");
	scanf("%d",&number); 
	int left=0,right=size-1;
	while(left<=right)
	{
		int mid;
		mid=(left+right)/2;
		if(arr[mid]<number)
		{
			left=mid+1;
		}
		else if(arr[mid]==number)
		{
			printf("Number found at %d position",mid+1);
			return 0;
		}
		else
		{
			right=mid-1;
		}
		
	}
	return 0;
}
