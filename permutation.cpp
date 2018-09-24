#include<iostream>
#include<string.h>
using namespace std;
int main()
{
   string num;
   cin>>num;
   int len;
   len=num.size();
   int fact=1;
   for(int i=1;i<=len;i++)
   {
   	fact=fact*i;
   }
   int k=0;
   for(int i=0;i<fact/2;i++)
   {
   	
   	   for(int j=0;j<len;j++)
   	   {
   	        cout<<num[j];	
	   }
	   cout<<endl;
	   int temp;
	   temp=num[k];
	   num[k]=num[k+1];
	   num[k+1]=temp;
	   
	   if(k+1==(len-1))
	   {
	   	k=-1;
	   }
	   k++;
	  }
  	return 0;
}
