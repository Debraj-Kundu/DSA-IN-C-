#include <bits/stdc++.h>
#define ll long long
#define BOOST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

class node{
public:
  int data, nodeCnt;
  node* left, *right;
  node* root;
  node(){root=nullptr;left=nullptr;right=nullptr;data=0;nodeCnt=0;}
  node* insert(node* , int);
  node* deleteNode(node* , int);
  int height(node* );
  void inorder(node *);
  void preorder(node*);
  void postorder(node*);
  int cnt_nodes(node* );
};
node* get_node(int item){
  node* newNode = new node;
  newNode->data = item;
  return newNode;
}
inline node* node::insert(node* root, int item){
  if(root == nullptr){
    root = get_node(item);
  }
  else if (item < root->data){
    root->left = insert(root->left, item);
  }
  else if(item > root->data){
    root->right = insert(root->right, item);
  } 
}
node* find_min(node* root){
  if(root->left != nullptr){
    root = root->left;
  }
  return root;
}
inline node* node::deleteNode(node* root, int item){
  if(root == nullptr) return nullptr;
  else if(item <root->data) root->left = deleteNode(root->left, item);
  else if(item > root->data) root->right = deleteNode(root->right, item);
  else{
    if(root->left == nullptr && root->right == nullptr){
      node* temp = root;
      root = nullptr;
      delete temp;
    }
    else if(root->left == nullptr){
      node* temp = root;
      root = root->right;
      delete temp;
    }
    else if(root->right == nullptr){
      node* temp = root;
      root = root->left;
      delete temp;
    }
    else{
      node* temp = find_min(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}
inline int node::height(node* root){
  if(root == nullptr){
    return 0;
  }
  return max(height(root->left), height(root->right))+1;
}
inline int node::cnt_nodes(node* root){
  if(root != nullptr){
    cnt_nodes(root->left);
    nodeCnt++;
    nodeCnt = cnt_nodes(root->right);
  }
  return nodeCnt;
}
inline void node::inorder(node* root){
  if(root != nullptr){
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
  }
}
inline void node::preorder(node* root)
{
    if(root != NULL){
        cout<<root->data<<' ';
        preorder(root->left);
        preorder(root->right);
    }
}
inline void node::postorder(node* root)
{
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<' ';
    }
}
int main()
{
  node* l1 = nullptr;
  l1 = l1->insert(l1, 40);
  l1 = l1->insert(l1, 10);
  l1 = l1->insert(l1, 70);
  l1 = l1->insert(l1, 80);
  l1 = l1->insert(l1, 35);
  l1 = l1->insert(l1, 100);
  l1->inorder(l1);
  l1 = l1->deleteNode(l1, 70);
  cout << "\nafter deletion\n";
  l1->inorder(l1);
  cout << "\nheight: " << l1->height(l1);
  cout << "\nNodes: " << l1->cnt_nodes(l1);

  return 0;
}
