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
    /*
    // Recursive approach T.C = O(n) S.C = O(H or n)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base csae
        if(root==NULL){
            return NULL; // means found nothing
        }

        if(root->val < p->val && root->val < q->val){
            // go to the right
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val > p->val && root->val > q->val){
            // go to the left
            return lowestCommonAncestor(root->left,p,q);
        }
        else{ // (root->val > p->val && root->val < q->val) || (root->val > q->val && root->val < p->val) || or any other case
            return root;
        }
    }
    */

    // Iteartive Approach T.C = O(n) S.C = O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val < p->val && root->val < q->val){
            // go to the right
            root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                // go to the left
                root = root->left;
            }
            else{ // (root->val > p->val && root->val < q->val) || (root->val > q->val && root->val < p->val) || or any other case
                return root;
            }
        }
        return NULL;  
    }
};