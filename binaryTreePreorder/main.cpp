#include <iostream>

using namespace std;

class binary_tree{
public:
    class node{
        public:
        int value;
        node *left;
        node *right;
    };
    typedef node* nodeptr;
    nodeptr root;

    binary_tree();
    void binary_insert();
    void preorder_recursive_wrapper();
    void preorder_recursive(nodeptr root);

};

binary_tree::binary_tree(){
 root =NULL;
}

void binary_tree::binary_insert(){
    root=new node;
    root->value=1;
    root->left=new node;
    root->right=new node;
    root->left->value=2;
    root->right->value=3;
    root->left->left=new node;
    root->left->left->value=4;
    root->left->left->left=NULL;
    root->left->left->right=NULL;
    root->right->left=NULL;
    root->right->right=NULL;
}

void binary_tree::preorder_recursive_wrapper(){
    if (root==NULL)
    {
        cout<<"tree is empty";
        return;
    }
    else
    {
       nodeptr temp=root;
       preorder_recursive(temp);
    }
}

void binary_tree::preorder_recursive(nodeptr root){
    if (root!=NULL)
    {
        cout<<root->value;
        preorder_recursive(root->left);
        preorder_recursive(root->right);
    }
}

int main()
{
    binary_tree b1;
    b1.binary_insert();
    b1.preorder_recursive_wrapper();
    return 0;
}
