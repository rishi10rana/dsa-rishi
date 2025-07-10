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
    // T.C = O(n)
    int maxDepth(TreeNode* root) {
        // base case
        if(root == NULL){
            return 0; // koii node nahi left ya right mei
        }

        int h1 = maxDepth(root->left);
        int h2 = maxDepth(root->right);
        
        int ans = max(h1,h2) + 1;
        
        return ans;
    }
};