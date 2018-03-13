#include "bst.h"
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void bst::altLevel(){
    if (root==NULL)
    {cout<<"Tree is empty";
        return;}
    queue<nodeptr> q;
    stack<nodeptr> s;
    q.push(root);
    int level = 0;
    int qsize = 0;

    while(!q.empty())
    { qsize=q.size();
      while(qsize != 0)
      { if (level % 2 == 0)
            {
                nodeptr curr=q.front();
                cout<<curr->data<<" ";
                if (curr->left)
                    {q.push(curr->left);}
                if (curr->right)
                    {q.push(curr->right);}
                q.pop();
                qsize--;
            }
        else
            {
                int qsize2=qsize;
                for(int i=1;i<=qsize2;i++)
                {
                    s.push(q.front());
                    nodeptr curr = q.front();
                    if (curr->left)
                        {q.push(curr->left);}
                    if (curr->right)
                        {q.push(curr->right);}
                    q.pop();
                    qsize--;
                }
                while(! s.empty())
                {
                    nodeptr curr= s.top();
                    cout<<curr->data<<" ";
                    s.pop();
                }
            }
      }
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
    b1.insertnode_wrapper(14);
    b1.insertnode_wrapper(1);
    b1.insertnode_wrapper(7);
    b1.insertnode_wrapper(11);
    cout<<"preorder level order traversal : ";
    b1.traverse_preorder_wrapper();
    cout<<endl<<"Alternate right level level order traversal : ";
    b1.altLevel();
    return 0;
}
