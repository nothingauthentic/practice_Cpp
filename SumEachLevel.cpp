#include <iostream>
#include <queue>

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
    void sumEachLevel();
};

bst::bst(){
    root=NULL;
}

void bst::insertnode_wrapper(int ele){
    nodeptr temp = new node();
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else{
        nodeptr curr=root;
        insertnode(curr,temp,ele);}
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

void bst::sumEachLevel(){
    if(root == NULL)
        return;
    queue<nodeptr> q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int qsize= q.size();
        int suml=0;
        while(qsize != 0){
            qsize--;
            nodeptr curr=q.front();
            suml = suml + curr->data;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            q.pop();
        }
        cout<<endl<<"sum at level "<<level<<" is "<<suml;
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
