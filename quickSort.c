#include<Stdio.h>
void swap(int *a,int *b)
{
	int q=*a;
	*a=*b;
	*b=q;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int j,i=low-1;
	for(j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
		swap(&arr[i+1],&arr[high]);
		return (i+1);
}

void qsort(int arr[],int low,int high)
{
	if(low<high)
	{
    	int p=partition(arr,low,high);
	
		qsort(arr,low,p-1);
	    qsort(arr,p+1,high);  
	}
}
int main()
{
	int arr[]={2,89,4,3,67,1,907,5,7,6};
	qsort(arr,0,9);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
