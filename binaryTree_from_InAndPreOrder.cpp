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

struct btreenode *create()
{
    struct btreenode *nn = (struct btreenode *)malloc(sizeof(struct btreenode));
   
    return nn;
}

//printing the tree

void print(struct btreenode *root)
{
    deque<struct btreenode *> q;
    q.push_back(root);
    while (!q.empty())
    {
        struct btreenode *temp = q.front();
        q.pop_front();
        cout << temp->data << " ";
        if (temp->left)
        {
            q.push_back(temp->left);
        }
        if (temp->right)
        {
            q.push_back(temp->right);
        }
    }
    cout << endl;
}

//searching root index in inorder

int search(int in[], int start, int end, int val) {
	int i;
	for(i=start;i<=end;i++) {
		if(in[i]==val)
		{
			return i;
		}
	}
}

//constructing tree

struct btreenode* tree(int pre[],int in[],int start,int end) {
	
	static int index=0;
	if( start > end ) {
		return NULL;
	}
	struct btreenode* newNode=create();
	newNode->data=pre[index++];
	int ind=search(in,start,end,newNode->data); 
	newNode->left=tree(pre,in,start,ind-1);
	newNode->right=tree(pre,in,ind+1,end);
	
	return newNode; 
}

int main( void ) {
	int size;
	cout<<"Enter the size of tree :"<<endl;
	cin>>size;
	int inorder[size],preorder[size];
	cout<<"Enter inorder :"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>inorder[i];
	}
	cout<<"Enter preorder :"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>preorder[i];
	}
	struct btreenode* root=NULL;
	root=tree(preorder,inorder,0,size-1);
	cout<<"Tree is :"<<endl;
	print(root);
	return 0;
}
