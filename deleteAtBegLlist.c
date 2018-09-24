#include<stdio.h>
struct node{
	int data;
	struct node *next;
};
struct node* createnew()
{
	struct node*nn=(struct node*)malloc(sizeof(struct node));
	return nn;
}
void add (struct node **h , int value) {
	
	struct node*nn=createnew();
	nn->data=value;
	nn->next=NULL;

	if(*h==NULL)
	{
	    *h=nn;
	}
	else
	{
			struct node *n=*h;
			while (n->next)
	       {
	        	n=n->next;
           }
	n->next=nn;
	}
} 

void delab(struct node**h)
{
	struct node *n=*h;
	if (*h!=NULL) {
			*h=(*h)->next;
	         free(n);
	        n=NULL;
	}
}
int main()
{
	struct node *h=NULL;
	int i=5,j=0;
	while (i--) {   
	    j++;
	   // printf("%d",j);
		add(&h,j);
		
	}
	printf("List is:\n");
	struct node *n=h;
	while(n)
	{
		printf("%d ",n->data);
		n=n->next;
	}
	printf("\nHow many elements u want to delete:\n");
	int no;
	scanf("%d",&no);

	while (no--) {
		delab(&h);
	}
		printf("After deleting:\n");
	while(h)
	{
		printf("%d ",h->data);
		h=h->next;
	}
	
	return 0;
}
