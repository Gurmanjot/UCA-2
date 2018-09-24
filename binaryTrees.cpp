#include<iostream>
using namespace std;
#include<deque>
#include<stack>
struct btreenode{
	int data;
	struct btreenode * left;
	struct btreenode * right;
};

struct btreenode* createnew(int val){
	struct btreenode *nn=new struct btreenode();
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
// pushing elemnets

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

// Pre order
void preorder(struct btreenode *h){
	
	if(h==NULL){
		cout<<"Empty tree"<<endl;
	}
	else
	{
		deque<struct btreenode*>q;
	     q.push_front(h);
	     
	     while(!q.empty()){
	     		struct btreenode *temp=q.front();
	     		q.pop_front();
	     	   if(temp->left && temp->right){
	     	    	cout<<temp->data<<" ";
	     	    	q.push_front(temp->right);
	     	    	q.push_front(temp->left);
				 }
				 else if(temp->left){
				 		cout<<temp->data<<" ";
				 		q.push_front(temp->left);
				 }
				 else if(temp->right)
				 {
				 		cout<<temp->data<<" ";
				 		q.push_front(temp->right);
				 }
				 else
				 {
				 	cout<<temp->data<<" ";
				 }
				 	
				 	
		 }
	}
}

//Post order

void postorder ( struct btreenode *h ) {
	
	  deque<struct btreenode*>q;
	  deque<int>final;
	  q.push_back(h);
	  while(!q.empty()){
	  	   	struct btreenode *temp=q.front();
	  	    final.push_front(temp->data);
	  	     q.pop_front();
	  	     
	  	    if(temp->left)
			 {
			 	q.push_front(temp->left);
			 }
			 if(temp->right)
			 {
			 	q.push_front(temp->right);
			 }
	  }
	    if(final.empty())
   {
   	cout<<"emptyy";
   }
	  while(!final.empty()){
	  	cout<<final.front()<<" ";
	  	 final.pop_front();
	  }
	
}

//Inorder

void inorder ( struct btreenode *h ) {
 stack<struct btreenode*>s;
   struct btreenode * curr=h;
 
      while(curr || !s.empty()){
      	
      	while(curr!=NULL)
      	{
      		s.push(curr);
      		curr=curr->left;
		}
		
		curr=s.top();
		s.pop();
		
		cout<<curr->data<<" ";
	   curr=curr->right;
	  }
}

//Level order

void levelorder ( struct btreenode *h ) {

	deque<struct btreenode*>q;
	q.push_back(h);
	while(!q.empty()) {
		struct btreenode *temp=q.front();
		q.pop_front();
		cout<<temp->data<<" ";
		
		if(temp->left)
		{
				q.push_back(temp->left);
		}
		
		if(temp->right)
		{
			q.push_back(temp->right);
		}
		
}
}
void height(struct btreenode*h)
{
	deque<struct btreenode*>s;
	s.push_back(h);
	int count=0;
	while(1){
	    int len=s.size();
	    if(len==0)
	    {
	      cout<<"count is "<<count;
	      break;
		}
       
        count++;
        
        while(len>0)
        {
        		struct btreenode *temp=s.front();
		s.pop_front();
        	 if(temp->left)
                s.push_back(temp->left);
	         if(temp->right)
                s.push_back(temp->right);
                
                len--;
        }
   	 }
}
int main() {
	struct btreenode *h=NULL;
	    push(&h,10);
		push(&h,20);
		push(&h,30);
		push(&h,40);
		push(&h,50);
		push(&h,60);
		push(&h,70);
	    push(&h,80);
	     height(h);
		cout<<"List is:"<<endl;
		levelorder(h);
		cout<<endl;
		cout<<"preorder"<<endl;
		preorder(h);
		cout<<endl;
	    cout<<"inorder"<<endl;
	    inorder(h);
	    cout<<endl;
	    cout<<"postorder"<<endl;
	    postorder(h);
	    cout<<endl;
	    cout<<"levelorder"<<endl;
	    levelorder(h);
	    
	return 0;	
}
