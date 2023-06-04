/*
A Dictionary stores keywords & its meanings. Provide facility for adding new keywords,
deleting keywords, updating values of any entry. Provide facility to display whole data
sorted in ascending/ Descending order. Also find how many maximum comparisons may
require for finding any keyword. Use Binary Search Tree for implementation. 
*/

#include<iostream>
using namespace std;
struct node
{
    char key;
    string value;
    node*left;
    node*right;
};

class DictBst
{
    public:
    node*root;
    DictBst()
    {
        root=NULL;
    }
    node*insert(node*root,char key,string value)
    {
        if(root==NULL)
        {
            root=new node;
            root->key=key;
            root->value=value;
            root->left=NULL;
            root->right=NULL;
        }
        else if(root->key<key)
        {
            insert(root->left,key,value);
        }
        else{insert(root->right,key,value);}
        return root;
    }
    node*update(node*root,char key,string nvalue)
    {
        if(root==NULL)
        {
            cout<<"KEY is not present."<<endl;
        }
        else if(root->key<key)
        {
            insert(root->left,key,nvalue);
        }
        else if(root->key>key)
        {insert(root->right,key,nvalue);}
    }
    void display(node*root)
    {
        if(root!=NULL)
        {
            return;
        }
        display(root->left);
        cout<<root->key<<"-"<<root->value<<endl;
        display(root->right);
    }    

};