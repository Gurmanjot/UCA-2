#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
struct node * createnew()
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	return nn;
}
void addatlast(struct node ** head,int value)
{
	struct node *nn=createnew();
	if(*head==NULL)
	{
		nn->data=value;
		nn->next=NULL;
		*head=nn;
	}
	else
	{
		struct node * temp=*head;
	while(temp->next)
	{
		temp=temp->next;
	}
	
	nn->data=value;
	nn->next=NULL;
	temp->next=nn;	
	}
}
void middle(struct node **h)
{
	struct node * slow=*h;
    struct node * fast=*h;
	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;
	}
	printf("%d ",slow->data);
	 
}
int main()
{
	struct node * head=NULL;
	int size;
	printf("enter the number of elements you want to enter\n");
	scanf("%d",&size);
	int i,value;
	for(i=0;i<size;i++)
	{
		printf("value at %d\n",i+1);
		scanf("%d",&value);
		addatlast(&head,value);
	}
	middle(&head);
	return 0;
}
