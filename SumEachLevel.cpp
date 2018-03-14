#include "bst.h"
#include <iostream>
#include <queue>

using namespace std;

void bst::sumEachLevel(){
    if(root == NULL)
        return;
    queue<nodeptr> q;
    q.push(root);
    int level = 0;
    while(!q.empty()){
        int qsize = q.size();
        int sum = 0;
        while(qsize != 0) {
            qsize--;
            nodeptr curr = q.front();
            sum = sum + curr->data;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            q.pop();
        }
        cout<<endl<<"sum at level "<<level<<" is "<<sum;
        level++;
    }
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
    b1.traverse_preorder_wrapper();
    cout<<endl<<endl;
    b1.sumEachLevel();
    return 0;
}
