#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left,*right;
};

node* create()
{
    node *nn;
    int x;
    nn=new node();

    cout<<"\nEnter data (-1 for no node).\n";

    cout<<"\nEnter data (-1 for no node).\n\n";

    cin>>x;
    if(x==-1)
    {
        return 0;
    }
    nn->data=x;
    cout<<"\nEnter left child of "<<x;
    nn->left=create();
    cout<<"\nEnter right child of "<<x;
    nn->right=create();
    return nn;
}

void preorder (node *root)
{
    if(root==0)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder (node *root)
{
    if(root==0)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder (node *root)
{
    if(root==0)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node *root;
    root=create();
    cout<<"\nPreorder is ";
    preorder(root);
    cout<<"\nInorder is ";
    inorder(root);
    cout<<"\nPostorder is ";
    postorder(root);

}
