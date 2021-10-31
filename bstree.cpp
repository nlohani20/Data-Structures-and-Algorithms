#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *left,*right;
        node(int x)                             //constructor
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
        void search1(node *root, int key);
};

node* bst :: insert1(node *root, node *nn)              //insert
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

void bst::inorder (node *root)                          //insert
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

        cout<<"\nDo you want to insert more?(y/n) \n\n";
        cin>>ans;

    }while(ans=='y');
}

void bst :: search1(node *root,int key)
{
    if(root==NULL)
    {
        cout<<"\n"<<key<<" is not present.";
        return;
    }
    if(key==root->data)
    {
        cout<<"\n"<<key<<" is present.";
        return;
    }
    else if(key < root->data)
    {
        search1(root->left,key);
    }
    else if(key > root->data)
    {
        search1(root->right,key);
    }
}

int main()
{
    bst b;
    int key;
    b.create();
    b.inorder(b.root);
    cout<<"\nEnter the key to be searched.";
    cin>>key;
    b.search1(b.root,key);
}
