#include<stdio.h>
int main()
{
	int arr[6]={4,2,7,5,1,9};
	int i,j,swap;
	for(i=1;i<6;i++)
	{
		j=i;
		while(j>0 && arr[j]<arr[j-1])
		{
			swap=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=swap;
			
			j--;
		}
	}
	for(i=0;i<6;i++)
	{
		printf("%d ",arr[i]);
	}
	return 00;
}
