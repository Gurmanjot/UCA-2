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
void insertatbeg(struct node **h,int value)
{
	struct node * temp=create();
	temp->data=value;
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
int palindrome(struct node **h,struct node *l)
{
    if(l==NULL)
    {
    	return 1;
	}
	int y=palindrome(h,l->next);
	
	if(y==1)
	{
		if((*h)->data==l->data)
		{
			(*h)=(*h)->next;
			return 1;
		}
		else
		return 0;
		
	}
	else
	return 0;
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
	int flag=0;
	flag=palindrome(&head,head);
	if(flag==0)
	{
		printf("not");
	}
	else
	{
			printf("yes");
	}
	
	return 0;	
}
