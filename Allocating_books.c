#include<stdio.h>
#include<stdlib.h>

int main()
{
    int size;
	printf("enter size:\n");
	scanf("%d",&size);
	int arr[size];
	int i,max=0;
	int students;
	printf("\nenter students:\n");
	scanf("%d",&students);
	for(i=0;i<size;i++)
	{ 
	    scanf("%d",&arr[i]);
		max=max+arr[i];
	}

	int min=arr[0];	
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	printf("\n");
	printf("%d  %d\n",min,max);
	while(min<max)
 {
    int mid=(min+max)/2;
	printf("mid=%d\n",mid);
    int k=1,j=0,sum=0,w;
	for(w=0;w<size;w++) {
            if(sum+arr[w]<=mid)
			{
			  sum=sum+arr[w];	
			}	
			else
			{
				++k;
				printf("-");
				sum=arr[w];
			}
			printf("%d ",sum);
     } 
	printf("k=%d \n",k);
    printf("\n");
	
	  if(k<=students)
	  {
	  	max=mid;
	  }
	  else
	  min=mid+1;
 }

printf("ans = %d",max);
	
	return 0;
}
