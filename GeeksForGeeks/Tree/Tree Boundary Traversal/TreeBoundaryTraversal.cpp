/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseLeft(Node* root,vector<int>& ans){
        // bae case
        if(root == NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            // leaf node dont add it
            return;
        }
        
        // jaate jaate add karo
        ans.push_back(root->data);
        if(root->left!=NULL){
            traverseLeft(root->left,ans);
        }
        else{
            traverseLeft(root->right,ans);
        }
    }
    
    void traverseLeaf(Node* root,vector<int>& ans){
        // base case
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            // add kardo leaf node ko
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
    }
    
    void traverseRight(Node* root,vector<int>& ans){
        // base case
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            return;
        }
        
        if(root->right!=NULL){
            traverseRight(root->right,ans);
        }
        else{
            traverseRight(root->left,ans);
        }
        ans.push_back(root->data);
    }
  
    // as just traversing nodes so T.C = O(n)
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        
        // add root node at first
        ans.push_back(root->data);
        
        // traverse only left side wale
        traverseLeft(root->left,ans);
        
        // traverse all leaf nodes
        // traverseLeaf(root,ans); // this will give error in acse if root is leaf itself
        
        // can traverse all leaf nodes i nthis separate call also
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right,ans);
        
        
        // traverse all right side nodes
        traverseRight(root->right,ans);
        
        return ans;
    }
};