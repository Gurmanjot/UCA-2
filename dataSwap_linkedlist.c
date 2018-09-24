#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
struct node* create()
{
	struct node * nn=(struct node *)malloc(sizeof(struct node));
	return nn;
}
void swap(struct node ** h)
{
	struct node * temp=(*h)->next;
	struct node * prev=*h;
	int i=0;
     while(temp)
	 {
	 	if(i%2==0)
		 {
			prev->data=prev->data+temp->data;
			temp->data=prev->data-temp->data;
			prev->data=prev->data-temp->data; 	
		}	
		i++;
		prev=temp;
		temp=temp->next;
	 }	
	
}
void insertatbeg(struct node**h,int data)
{
	struct node * temp=create();
	temp->data=data;
	if(*h==NULL)
	{
		temp->next=NULL;
		*h=temp;
	}
	else
    {
	 temp->next=*h;
     *h=temp;
	 }
}
void print(struct node * h)
{
		struct node * temp=h;
		while(temp)
		{
			printf("%d \n",temp->data);
			temp=temp->next;
		}
		
}
int main()
{
	struct node * head=NULL;
	int size;
	 printf("Number of elements \n");
	 scanf("%d",&size);
    int i;
    while(size--)
    {
    	scanf("%d",&i);
    	insertatbeg(&head,i);
	}
	printf("elements after insertion\n");
	print(head);
    printf("After swap\n");
    swap(&head);
    print(head);
    return 0;
}
