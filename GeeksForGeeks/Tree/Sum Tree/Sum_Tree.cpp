/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  
  // T.C = O(n)
    pair<bool, int> helper(Node* root){
        // base - for non-leaf nodes
        if(root == NULL){
            pair<bool, int> p = make_pair(true,0); // as null node have 0 sum
            return p;
        }
        
        // base case - for leaf nodes
        if(root->left == NULL && root->right == NULL){ // but stop at leaf node
            pair<bool ,int> p = make_pair(true, root->data);
            return p; // we consider leaf node as sum tree
        }
        
        pair<bool , int> left = helper(root->left);
        pair<bool , int> right = helper(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool value = (root->data == left.second + right.second) ? true : false;
        
        pair<bool, int> ans;
        
        if(leftAns && rightAns && value){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        ans.second = left.second + right.second + root->data;
        return ans;
    }
  
    bool isSumTree(Node* root) {
        // Your code here
        pair<bool , int> result = helper(root);;
        return result.first;
    }
};