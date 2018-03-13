#include "bst.h"
#include <iostream>

using namespace std;

void bst::searchBST_wrapper(int key){
    int flag = searchBST(root,key);
    if (flag == 0)
        cout<<"NOT FOUND";
    else
        cout<<"FOUND";
}

int bst::searchBST(nodeptr root,int key){
    if (root == NULL)
        return 0;
    else if (key > root->data)
        return searchBST(root->right,key);
    else if (key < root->data)
        return searchBST(root->left,key);
    else if (key = root->data)
        return 1;
}

int main()
{   bst b1;
    int key;
    b1.insertnode_wrapper(9);
    b1.insertnode_wrapper(4);
    b1.insertnode_wrapper(6);
    b1.insertnode_wrapper(12);
    b1.insertnode_wrapper(10);
    b1.insertnode_wrapper(2);
    cout<<"Preoder Traversal : ";
    b1.traverse_preorder_wrapper();

    cout<<endl<<"Enter key to be searched :";
    cin>>key;

    b1.searchBST_wrapper(key);
    return 0;
}
