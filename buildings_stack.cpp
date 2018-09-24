#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int>s;
     int arr[7]={80,60,70,60,75,85,83};
     int ar[7];
	 for(int i=0;i<7;i++)
	 {
	 	if(s.empty())
	 	{
	 		s.push(i);
	 		ar[i]=i+1;
		 }
		 else if(arr[s.top()]<arr[i])
		 {
		 	int val=arr[s.top()];
		 	s.pop();
		 	
		 	i--;
		 	continue;
		 }
		 else
		 {
		 	
		 	ar[i]=i-s.top();
            s.push(i);		 
		 }
	 }
	 for(int j=0;j<7;j++)
	 {
	 	cout<<ar[j]<<" ";
	 }
	 	return 0;
}
	
