#include<iostream>
using namespace std;

struct node{
  int data;
  node* left, *right;
};

node* root = nullptr, *par=nullptr;

node* findNode(int item){
  if(root == NULL){
        par=NULL;return NULL;
    }
    else if(item == root->data){
        par=NULL;return root;
    }
    else{
        node* loc;
        node* ptr, *save;
        if(item < root->data){
            ptr=root->left;
            save = root;
        }
        else{
            ptr=root->right;
            save=root;
        }
        while(ptr != NULL){
            if(ptr->data == item){
                loc=ptr;
                par=save;
                return loc;
            }
            else if(item < ptr->data){
                save = ptr;
                ptr=ptr->left;
            }
            else{
                save = ptr;
                ptr = ptr->right;
            }
        }
        loc = NULL;par = save;
        return loc;
    }
}

void insert(int item){
  node* loc = findNode(item);
    if(loc != NULL){
        cout<<"Node already Exist\n";
        return;
    }
    else{
        node* new_node = new node;
        new_node->data=item;
        new_node->left = new_node->right=NULL;
        if(par == NULL){
            root = new_node;
        }
        else if(item < par->data){
            par->left = new_node;
        }
        else{
            par->right = new_node;
        }
    }
}

void inorder(node* r)
{
    if(r != NULL){
        inorder(r->left);
        cout<<r->data<<' ';
        inorder(r->right);
    }
}

void preorder(node* r)
{
    if(r != NULL){
        cout<<r->data<<' ';
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(node* r)
{
    if(r != NULL){
        postorder(r->left);
        postorder(r->right);
        cout<<r->data<<' ';
    }
}

int main(){

  insert(10);insert(20);insert(80);
  insert(5);insert(40);insert(107);
  cout << "Preorder: ";
  preorder(root);
  cout<<"\nInorder: ";
  inorder(root);
  cout<<"\nPostorder: ";
  postorder(root);
  

  return 0;
}