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
int main() {


}