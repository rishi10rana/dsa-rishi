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
    // Using Preorder Traversal
    void preorder(TreeNode* root, int &count){
        if(root == NULL){
            return;
        }
        count = count + 1;
        preorder(root->left, count);
        preorder(root->right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        preorder(root, count);
        return count;
    }
};