#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *arr;
	 int top;
};
void initialize(struct stack *mem,int siz)
{
	mem->arr=(int*)malloc(sizeof(int)*siz);
	mem->top=-1;
}
void push(struct stack *mem,int val)
{
    mem->top=mem->top+1;
    mem->arr[mem->top]=val;	
}
void pop(struct stack *mem)
{
	if(mem->top==-1)
	{
		printf("it's alredy empty:\n");
	}
	else
	{
		mem->top=(mem->top)-1;
	}
}
void top(struct stack *mem)
{
	if(mem->top==-1)
	  printf("LIST is empty");
	else
	  printf("%d\n",mem->arr[mem->top]);
}

void isEmpty(struct stack *mem)
{
	   if(mem->top==-1)
	   {
	   	printf("List is empty\n");
	   }
	   else
	   	printf("List is NOT empty\n");
}

void isFull(struct stack *mem,int size)
{
	   if(mem->top==size)
	   {
	   	printf("List is Full\n");
	   }
	   else
	   	printf("List is NOT  full\n");
}


int main()
{
	int size; 
	printf("enter the size:\n");
	scanf("%d",&size);
    struct stack head;
    initialize(&head,size);
    printf("Pushing\n");
	int val;

	int i=size;
	// if struct stack head then to access its value we use '.' else if it is a pinter we use '->';
	while(i--)
	{
	        printf("Enter Element\n");
	        	scanf("%d",&val);
			push(&head,val);
    }
    int j=0;
    for(j=0;j<size;j++)
    {
    	printf("%d ",head.arr[j]);
	}
    
	printf("\npop\n");
	int valu;
	printf("ENTER the no of elements u want to pop\n");
	scanf("%d",&valu);
	while(valu--)
	{
		pop(&head);
	}
	  for(j=0;j<=head.top;j++)
    {
    	printf("%d ",head.arr[j]);
	}
	
	printf("\nTOP\n");
	top(&head);
	  
	printf("Is empty\n");
	isEmpty(&head);  
	
	printf("Is Full\n");
	isFull(&head,size); 
	
//with switch	
/*	while(1)
	{
		printf("Enter the choice : \n1) push\n2)pop\n3)top\n4)isEmpty\n5)isFull\n6)exit\n");
		int value;
		scanf("%d",&value);
		switch(value){
			case 1:
			 {
			 	  printf("Enter Element\n");
	        	  scanf("%d",&val);
			      push(&head,val);
			      break;
			 }
			case 2:{
					printf("ENTER the no of elements u want to pop\n");
	                scanf("%d",&value);
				
				break;
			}
			case 3:{
				top(&head);
				break;
			}
			case 4:{
					isEmpty(&head); 
				break;
			}
			case 5:{
					isFull(&head,size); 
				break;
			}
			default:{
				
			exit(0);
			}
				
			 	
		}
		
		
	}
	
	*/
     return 0;
}
