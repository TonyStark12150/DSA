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
    node*parent;
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
        {
            insert(root->right,key,nvalue);
        }
        else if(root->key==key)
        {
            root->value=nvalue;
        }
    }

    node* min(node* root)
    {
        if (root->left != NULL)
        {
            return min(root->left);
        }
        return root;
    }

    void delet(node*root,char key)
    {
        while(root!=NULL)
        {
            if(key>root->key)
            {
                parent=root;
                root=root->right;
            }
            else if(key<root->key)
            {
                parent=root;
                root=root->left;
            }
            else if(key==root->key)
            {
                if(root->left==NULL&&root->right==NULL)
                {
                    if(parent->left==root)
                    {
                        delete root;
                        parent->left=NULL;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        delete root;
                        parent->right=NULL;
                        return;
                    }
                }

                if(root->left==NULL)
                {
                    if(parent->left==root)
                    {
                        parent->left=root->right;
                        delete root;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        parent->right=root->right;
                        delete root;
                        return;
                    }
                }
                else if(root->right==NULL)
                {
                    if(parent->left==root)
                    {
                        parent->left=root->left;
                        delete root;
                        return;
                    }
                    else if(parent->right==root)
                    {
                        parent->right=root->left;
                        delete root;
                        return;
                    }
                }
                else if(root->left!=NULL&&root->right!=NULL)
                {
                    node*n=min(root->right);
                    n->key=root->key;
                    delet(n,n->key);
                    return;
                }
            }
        }

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

    void comparisons(node*root,char key)
    {
        static int count=0;
        while(root!=NULL)
        {
            if(key<root->key)
            {
                count++;
                root=root->left;
            }
            else if(key>root->key)
            {
                count++;
                root=root->right;
            }
            else if(key==root->key)
            {
                count++;
                cout<<"Number of comparisons to find the words:"<<count<<endl;
                return;
            }
        }
    }
};
int main()
{
    DictBst db;
    int ch;
    char key;
    string value;
    do
    {
        cout<<"What do want to do?"<<endl;
        cout<<"1.Insert Key\n2.Delete keys\n3.Update\n4.Display Dictionary\n5.Comparisons\n6.Exit"<<endl;
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter the key :"<<endl;
            cin>>key;
            cout<<"Enter the value : "<<endl;
            cin>>value;
            db.insert(db.root,key,value);
            break;
        case 2:
            cout<<"Enter the key to delete:"<<endl;
            cin>>key;
            db.delet(db.root,key);
            break;
        case 3:
            cout<<"Enter the key to update :"<<endl;
            cin>>key;
            cout<<"Enter the value to update : "<<endl;
            cin>>value;
            db.update(db.root,key,value);
            break;
        case 4:
            db.display(db.root);
            break;
        case 5:
            cout<<"Enter the key to comparisons :"<<endl;
            cin>>key;
            db.comparisons(db.root,key);
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    } while (6);   

    return 0;
}