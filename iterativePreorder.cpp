#include<iostream>
using namespace std;
 struct Node{
    int val ;
    Node* left;
    Node* right;
    Node(int x) : val(x),left(nullptr),right(nullptr) {};
    Node() : val(0),left(nullptr),right(nullptr){};
    Node(int x , Node* left1,Node* right1) {
        val = x;
        left= left1;
        right = right1;
    }
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
  void preorderTraversal(Node * root) {
  if(root == nullptr) return ;
   cout<<root->val<<" ";
   preorderTraversal(root->left);
   preorderTraversal(root->right);
  }
int main()
{
    Node* root = buildTree();
    preorderTraversal(root);  
    return 0;
}
