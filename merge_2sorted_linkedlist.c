#include<stdio.h>
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

void print(struct node *h)
{
		struct node *nn=h;
		while(nn)
		{
			printf("%d ",nn->data);
			nn=nn->next;
		}
}
struct node * combine(struct node *a,struct node *b)
{
	struct node *c=NULL;
	struct node *one=a;
	struct node *two=b;
	struct  node *final;
		if(one->data < two->data)
    	{
		c=one;
		a=a->next;
		one->next=NULL;
        }
	    else
    	{
		c=two;
		b=b->next;
		two->next=NULL;
		}
	final=c;
  while(a!=NULL && b!=NULL	)
  {
  	 one=a;
  	 two=b;
  	 //	printf("1= %d   2= %d \n",a->data,b->data);
  		if(one->data < two->data)
	{
		c->next=one;
			a=a->next;
		one->next=NULL;
	//	print(a);
	}
	else
	{
		c->next=two;
		b=b->next;
		two->next=NULL;
	}
  	c=c->next;
  }
  
  if(a==NULL)
  {
  		c->next=b;
  		c=c->next;
   }
  else
  {
  		c->next=a;
        c=c->next;
  }
 
  print(final);
  return c;
}
int main()
{
    struct node *first =NULL;
	struct node *second=NULL;
	struct node *final =NULL;
     
   	push(&first,60);
	push(&first,40);
	push(&first,30);
	push(&first,20);
	push(&first,10);

    push(&second,110);
	push(&second,85);
	push(&second,42);
    push(&second,27);
	push(&second,13);	
	
	final=combine(first,second);
    return 0;
}
