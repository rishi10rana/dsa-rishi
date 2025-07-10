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
    // Approach - move through both tree nodes ar same time T>C = O(n)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        if(p==NULL && q==NULL){
            return true; // yaha para to dono dame hai
        }
        if(p==NULL && q!=NULL || p!=NULL && q==NULL){
            return false; // means yaha par dono same nahi hai
        }

        bool left = isSameTree(p->left,q->left); // left dono ka same hai kya
        bool right = isSameTree(p->right,q->right);
        
        bool val = (p->val == q->val) ? true : false; // value bhi same agar
        
        if(left && right && val){
            return true; // ye node to same hai dono mei
        }
        else{
            return false;
        }
    }
};