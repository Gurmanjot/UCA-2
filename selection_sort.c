#include<stdio.h>
int main()
{

	int arr[5]={2,1,5,3,4};

	int i,j,swap;

	for(i=0;i<4;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(arr[j]<arr[i])
			{
			   swap=arr[j];
			   arr[j]=arr[i];
			   arr[i]=swap;	
			}
		}
	}
	
		for(i=0;i<5;i++)
	{
	printf("%d  ",arr[i]);
	}
	return 0;
}
