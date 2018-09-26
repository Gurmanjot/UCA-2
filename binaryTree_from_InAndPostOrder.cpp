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
    nn->left=NULL;
    nn->right=NULL;
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

struct btreenode* tree(int in[], int post[], int start,int end, int* index) 
{ 
    if (start > end) 
        return NULL; 
    struct btreenode* node = create(); 
    node->data=post[*index];
	(*index)--; 
	if (start == end) 
        return node; 
     int indexa = search(in, start,end, node->data); 
    node->right = tree(in, post, indexa + 1, end, index); 
    node->left = tree(in, post, start, indexa - 1, index); 
  return node; 
} 

int main() {
	int size;
	cout<<"Enter the size of tree :"<<endl;
	cin>>size;
	int inorder[size],postorder[size];
	cout<<"Enter inorder :"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>inorder[i];
	}
	cout<<"Enter postorder :"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>postorder[i];
	}
	struct btreenode* root;
	int index=size-1;
	root=tree(inorder, postorder,0, size-1,&index); 
	cout<<"Tree is :"<<endl;
	print(root);

	return 0;
}
