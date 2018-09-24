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

//  minimum value in tree

int max_l(struct btreenode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

// maximum value in tree

int max_r(struct btreenode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

// delete a value

struct btreenode *del(struct btreenode *root, int value)
{

    if (root->data == value)
    {
        if (root->left == NULL)
        {
            return root->right;
        }
        else if (root->right == NULL)
        {
            return root->left;
        }
        else
        {
            int max_left = max_l(root->left);
            root->data = max_left;
            root->left = del(root->left, max_left);
            return root;
        }
    }

    if (root->data < value)
    {
        root->right = del(root->right, value);
    }
    else if (root->data > value)
    {
        root->left = del(root->left, value);
    }
    return root;
}

// to check if tree is valid or not

int valid_Bst(struct btreenode *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data < min || root->data > max)
    {
        return 0;
    }
    return valid_Bst(root->left, min, root->data - 1) && valid_Bst(root->right, root->data + 1, max);
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
    int check, min, max;
    min = max_l(root);
    max = max_r(root);
    check = valid_Bst(root, min, max);
    if (check == 1)
    {
        cout << " Tree is valid " << endl;
    }
    else if (check == 0)
    {
        cout << " Tree is invalid " << endl;
    }
    int val_d;
    cout << "Enter the value you want to delete : " << endl;
    cin >> val_d;
    del(root, val_d);
    cout << "After Deletion :" << endl;
    print(root);

    return 0;
}
