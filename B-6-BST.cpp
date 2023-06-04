/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value 
*/
#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

class BST
{
public:
    node* root;

    BST()
    {
        root = NULL;
    }

    node* insert(node*& root, int ele)
    {
        if (root == NULL)
        {
            root = new node;
            root->data = ele;
            root->left = NULL;
            root->right = NULL;
        }
        else if (ele > root->data)
        {
            root->right = insert(root->right, ele);
        }
        else
        {
            root->left = insert(root->left, ele);
        }
        return root;
    }

    node* min(node* root)
    {
        if (root->left != NULL)
        {
            return min(root->left);
        }
        return root;
    }

    int longest(node* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int leftHeight = longest(root->left);
        int rightHeight = longest(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void mirror(node* root)
    {
        if (root == NULL)
        {
            return;
        }
        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }

    node* search(node* root, int ele)
    {
        if (root == NULL)
        {
            cout << "Element is not present." << endl;
            return NULL;
        }
        else if (root->data == ele)
        {
            cout << "Element is present." << endl;
            return root;
        }
        else if (ele > root->data)
        {
            return search(root->right, ele);
        }
        else
        {
            return search(root->left, ele);
        }
    }

    void display(node* root)
    {
        if (root != NULL)
        {
            display(root->left);
            cout << root->data << " ";
            display(root->right);
        }
    }
};

int main()
{
    BST b;
    b.root = b.insert(b.root, 11);
    b.insert(b.root, 14);
    b.insert(b.root, 10);
    b.insert(b.root, 5);
    b.insert(b.root, 1);

    cout << "Binary Search Tree:" << endl;
    b.display(b.root);
    cout << endl;

    cout << "Number of nodes in the longest path from root: " << b.longest(b.root) << endl;

    node* minimum = b.min(b.root);
    cout << "Minimum data value found in the tree: " << minimum->data << endl;

    cout << "Mirror of the tree:" << endl;
    b.mirror(b.root);
    b.display(b.root);
    cout << endl;

    b.search(b.root,11);
    b.search(b.root,100);
    cout << endl;

    return 0;
}
