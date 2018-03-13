#include "bst.h"
#include <iostream>

using namespace std;

bst::bst(){
    root = NULL;
}

void bst::insertnode_wrapper(int ele){
    nodeptr temp = new node();
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else{nodeptr curr = root;
        insertnode(curr,temp,ele);}
}

void bst::insertnode(nodeptr curr,nodeptr temp,int ele){
    nodeptr temp2;
    while(curr != NULL)
    {   temp2 = curr;
        if(ele < curr->data)
            {curr = curr->left;}
        else
            curr = curr->right;}
    if(ele>temp2->data)
        {temp2->right = temp;}
    else
        temp2->left = temp;
}

void bst::traverse_preorder_wrapper(){
    if (root == NULL)
        {cout<<endl<<"Tree is empty";
        return;}
    nodeptr curr = root;
    traverse_preorder(curr);
}

void bst::traverse_preorder(nodeptr root){
    if(root == NULL)
        return;
    else
    {cout<<root->data<<" ";
    traverse_preorder(root->left);
    traverse_preorder(root->right);}
}

void bst::traverse_postorder_wrapper(){
    if (root==NULL)
        {cout<<endl<<"Tree is empty";
        return;}
    nodeptr curr = root;
    traverse_postorder(curr);
}

void bst::traverse_postorder(nodeptr root){
    if(root == NULL)
        return;
    else
    {   traverse_postorder(root->left);
        traverse_postorder(root->right);
        cout<<root->data<<" ";  }
}

void bst::traverse_inorder_wrapper()
{
    if (root==NULL)
    {cout<<endl<<"Tree is empty";
        return; }
    nodeptr curr = root;
    traverse_inorder(curr);
}

void bst::traverse_inorder(nodeptr root){
    if(root == NULL)
        return;
    else
    {   traverse_inorder(root->left);
        cout<<root->data<<" ";
        traverse_inorder(root->right);}
}

int main()
{   bst b1;
    b1.insertnode_wrapper(9);
    b1.insertnode_wrapper(4);
    b1.insertnode_wrapper(6);
    b1.insertnode_wrapper(12);
    b1.insertnode_wrapper(10);
    b1.insertnode_wrapper(2);
    cout<<"Preoder Traversal : ";
    b1.traverse_preorder_wrapper();
    cout<<endl<<"Postoder Traversal : ";
    b1.traverse_postorder_wrapper();
    cout<<endl<<"Inoder Traversal : ";
    b1.traverse_inorder_wrapper();
    return 0;
}
