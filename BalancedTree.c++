#include<iostream>
using namespace std;
#include<vector>
#include<stack>
struct Node{
    int data ;
    Node* right;
    Node* left;
    Node(int x) : data(x) , right(nullptr),left(nullptr){};
    Node(int x,Node* l,Node* r) : data(x),right(r),left(l) {};
};
 Node* buildTree(){
     int val;
     cout<<"value -> ";
     cin>> val;
     if(val == -1) return nullptr ;
     Node* root = new Node(val);
    //enter the left child
     cout<<"Enter the left child for root " <<val<< endl;
     root->left = buildTree();
     cout<<"Enter the right child for root "<<val<< endl;
     root->right = buildTree();
     return root;
  }
 int findHeight(Node* root) {
  if(root == nullptr) return 0;
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);
  if(abs(lh-rh)>1) return -1;
  if(lh == -1 || rh == -1) return -1;
  return 1 + max(lh,rh);
 } 
int main() {
Node * root = buildTree();
 int height = findHeight(root);
 if(height == -1 ) cout<<"The Tree Is Not Balanced";
 else cout<< "Tree is Balanced";
 return 0;
}