#include<iostream>
using namespace std;
#include<deque>
int main()
{
	deque<int>q;
int size;
cout<<"enter size"<<endl;
 cin>>size;
 cout<<"enter elements"<<endl;
 int arr[size];
 for(int q=0;q<size;q++)
 {
 	cin>>arr[q];
 }
cout<<"enter window"<<endl;
 int k;
 cin>>k;
	int i;
	for( i=0;i<k;++i)
	{
	    while ( (!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        q.push_back(i);
		
	}
	

	for(;i<size;i++)
	{
		cout<<arr[q.front()]<<" ";
	
		while(!(q.empty()) && q.front()<=i-k)
		{
			q.pop_front();
		}
		
		
		 while ( (!q.empty()) && arr[i] >= arr[q.back()])
            q.pop_back();  // Remove from rear
 
        // Add new element at rear of queue
        q.push_back(i);
	}
	cout<<arr[q.front()];
	
	return 0;
}
