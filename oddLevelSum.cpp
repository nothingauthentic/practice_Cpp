#include "bst.h"
#include <iostream>

void bst::oddLevelSum_wrapper(int &sum){
        int level=0;
        cout<<oddLevelSum(root,level,sum);
}

int bst::oddLevelSum(nodeptr root,int level,int &sum){
    if(root==NULL)
        return sum;
    if(level%2 != 0)
        sum=sum+root->data;
    oddLevelSum(root->left,level+1,sum);
    oddLevelSum(root->right,level+1,sum);
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
    cout<<endl<<"Odd level Sum  ";
    b1.oddLevelSum_wrapper(sum);
    return 0;
}
