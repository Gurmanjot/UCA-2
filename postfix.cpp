#include<iostream>
using namespace std;
#include<string.h>
#include<stack>
#include<ctype.h>


int precedence(char a)
{
	if(a=='(' || a==')')
    {
		return -1;
	}
	else if(a=='+' || a=='-')
	{
		return 1;
	}
	else if(a=='*' || a=='/'|| a=='%')
	{
		return 2;
	}
	
}
int main()
{
	char arr[100];
	cout<<"Enter String"<<endl;
	gets(arr);
	stack<char>s;
	
	int len=strlen(arr);
    char ar[len];
 	int j=0;
	 for(int i=0;i<len;i++)
	{
		 if(arr[i]=='(')
	{
		 s.push(arr[i]);
	}	
	else if(isalpha(arr[i]))
	{
		ar[j]=arr[i];
		j++;
	}
	else if(arr[i]==')')
	{
		
		while(s.top()!='(')
		{
			ar[j++]=s.top();
			s.pop();
		}
		s.pop();
	}
	else
	{ 
	   while(precedence(s.top())>=precedence(arr[i]))
		   {
				char t=s.top();
				ar[j++]=t;
				s.pop();
			   
			}
			 s.push(arr[i]);
		
	}
		
    }
	printf("\n in stack\n");
     while(!s.empty())
	{
		printf("%c",s.top());
		s.pop();
	}
	printf("\n in string\n");
	puts(ar);
	return 0;
}
