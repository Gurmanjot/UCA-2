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

struct btreenode *create(int val)
{
    struct btreenode *nn = (struct btreenode *)malloc(sizeof(struct btreenode));
    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

// inserting new node

struct btreenode *insert(struct btreenode *root, int val)
{
    if (root == NULL)
    {
        struct btreenode *newNode = create(val);
        return newNode;
    }
    else
    {
        if (val < root->data)
        {
            root->left = insert(root->left, val);
        }
        else
        {
            root->right = insert(root->right, val);
        }
    }
    return root;
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

 struct btreenode * ancestor(struct btreenode *root,int one,int two){
 	
 	if(root==NULL)
 	 {
 	 	return NULL;
	 }
	  
	 if(root->data < one && root->data <two){
	 	return  ancestor(root->right,one,two);
	 }
	 else if(root->data > one && root->data >two) {
	 	return  ancestor(root->left,one,two);
	 }
	 
	 return root; 
 }
int main()
{
    struct btreenode *root = NULL;
    int size;
    cout << " Enter the number of elements you want to enter in the tree : " << endl;
    cin >> size;
    int val;
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        root = insert(root, val);
    }
    cout << "After Insertion :" << endl;
    print(root);
 
    int one,two;
    cout<<"Enter the number whose ancestors you want to find :"<<endl;
    cin>>one>>two;
    
    struct btreenode * ans=ancestor(root,one,two);
	cout<<"ans is "<<ans->data;    
    return 0;
}
