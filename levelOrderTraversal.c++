#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Node{
    int data ;
    Node* left ;
    Node* right;
    Node(int x,Node* l,Node* r) {
        data = x;
        left = l;
        right = r;
    }
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
Node* buildTree() {
    
cout<<"value -> ";
int val;
cin>> val;
if(val == -1 ) return nullptr;
// building a node ->
Node * root = new Node(val);
cout<<"Enter the value for left Node of root -> "<<val<<" ";
root->left = buildTree();
cout<< "Enter the value for right Node of root -> "<<val<<" ";
root ->right = buildTree();
return root;

}
 vector<vector<int>> levelOrderTraversal(Node* root,vector<vector<int>> &ans) {
     queue<Node*>q;
     q.push(root);
     while(!q.empty()) {
        int size = q.size();
        vector<int>arr;
    for(int i = 0 ;i < q.size() ;i++) {
        Node* node = q.front();
        q.pop();
        arr.push_back(node->data);
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }
    ans.push_back(arr);
     }
 }

int main() {
Node* root = buildTree();
 vector<vector<int>> ans;
 levelOrderTraversal(root,ans);
return 0;

}