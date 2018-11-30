#include<stdio.h>
//defining node 
typedef struct node{
	int data;
	struct node* next;
	
}node;
node* createnode()
{
	node* nn=(node *)malloc(sizeof(node));
	return nn;
}
//Adding node at beginning
void addnodebeg(node **h,int value)
{
	node *nn=createnode();
	nn->data=value;
	nn->next=*h;
	*h=nn;
}
void iterate(node** h)
{
		node* temp=*h;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}
//Adding at a certain position
void addbetween(node **head,int pos)
{
	int value;
  		printf("enter value\n");
  		scanf("%d",&value);
  	if(pos==1)
  	{
  		
  		addnodebeg(&head,value);
	}
	  else
	  {
	  int p=1;
	  node * temp=*head;
	  	while(p<pos-1 && temp )
	  	{
	  		temp=temp->next;
	  		p++;
		  }
	  
	  if(temp==NULL)
	  {
	  	printf("position no there");
	  }
	  else
	  {
	  	node* nn=createnode();
	  	nn->data=value;
	  	nn->next=temp->next;
	  	temp->next=nn;
	  	
	  }
}
}
//Adding at last position
void addnodelast(node ** head)
{
	node * temp=*head;
	while(temp && temp->next)
	{
		temp=temp->next;
	}
	node * nn=createnode();
	
		if(temp==NULL)
		{
			*head=nn;
		
		}
		else
	{
	temp->next=nn;
	nn->next=NULL;
	nn->data=20;	
 	}
}
int main()
{
	node * head=NULL;
	addnodebeg(&head,10); 
	addnodelast(&head);
	int pos;
	printf("Enter the position\n");
	scanf("%d",&pos);
	addbetween(&head,pos);
	iterate(&head);
	return 0;
}
