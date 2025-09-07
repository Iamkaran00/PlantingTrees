#include<iostream>
#include<stack>
#include<vector>
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
  void preorderTraversal(Node * root , vector<int> &ans){ 
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node * node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
  }
int main()
{
    Node* root = buildTree();
    vector<int> ans;
    preorderTraversal(root,ans);  
    for(auto i : ans) cout<<i<<" ";
    return 0;
}
