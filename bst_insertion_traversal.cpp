#include <iostream>

using namespace std;

class bst {
private:
    class node {
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
    void traverse_preorder_wrapper();
    void traverse_preorder(nodeptr root);
    
private:
    void insertnode(nodeptr root, nodeptr temp, int ele);
};

bst::bst() {
    root = NULL;
}

void bst::insertnode_wrapper(int ele) {
    nodeptr temp = new node();
    temp->data = ele;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
        root = temp;
    else {
        nodeptr curr = root;
        insertnode(curr, temp, ele);
    }
}

// Also I would suggest check recursive implementation, that will be easy and fast to code
void bst::insertnode(nodeptr root, nodeptr newNode, int ele) {
    nodeptr parent;
    while(curr != NULL) {
        // I guess you want to save parent
        parent = root;
        if(newNode->data < root->data)
            root = root->left;
        else
            root = root->right;
    }
    if(temp->data > parent->data)
        parent->right = newNode;
    else
        parent->left = newNode;
}

void bst::traverse_preorder_wrapper() {
    if (root == NULL) {
        cout<<endl<<"Tree is empty";
        return;
    }
    nodeptr curr = root;
    traverse_preorder(curr);
}

void bst::traverse_preorder(nodeptr root) {
    if(root == NULL)
        return;
    else {
        cout<<root->data<<" ";
        traverse_preorder(root->left);
        traverse_preorder(root->right);
    }
}

int main() {
    bst b1;
    b1.insertnode_wrapper(9);
    b1.insertnode_wrapper(4);
    b1.insertnode_wrapper(6);
    b1.insertnode_wrapper(12);
    b1.insertnode_wrapper(10);
    b1.insertnode_wrapper(2);
    b1.traverse_preorder_wrapper();
    return 0;
}
