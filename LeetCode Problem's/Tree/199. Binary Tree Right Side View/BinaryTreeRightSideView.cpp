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
    // T.C = O(n) , S.C = O(depth pr height)
    // DFS Approach 
    void helper(TreeNode* root, vector<int>& ans, int level){
        // base case
        if(root==NULL){
            return;
        }
        if(ans.size()==level){
            // uss node ko answer mei add kardo
            ans.push_back(root->val);
        }

        // phela right jao fhir left
        helper(root->right, ans, level+1);
        helper(root->left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        helper(root, ans, 0);
        return ans;
    }
    */
    
    // Approach - level order T.C = O(n) , S.C = O(n)
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        map<int, int> mp; // map level to the data of first node that occurs in that level
        queue<pair<TreeNode*, int>> q;// store the node and its level
        q.push(make_pair(root,0));
        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int level = temp.second;

            // map the node to the level only thr level is not previosuly to mapped to anyone
            if(mp.find(level)==mp.end()){
                mp[level] = node->val;
            }
            // phela right walako add karna fhir left wale koo
            if(node->right!=NULL){
                q.push(make_pair(node->right, level+1));
            }
            if(node->left!=NULL){
                q.push(make_pair(node->left, level+1));
            }
        }
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};