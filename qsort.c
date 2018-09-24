#include<stdio.h>
#include<stdlib.h>
// compare function
int comp(void *x,void *y)
{
	return (*(int *)x)-(*(int *)y);
}
int main()
{
	printf("Enter the size of the array :\n");
	int size;
	scanf("%d",&size);
	int arr[size];
	int i;
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);
	}
	// qsort function
	qsort(arr,size,sizeof(int),comp);
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
