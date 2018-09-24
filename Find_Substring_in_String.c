#include<stdio.h>
#include<string.h>
int main()
{
	char arr[20],find[20];
	gets(arr);
	gets(find);
	int i=0,j=0,x,flag=0;
	while(arr[i]!='\0')
	{
		if(arr[i]==find[j])
		{
			x=i;
			while(arr[i]!='\0' && find[j]!='\0'&& arr[i+j]==find[j])
			{
			  j++;
			}
			if(j==strlen(find))
			{
				flag=1;
				break;
			}
			
		}
		
		i++;
		
	}
	if(flag==1)
	{
		printf("%d",x+1 );
	}
	else
		printf("not found");
	return 0;
}
