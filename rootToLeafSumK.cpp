#include "bst.h"
#include <iostream>

using namespace std;

void bst::rootToLeafSumK_wrapper(int k){
    int currsum = 0;
    int flag = rootToLeafSumK(root,currsum , k);
    if (flag == 0)
        cout<<"NOT FOUND";
    else
        cout<<"FOUND";
}

int bst::rootToLeafSumK(nodeptr root, int currsum, int k){
    if (currsum > k)
        return 0;
    if (root == NULL && currsum == k)
        return 1;
    if (root == NULL && currsum != k)
        return 0;
    else if (! root->right)
        {   currsum = currsum + root->data;
            return rootToLeafSumK(root->left,currsum,k); }
    else if (! root->left)
        {   currsum = currsum + root->data;
            return rootToLeafSumK(root->right,currsum,k); }
    else if ((! root->left) && (! root->right))
        {   currsum = currsum + root->data;
            return (NULL, currsum, k);
        }
    else
    { currsum = currsum + root->data;
      int f1 = rootToLeafSumK(root->left,currsum,k);

      int f2 = rootToLeafSumK(root->right,currsum,k);
      if (f2 == 1)
        return 1;
      else if (f1 == 1)
        return 0;
      else
        return 0;
    }
}

int main()
{   bst b1;
    int k;
    b1.insertnode_wrapper(9);
    b1.insertnode_wrapper(4);
    b1.insertnode_wrapper(6);
    b1.insertnode_wrapper(12);
    b1.insertnode_wrapper(10);
    b1.insertnode_wrapper(2);
    b1.insertnode_wrapper(1);
    b1.insertnode_wrapper(14);
    b1.insertnode_wrapper(5);
    b1.insertnode_wrapper(11);
    cout<<"Preoder Traversal : ";
    b1.traverse_preorder_wrapper();
    cout<<endl<<"Enter sum to be found ";
    cin>>k;
    cout<<endl;
    b1.rootToLeafSumK_wrapper(k);
    return 0;
}
