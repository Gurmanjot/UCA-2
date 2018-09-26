 #include<iostream>
using namespace std;
#include<deque>
#include<stack>
struct btreenode{
	int data;
	struct btreenode * left;
	struct btreenode * right;
};

// creating a new node
struct btreenode* createnew(int val){
	struct btreenode *nn=new struct btreenode();
	nn->data=val;
	nn->left=NULL;
	nn->right=NULL;
	return nn;
}
// pushing node to tree
void push(struct btreenode **h, int val)
{

	struct btreenode *n = new struct btreenode();
	n->data = val;

	if (*h == NULL)
	{
		*h = n;
	}
	else
	{
		deque<struct btreenode *> q;
		q.push_back(*h);
		while (!q.empty())
		{
			struct btreenode *temp = q.front();
			q.pop_front();

			if (!temp->left)
			{
				temp->left = n;
				return;
			}
			if (!temp->right)
			{
				temp->right = n;
				return;
			}

			q.push_back(temp->left);
			q.push_back(temp->right);
		}
	}
}
//mirror  tree formation
struct btreenode* mirror(struct btreenode * root) {
	if(root==NULL)
	{
		return NULL;
	}
	struct btreenode* nn=createnew(root->data);
	nn->left=mirror(root->right);
 	nn->right=mirror(root->left);
 	
 	return nn;
}
//printing tree
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
//main function
int main()
{
	struct btreenode *root = NULL;
	push(&root, 10);
	push(&root, 20);
	push(&root, 30);
	push(&root, 40);
	push(&root, 50);
	push(&root, 60);
	push(&root, 70);
	push(&root, 80);
	push(&root, 90);
	push(&root, 100);
	cout<<"Original tree :"<<endl;
    print(root);
    cout<<endl;
    struct btreenode* mir=NULL;
    mir=mirror(root);
    cout<<"Mirror tree : "<<endl;
	print(mir);
	return 0;
}
