#include "bst.h"
#include <iostream>

using namespace std;

int bst::validateBST_wrapper(){
    return validateBST(root);
}

int bst::leftMax(nodeptr root) {
    
}

bool bst::validateBST(nodeptr root) {
    int l = leftMax(root->left);
    int r = rightMin(root->right);
    
    bool b = compare(root->data, l, r);    
    return b && validateBST(root->left) && validateBST(root->right);
}

bool bst::validateBST(nodeptr root){
    if (root == NULL)
        return true;
    else{
        bool b1,b2;
        b1 = root->data > root->right->data;
        b2 = root->data < root->left->data;
        if (b1 && b2){
            return (validateBST(root->right) && validateBST(root->left));
        }
        else
            return false;
    }
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
    cout<<endl<<"Validating BST :     ";
    int flag=b1.validateBST_wrapper();
    if(flag == 0)
        cout<<"It is a BST!!";
    else
        cout<<"It is NOT a BST!!";
    return 0;
}
