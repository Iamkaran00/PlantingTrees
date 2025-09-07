#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node {
    int val ;
    Node * left ;
    Node * right ;
     Node( int x ) : val(x),left(nullptr) ,right (nullptr) {};
     Node(int x,Node* l,Node*r) : val(x),right(r),left(l) {};
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
vector<int> IterativeInorder(Node * root) {
stack<Node*>st;
vector<int>ans;
Node * node = root;
while(true) {
    if(node){
        st.push(node);
        node = node->left;
    } else {
        if(st.empty()) break;
         node = st.top();
        st.pop();
        ans.push_back(node->val);
        node = node->right;
    }
}
return ans;
}
int main() {

    Node* root = buildTree();
vector<int> ans =  IterativeInorder(root);
     for(auto & el : ans) {
        cout<<el<<" ";
     }
    return 0;
}

