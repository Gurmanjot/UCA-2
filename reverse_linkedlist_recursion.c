#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
struct node * head=NULL;
struct node * createnew()
{
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	return nn;
}
void push(struct node **h,int value)
{
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=value;
	nn->next=*h;
	*h=nn;
	
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
void print(struct node **h)
{
		struct node *nn=*h;
		while(nn)
		{
			printf("%d ",nn->data);
			nn=nn->next;
		}
	
}
void reverse(struct node * prev,struct node *curr)
{
     if(curr)
	 {
	    reverse(curr,curr->next);
		curr->next=prev;	
	 }
	 else	
	 {
	 	head=prev;
	 }
}
int main()
{
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
	print(&head);
    reverse(NULL,head);
    printf("\n after reverse\n");
    print(&head);
	return 0;
}

