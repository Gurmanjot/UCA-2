#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
void push(struct node **h,int val){
	
	struct node * nn =(struct node *)malloc(sizeof(struct node));
	nn->data=val;
	nn->next=*h;
	*h=nn;
}
//bubble sort
void sort(struct node *h)
{
	if(h==NULL)
	{
		printf("list empty:");
		return 0;
	}
	else
	{
		struct node *nn=h;
        int i,j,swap;
 	  for(i=0;i<4;i++)
 	  {
 	  	nn=h;
 	  	for(j=0;j<4;j++)
			{
		        if((nn->data)>(nn->next->data))
				{
					swap=nn->data;
					nn->data=nn->next->data;
					nn->next->data=swap;
				}
				nn=nn->next;		
		    }
	   }
			
		
	}
}

//print list
void print(struct node *h){
		struct node *nn=h;
		while(nn){
			printf("%d\n",nn->data);
			nn=nn->next;
		}
	
}
int main()
{
	struct node *h=NULL;
	push(&h,100);
	push(&h,50);
	push(&h,20);
	push(&h,90);
	push(&h,60);
	
    sort(h);
    print(h);
	return 0;
}
      

