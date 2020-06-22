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
    cout<<"\nEnter data (-1 for no node).";
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

int main()
{
    node *root;
    root=create();

}
