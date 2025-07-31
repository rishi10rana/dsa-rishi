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
    // T.C = O(n) S.C = O(height) or worst O(n)
    bool isBST(TreeNode* root, long min, long max){
        // base case
        if(root==NULL){
            return true; // null means ki uski wajah se tree to bst hoga hii
        }

        // check node
        if(min < root->val && root->val < max){
            // uske left aur right wlo ko check akrna fhir
            bool left = isBST(root->left, min , root->val);
            bool right = isBST(root->right, root->val , max);
            // jab node pe left right se wapis aao
            return left && right; // agar dono node true de tabhi upar true bhejna
        }
        else{
            return false;
        }
    }


    bool isValidBST(TreeNode* root) {
        long min = LONG_MIN;
        long max = LONG_MAX;
        return isBST(root,min,max);
    }
};