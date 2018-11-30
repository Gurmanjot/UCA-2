#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node * next;
};
void push(struct node **h,int value)
{
	struct node *nn=(struct node *)malloc(sizeof(struct node));
	nn->data=value;
	nn->next=*h;
	*h=nn;
	
}

void print(struct node *h)
{
		struct node *nn=h;
		while(nn)
		{
			printf("%d ",nn->data);
			nn=nn->next;
		}
	
}
struct node * rever(struct node * a)
{
	
	struct node * prev=NULL;
	struct node * next;
	struct node * curr=a;
//	int flag=0;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	
	
	return prev;
	
}
void rev(struct node * h)
{
	int first,second;
	printf("first index \n");
	scanf("%d",&first);
	printf("second index \n");
    scanf("%d",&second);
    struct node * n=h;
    struct node * nn=h;
    struct node * start=NULL;
    struct node * start_prev=NULL;
	struct node *  end=NULL;
    struct node *  end_next=NULL;
    
    int i=1;
    while(n && i<=second)
    {
    	if(i<first)
    	{
    		start_prev=n;
		}
		if(i==first)
		{
			start=n;
		}
		if(i==second)
    	{
    		end=n;
    		end_next=end->next;
		}
		n=n->next;
		i++;
	}
	end->next=NULL;
//	printf(" prev = %d   start = %d    end =%d    end_next = %d \n",start_prev->data,start->data,end->data,end_next->data);
        end=rever(start);
		if(start_prev)
		{
			start_prev->next=end;
		}
		else
		h=end;
		
		start->next=end_next;  
	printf("Reversed Linked list :\n");
    print(h);
  
	}
int main()
{
	struct node * head=NULL;

	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,60);
	push(&head,70);
	push(&head,80);
    push(&head,90);
	push(&head,100);
	printf("LINKED LIST :\n ");
	print(head);
	printf("\nreversed\n");
	rev(head);
//	print(head);
	return 0;
	
}
