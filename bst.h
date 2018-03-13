#ifndef BST
#define BST
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

    void traverse_postorder_wrapper();
    void traverse_postorder(nodeptr root);

    void traverse_inorder_wrapper();
    void traverse_inorder(nodeptr root);

    void sumEachLevel();//find sum of nodes at each level

    void altLevel();//print levels right to left and left to right alternatively

    void evenLevelSum_wrapper(int &sum); // find sum of all nodes at even levels
    int evenLevelSum(nodeptr root,int level,int &sum);

    void oddLevelSum_wrapper(int &sum); // find sum of all nodes at odd levels
    int oddLevelSum(nodeptr root,int level,int &sum);

    void replaceBySum_wrapper();
    int replaceBySum(nodeptr root);

    int validateBST_wrapper();
    bool validateBST(nodeptr root);

    void searchBST_wrapper(int key);
    int searchBST(nodeptr node,int key);
};

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

#endif

