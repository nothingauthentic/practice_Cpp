#include <iostream>

using namespace std;

class bst{
private:
    class node{
    public:
        int data;
        node* left;
        node* right;
    };
    typedef node* nodeptr;
    nodeptr root;
public:
    bst();
    void insertnode_wrapper(int ele);
    void insertnode(nodeptr root,nodeptr temp,int ele);
    void traverse_preorder_wrapper();
    void traverse_preorder(nodeptr root);
    void replaceBySum_wrapper();
    int replaceBySum(nodeptr root);
};

bst::bst(){
    root=NULL;
}

void bst::insertnode_wrapper(int ele){
    nodeptr temp=new node();
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;

    if (root==NULL)
        root=temp;
    else{
        nodeptr curr=root;
        insertnode(curr,temp,ele);
    }
}

void bst::insertnode(nodeptr curr,nodeptr temp,int ele){
    nodeptr temp2;
    while(curr!=NULL)
    {   temp2=curr;
        if(ele<curr->data)
        {
            curr=curr->left;
        }
        else
            curr=curr->right;
    }
    if(ele>temp2->data)
    {
        temp2->right=temp;
    }
    else
        temp2->left=temp;
}

void bst::traverse_preorder_wrapper()
{
    if (root==NULL)
    {
        cout<<endl<<"Tree is empty";
        return;
    }
    nodeptr curr=root;
    traverse_preorder(curr);
}

void bst::traverse_preorder(nodeptr root){
    if(root==NULL)
        return;
    else
    {cout<<root->data<<" ";
    traverse_preorder(root->left);
    traverse_preorder(root->right);}
}

void bst::traverse_postorder(nodeptr root){
    if(root == NULL)
        return;

    traverse_postorder(root->left);
    traverse_postorder(root->right);
    cout<<root->data<<" ";
}

void bst::replaceBySum_wrapper(){
    replaceBySum(root);
}

int bst::replaceBySum(nodeptr root){
    if(root == NULL)
        return 0;
    
    int currentData = root->data;
    int l = replaceBySum(root->left);
    int r = replaceBySum(root->right);
    root->data = l + r;
    return root->data + currentData;
}


int main()
{
    bst b1;
    b1.insertnode_wrapper(9);
    b1.insertnode_wrapper(4);
    b1.insertnode_wrapper(6);
    b1.insertnode_wrapper(12);
    b1.insertnode_wrapper(10);
    b1.insertnode_wrapper(2);
    b1.insertnode_wrapper(1);
    b1.insertnode_wrapper(14);
    cout<<"Preorder Traversal is : ";
    b1.traverse_preorder_wrapper();
    cout<<endl;
    cout<<"Replace nodes by Sum :";
    b1.replaceBySum_wrapper();
    cout<<endl;
    b1.traverse_preorder_wrapper();
    return 0;
}
