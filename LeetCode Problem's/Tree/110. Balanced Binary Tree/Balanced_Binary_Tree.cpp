/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    // Approach 1
    int height(TreeNode* root){
        // base case
        if(root==NULL){
            return 0;
        }

        int leftH = height(root->left);
        int rightH = height(root->right);

        // uar wale ko max height do inki + 1
        return max(leftH,rightH) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL){
            return true; // nothing on left or right of leaf node is always balanced
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = (abs(height(root->left) - height(root->right)) <= 1) ? true : false;
        if(left && right && diff){
            return true; // yes this node balanced
        }
        else{
            return false;
        }
    }
    */

    // Approach 2 using pair
    /*
    */
    pair<bool, int> helper(TreeNode* root){
        if(root == NULL){
            pair<bool ,int> p = make_pair(true,0); 
            return p; // nothing on left or right of leaf node is always balanced and heigth is 0
        }

        pair<bool ,int> left = helper(root->left);
        pair<bool ,int> right = helper(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = (abs(left.second - right.second) <= 1) ? true : false;
        
        pair<bool ,int> ans;
        
        if(leftAns && rightAns && diff){
            ans.first =  true; // yes this node balanced
        }
        else{
            ans.first = false;
        }

        // height to return above
        ans.second = max(left.second,right.second) + 1;
        return ans;
    }   

    bool isBalanced(TreeNode* root) {
        pair<bool , int> result;
        result = helper(root);
        return result.first;
    }
};