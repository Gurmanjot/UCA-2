#include<iostream>
using namespace std;
#include<stack>
#include<string.h>
int main()
{
	stack<char>s;
	stack<char*>a;
	int size,flag=0;
	cout<<"Enter the size:"<<endl;
	cin>>size;
	if(size%2!=0)
	{
		cout<<"not possible ";
		return 0;
	}
	char arr[size][200];
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	for(int j=0;j<size;j++){
    	if(arr[j][1]=='/')
		{
				char c[100];
			int len=strlen(arr[j]);
	          	
		for(int k=1;k<len-1;k++)
		{
			arr[j][k]=arr[j][k+1];
	    }
	     arr[j][len-1]='\0';
			
			if(a.empty())
			{
				flag=0;
				break;
			}
			if((strcmp(a.top(),arr[j]))==0)
			{
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
			
			a.pop();
	   }
		else
		{
			a.push(arr[j]);
		}
	//	cout<<arr[j]<<endl;
	}
	if(flag==0)
	cout<<"invalid"<<endl;
	else
	{
		cout<<"valid"<<endl;
	}
return 0;	
}
