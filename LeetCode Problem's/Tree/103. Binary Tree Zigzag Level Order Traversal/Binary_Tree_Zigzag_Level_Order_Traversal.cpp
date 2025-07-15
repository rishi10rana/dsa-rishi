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
    // T.C = O(n) S.C = O(n)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        // check tree hai ki nahi
        if(root==NULL){
            return result;
        }

        // Apply level order traversal but also keep trak of size of eacgh level
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            // size of current level
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                // kis order mei element insert karke is level mei
                int index = leftToRight ? i : size-i-1;
                temp[index] = node->val;

                // now add the neighbours of this node in queue
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            // after each level change
            leftToRight = !leftToRight; 
            // ek level ka jo answer aayega usse result mei daaldo
            result.push_back(temp);
        }
        return result;
    }
};