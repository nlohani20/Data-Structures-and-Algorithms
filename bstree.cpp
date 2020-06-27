#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left,*right;
        node(int x)
        {
            data=x;
            left = right=NULL;
        }
};

class bst
{
    public:
        node *root=NULL;
        node* insert1(node *root, node *nn);
        void create();
        void inorder(node *root);
};

node* bst :: insert1(node *root, node *nn)
{
    node *temp=root;
    if(temp==NULL)
    {
        temp=nn;
    }
    if(nn->data < temp->data)
    {
        temp->left=insert1(temp->left, nn);
    }
    if(nn->data > temp->data)
    {
        temp->right=insert1(root->right, nn);
    }
    return temp;
}

void bst::inorder (node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void bst::create()
{
    char ans;
    do
    {
        node *nn;
        int x;
        cout<<"\nEnter number to be inserted. ";
        cin>>x;
        nn=new node(x);
        root=insert1(root,nn);
        cout<<"\n"<<x<<" inserted.";

        cout<<"\nDo you want to insert more?(y/n)";
        cin>>ans;

    }while(ans=='y');
}


int main()
{
    bst b;
    b.create();
    b.inorder(b.root);

}
