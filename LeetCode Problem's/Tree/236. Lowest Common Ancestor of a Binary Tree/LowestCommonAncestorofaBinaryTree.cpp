/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Approach - use DFS T.C = O(n) S.C = O(height)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL || root==p || root==q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // wapis aate wakt 3 case banenga to check
        if(left==NULL && right!=NULL){
            return right;
        }
        else if(left!=NULL && right==NULL){
            return left;
        }
        else if(left==NULL && right==NULL){
            return left;
        }
        else{ // maltba dono mei null nahi hai matlab ye lca hai
            return root;
        }
    }
};