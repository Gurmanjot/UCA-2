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

// inserting new node

struct btreenode *insert(int arr[], int start,int end)
{
    if(start>end) return NULL;
      
     int mid=(start+end)/2;
     struct btreenode *nn=create();
     nn->data=arr[mid];
     nn->right=insert(arr,mid+1,end);
     nn->left=insert(arr,start,mid-1);
      
     return nn;
}
// Printing the Binary Search tree

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
// preorder traversal
void preOrder(struct btreenode* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
} 
int main()
{
    struct btreenode *root = NULL;
    int size;
    cout << " Enter the number of elements you want to enter in the tree : " << endl;
    cin >> size;
    int val;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        arr[i]=val;
    }
   
  
	root=insert(arr, 0, size-1);
	
	cout<<"Binary tree is : "<<endl;
	print(root); 
    
    
    
    return 0;
}
