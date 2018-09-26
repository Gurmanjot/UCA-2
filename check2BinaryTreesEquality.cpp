#include <iostream>
#include <stack>
#include <deque>
#include <stdlib.h>
using namespace std;
struct btreenode
{
	int data;
	struct btreenode *left;
	struct btreenode *right;
};

// Create new node

struct btreenode *createnew(int val)
{
	struct btreenode *nn = (struct btreenode *)malloc(sizeof(struct btreenode));
	nn->left = NULL;
	nn->data=val;
	nn->right = NULL;
	return nn;
}

void push(struct btreenode**h,int val) {
	
  struct btreenode *n=createnew(val);
  
   if ( *h == NULL ) {
   	 *h = n;
   }
   else
   {
   	   deque<struct btreenode*>q;
   	   q.push_back(*h); 
   	   while ( !q.empty() ) {
   	   	  struct btreenode *temp=q.front();
   	   	    q.pop_front();
   	   	   
   	   	    if(!temp->left) {
   	   	    	temp->left=n;
				  return;
				  }
		    if(!temp->right) {
		    	temp->right=n;
		    	return;
			}		  
   	   	     
   	   	   q.push_back(temp->left);
   	   	   q.push_back(temp->right);
		  }
   	  
   	
   }
	
}
int checkTrees(struct btreenode*one,struct btreenode*two){
	
	if(one==NULL && two==NULL)
	  return 1;
	
	if(one->data!=two->data){
		return 0;
	}
	
  return checkTrees(one->left,two->left) && checkTrees(one->right,two->right);
	}
int main(){
	
	struct btreenode* one=NULL;
	struct btreenode* two=NULL;
	
	push(&one, 10);
	push(&one, 20);
	push(&one, 30);
	push(&one, 40);
	push(&one, 50);
	push(&one, 60);
	push(&one, 70);
	push(&one, 80);
	
	push(&two, 10);
	push(&two, 20);
	push(&two, 30);
	push(&two, 40);
	push(&two, 50);
	push(&two, 60);
	push(&two, 70);
	push(&two, 80);
	
	int check=checkTrees(one,two);
	 if(check==1)
	 {
	 	cout<<"yes";
	 }
	 else
	 cout<<"no";
	
	return 0;
}
