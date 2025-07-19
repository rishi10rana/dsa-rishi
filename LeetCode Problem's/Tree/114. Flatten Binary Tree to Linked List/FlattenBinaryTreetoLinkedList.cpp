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
    // T.C = O(n) S.C = O(1)
    void flatten(TreeNode* root) {
    
        // Will use Morris Traveral Technique
        while(root!=NULL){
            // agar mera left part exist nahi karta hai
            if(root->left==NULL){
                root = root->right;
            }

            // left part exists
            else{
                // left nde ke right most tak jao aur link create kardo
                TreeNode* current = root->left;
                while(current->right!=NULL){
                    current = current->right;
                }

                current->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right; // root ko aage baada do
            }
        }
    }
};