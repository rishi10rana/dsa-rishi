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
    TreeNode* solve(vector<int>& preorder, int mini, int maxii, int& i){
        // base case
        if(i >= preorder.size()){ // means pura reorder traverse kar liya
            return NULL;
        }
        if(preorder[i] < mini || preorder[i] > maxii){ // range ke bahar
            return NULL;
        }
        
        // node banado
        TreeNode* root = new TreeNode(preorder[i++]);
        // call for left then right
        root->left = solve(preorder, mini, root->val,i);
        root->right = solve(preorder, root->val, maxii, i);

        // kisi node ke lift ya right se wapis aaye to us node ko upar behejdo
        return root;
    }
    // T.C = O(n)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxii = INT_MAX;
        int i = 0;
        return solve(preorder, mini, maxii, i);
    }
    */
    
    // Small Optimization using only maxii
    TreeNode* solve(vector<int>& preorder, int maxii, int& i){
        // base case
        if(i >= preorder.size()){ // means pura reorder traverse kar liya
            return NULL;
        }
        if(preorder[i] > maxii){ // range ke bahar
            return NULL;
        }
        
        // node banado
        TreeNode* root = new TreeNode(preorder[i++]);
        // call for left then right
        root->left = solve(preorder,root->val,i);
        root->right = solve(preorder,maxii, i);

        // kisi node ke lift ya right se wapis aaye to us node ko upar behejdo
        return root;
    }
    // T.C = O(n)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int maxii = INT_MAX;
        int i = 0;
        return solve(preorder, maxii, i);
    }
};