#include "bst.h"
#include <iostream>

void bst::evenLevelSum_wrapper(int &sum) {
    cout<<evenLevelSum(root, 0, sum);
}

int bst::evenLevelSum(nodeptr root, int level, int &sum) {
    if(root == NULL)
        return sum;
    if(level%2 == 0)
        sum = sum + root->data;
    evenLevelSum(root->left, level + 1, sum);
    evenLevelSum(root->right, level + 1, sum);
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
    cout<<"Preorder Traversal  :  ";
    b1.traverse_preorder_wrapper();
    int sum=0;
    cout<<endl<<"Even level Sum  ";
    b1.evenLevelSum_wrapper(sum);
    return 0;
}
