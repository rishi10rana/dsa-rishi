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
    // iteartive approach
    // T.C = O(Height or n) S.C = O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        
        while(temp!=NULL){
            if(temp->val == val){
                return temp; // mil gaya
            }
            if(val < temp->val){
                // go to left
                temp = temp -> left;
            }
            else{ // val > root->data
                // go to right
                temp = temp->right;
            }
        }
        return NULL; // means nahi milaa
    }
};