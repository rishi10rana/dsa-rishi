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
    // Left Node Right
    void inorder(TreeNode* root, vector<int>& result){
        // base case
        if(root==NULL){
            return;
        }

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    // Recursive Approach T.C = O(n) S.C = O(Height)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};