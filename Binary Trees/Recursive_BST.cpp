#include <bits/stdc++.h>

struct node{
    int data;
    node* left, *right;
};

node* getNode(int item){
    node* new_node = new node;
    new_node->data = item;
    new_node->left = new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int item)
{
    if(root == NULL){
        root = getNode(item);
    }
    else if(item < root->data){
        root->left = insert(root->left, item);
    }
    else if(item > root->data){
        root->right = insert(root->right, item);
    }
    return root;
}

node* findMin(node* root)
{
    if(root->left != NULL){
        root = findMin(root->left);
    }
    return root;
}

node* deleteNode(node* root, int item)
{
    if(root == NULL){
        return NULL;
    }
    else if(item < root->data)
        root->left = deleteNode(root->left, item);
    else if(item > root->data)
        root->right = deleteNode(root->right, item);
    if(item == root->data){
        if(root->left == NULL && root->right == NULL){
            node* temp = root;
            root = NULL;
            delete temp;
        }
        else if(root->right == NULL){
            node* temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->left == NULL){
            node* temp = root;
            root = root->right;
            delete temp;
        }
        else{
            node* loc = findMin(root->right);
            root->data = loc->data;
            root->right = deleteNode(root->right, loc->data);
        }
    }
    return root;
}

void inorder(node* r){
    if(r != NULL){
        inorder(r->left);
        std::cout<<r->data<<' ';
        inorder(r->right);
    }
}

int main()
{
    node* root;
    root=insert(root,10);root=insert(root,90);root=insert(root,80);
    root=insert(root,70);root=insert(root,5);root=insert(root,4);
    root=insert(root,7);root=insert(root,6);
    inorder(root);
    root = deleteNode(root,5);
    std::cout << '\n';
    inorder(root);

    return 0;
}
