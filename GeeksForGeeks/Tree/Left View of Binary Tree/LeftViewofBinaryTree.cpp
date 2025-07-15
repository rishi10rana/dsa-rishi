/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    //  traverse using DFS // T.C = o(n) 
    void helper(Node* root, vector<int>& ans, int level){
        // base case
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            // means add that node data in answer
            ans.push_back(root->data);
        }
        
        helper(root->left, ans,level+1);
        helper(root->right, ans, level+1);
    }
  
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        helper(root, ans, 0);
        return ans;
    }
};