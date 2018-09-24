#include<stdio.h>
#include<string.h>
int main()
{
	  int no;
   
	 int arr[7],ar[7];
    scanf("%d",&no);
  if(no==0)
  {
    printf("zero");
    return;
  }
	 int i;
	  
	 for(i=0;i<7;i++)
	 {
	 	arr[i]=no%10;
	 	no=no/10;
	 }
	
	 int j,k=6;
	 for(j=0;j<7;j++)
	 {
	   ar[j]=arr[k--];
	 }
	 
	 char ones[][20]={"one","two","three","four","five","six","seven","eight","nine"};
	 char tens[][20]={"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	 char  ten[][20]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
	 char hund[][20]={"hundred","thousand","lakh"};
	 
	 
  // lakhs
  if(ar[0]!=0 || ar[1]!=0)
  {
    if(ar[0]==1&&ar[1]!=0)
	    	{
	    		printf("%s ",tens[ar[1]]);
			}
			else if(ar[0]==1 && ar[1]==0)
			{
				printf("%s ",ten[0]);
			}
			else if(arr[0]!=1 && arr[0]!=0)
			{
				printf("%s ",ten[ar[0]-1]);
				printf("%s ",ones[ar[1]-1]);
			}
			else if(arr[1]!=0)
			{
					printf("%s ",ones[ar[1]-1]);
			}
		printf("lakhs ");	 
  }
	    	
	
// thousands
  if(ar[2]!=0 || ar[3]!=0)
  {
    if(ar[2]==1&&ar[3]!=0)
	    	{
	    		printf("%s ",tens[ar[3]]);
			}
			else if(ar[2]==1 && ar[1]==0)
			{
				printf("%s ",ten[0]);
			}
			else if(arr[2]!=1)
			{
				printf("%s ",ten[ar[2]-1]);
				printf("%s ",ones[ar[3]-1]);
			}
		printf("thousand ");
    
  }
  	
//
 
   if(ar[4]!=0)
   {
   		printf("%s ",ones[ar[4]-1]);
            if(ar[5]==0 && ar[6]==0)
            {
            		printf("hundred");
			}
			else
    	 	printf("hundred ");
   }
     //ones 
   if(ar[5]!=0 || ar[6]!=0)
   {
     if(ar[5]==1&&ar[6]!=0)
	    	{
	    		printf("%s",tens[ar[6]]);
			}
			else if(ar[5]==1 && ar[6]==0)
			{
				printf("%s",ten[0]);
			}
			else if(arr[5]!=1)
			{
				printf("%s ",ten[ar[5]-1]);
				printf("%s",ones[ar[6]-1]);
			}    	 	
     
   }
	
		printf("\n");
	return 0;
}



