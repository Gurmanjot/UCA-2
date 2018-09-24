#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node * next;
};

void check(struct node **h)
{
	struct Node *slow=*h,*fast=*h;
	int flag=0;
	while(fast && fast->next)
	{
		fast=fast->next->next;
		slow=slow->next;	
			if(slow==fast)
	{
		slow=*h;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
		printf("%d\n",slow->data);
		break;
	}
	
	
	}

	
}

int main()
{
	struct Node* start=NULL;
struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
struct Node* fourth = NULL;  

   head = (struct Node*)malloc(sizeof(struct Node)); 
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
   fourth = (struct Node*)malloc(sizeof(struct Node));
  
     head->data = 1; 
     head->next = second;
     second->data = 2; 
     second->next = third;
     third->data = 3; 
     third->next = fourth;
    fourth->data = 4; 
     fourth->next = second;
     start=head;
	 check(&start);
	return 0;
}
