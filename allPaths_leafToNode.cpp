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
	nn->left = NULL;
	nn->right = NULL;
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
void push(struct btreenode **h, int val)
{

	struct btreenode *n = create();
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

void printarray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void path(struct btreenode *root, int arr[], int index)
{

	if (root == NULL)
		return;

	arr[index++] = root->data;

	if (root->left == NULL && root->right == NULL)
	{
		printarray(arr, index);
	}
	else
	{
		if (root->left)
		{
			path(root->left, arr, index);
		}
		if (root->right)
		{
			path(root->right, arr, index);
		}
	}
}

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

	int arr[100];
	path(root, arr, 0);
	return 0;
}
