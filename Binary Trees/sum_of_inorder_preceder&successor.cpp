#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left, *right;
  Node(){data=0;left=right=nullptr;}
};
Node* getNode(int item){
  Node* newnode = new Node;
  newnode->data = item;
  newnode->left=newnode->right=nullptr;
  return newnode;
}
void inorder(Node* root, vector<int>& arr){
  if(root != nullptr){
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
  }
}
void sumOfNodes(Node* root, vector<int> arr, int& i){
  if(root == nullptr){
    return;
  }
  sumOfNodes(root->left, arr, i);
  root->data = arr[i-1]+arr[i+1];
  ++i;
  sumOfNodes(root->right, arr, i);
}
void solution(Node* root){
  vector<int> arr;
  arr.push_back(0);
  inorder(root, arr);
  arr.push_back(0);
  int i=1;
  sumOfNodes(root, arr, i);
}
void preorder(Node* root){
  if(root != nullptr){
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
  }
}
int main(){
  
  Node* root = getNode(1); 
  root->left = getNode(2);        
  root->right = getNode(3);       
  root->left->left = getNode(4);  
  root->left->right = getNode(5); 
  root->right->left = getNode(6); 
  root->right->right = getNode(7);
  solution(root);
  preorder(root);

  return 0;
}