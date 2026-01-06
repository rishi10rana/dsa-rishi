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
    // BFS (level by level) tree traversal
    /*
    int maxLevelSum(TreeNode* root) {
        
        int resultlevel = 0;
        int maxSum = INT_MIN;

        int currlevel = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                // add left child if exist
                if(temp->left){
                    q.push(temp->left);
                }
                // add right child if exist
                if(temp->right){
                    q.push(temp->right);
                }
            }

            // at end of each level check the level sum
            if(sum > maxSum){
                // agar level ka sum bada hua to update maxsum and level jaha 
                // woh mila
                maxSum = sum;
                resultlevel = currlevel;
            }

            // increment lvl as moving on next level
            currlevel++;
        }

        return resultlevel;
    }
    */

    // DFS tree traversal(inorder- left , root, right)
    void dfs(TreeNode* root, int level){
        // base case 
        // agar null mila
        if(root == NULL){
            return; // chup chap wapis aajao
        }

        // left
        dfs(root->left, level+1);
        // root
        mp[level] = mp[level] + root->val;
        // right
        dfs(root->right, level+1);
    }

    unordered_map<int ,int> mp;
    int maxLevelSum(TreeNode* root) {
        mp.clear();
        
        // call dfs pass root node and root node level
        dfs(root, 1);

        // we can use unordered_map, ordered_map, vector anything
        // i use unordered_map but ordered_map makes work more easy
        // traverse in map to find smallest level which has maximum sum
        int maxSum = INT_MIN;
        int resultlevel = 0;
        for(auto &pair: mp){
            int currlevel = pair.first;
            int levelsum = pair.second;
            if(levelsum > maxSum){
                maxSum = levelsum;
                // agar chota level mila to wahi consider karlo
                resultlevel = currlevel;
            }
            else if(levelsum == maxSum){
                resultlevel = min(resultlevel, currlevel);
            }
        }

        return resultlevel;
    }
};