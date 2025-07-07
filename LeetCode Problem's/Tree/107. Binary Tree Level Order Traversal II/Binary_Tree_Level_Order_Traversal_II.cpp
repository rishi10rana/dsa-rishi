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
    // appraoch - use level order traversal T.C = O(n)
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> bigList;
        
        // check if their is not tree
        if(root == NULL){
            return bigList;
        }

        stack<vector<int>> s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> smallList;
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                TreeNode* temp = q.front();
                q.pop();

                // store all nodes of one level in a smallList
                smallList.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            // push that list of nodes of a level in stack
            s.push(smallList);
        }
        // stack will return all your lists in bottom up way
        while(!s.empty()){
            bigList.push_back(s.top());
            s.pop();
        }
        return bigList;
    }
};