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
    // DFS use karo T.C = O(n) , S.C = O(height)
    void helper(TreeNode* root,int targetSum, vector<int> path, int& count){
        // BC
        if(root==NULL){
            return;
        }
        path.push_back(root->val);

        helper(root->left,targetSum,path,count);
        helper(root->right,targetSum,path,count);

        // jab kisi node pe wapis aaoge to us ko include karne wali saii path kao chak karlo
        // usss node se lekar piche travers akro in path
        int n = path.size();
        long sum = 0; // kyuki path me sabka sum nikalega to bhut jayada bhi aa sakta
        for(int i=n-1;i>=0;i--){
            sum = sum + path[i];
            if(sum==targetSum){
                count++;
            }
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        vector<int> path;
        helper(root,targetSum,path,count);
        return count;   
    }
};