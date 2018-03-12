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
    int traverse_preorderForSum(nodeptr root,int sum);
    void levelorder();
    int heightofnode(nodeptr temp);
    int evenLevelSum();
};

bst::bst(){
    root=NULL;
}

void bst::insertnode_wrapper(int ele){
    nodeptr temp=new node();
    temp->data=ele;
    temp->left=NULL;
    temp->right=NULL;

    if (root==NULL)
        root=temp;
    else{
        nodeptr curr=root;
        insertnode(curr,temp,ele);
    }
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

int bst::heightofnode(nodeptr temp){
    if (! temp)
        return 0;
    else
    {int hl=heightofnode(temp->left);
    int hr=heightofnode(temp->right);
    return 1+ ((hl>hr)?hl:hr) ;
    }
}

int bst::evenLevelSum(){
    if(root==NULL)
        return 0;
    int sum=0;
    if (heightofnode(root)==0)
    {
        sum=root->data;
        return sum;
    }
    nodeptr temp=root;
    sum=traverse_preorderForSum(temp,sum);
    return sum;
}

int bst::traverse_preorderForSum(nodeptr root,int sum){
    if(root==NULL)
        return sum;
    else
    {if(heightofnode(root)%2==0)
        {

            sum=sum+ root->data;
        }
    traverse_preorderForSum(root->left,sum);
    traverse_preorderForSum(root->right,sum);}
}

void bst::levelorder(){
    if (root==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    queue<nodeptr> s;
    s.push(root);
    while(!s.empty())
    {
        nodeptr curr=s.front();
        cout<<curr->data<<" ";
        if (curr->left)
            {s.push(curr->left);}
        if (curr->right)
            {s.push(curr->right);}
        s.pop();
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
    cout<<endl<<"level order traversal   :";
    b1.levelorder();
    cout<<endl<<"Even level Sum  :";
    cout<<b1.evenLevelSum();
    return 0;
}
