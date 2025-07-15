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
    // T.C = O(n) , S.C = O(n)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> bigList;
        // check karlo ki tree hai ki nahi
        if(root==NULL){
            return bigList;
        }
        
        // ye map store karega phaela to horzontal distance -> fhir har horizontal distance mie ke particualr level ko -> ki  uss level mei kitna nodes hai unko ek vector mei rakhega
        map<int,map<int,vector<int>>> mp;
        // doing level order traversal , so track node , horizonal distance , level
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* node = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            mp[hd][lvl].push_back(node->val);
            if(node->left!=NULL){
                q.push(make_pair(node->left,make_pair(hd-1,lvl+1)));
            }
            if(node->right!=NULL){
                q.push(make_pair(node->right,make_pair(hd+1,lvl+1)));
            }
        }
        for(auto i: mp){
            vector<int> smallList;
            for(auto j: i.second){
                sort(j.second.begin(),j.second.end()); // this line is here to sort the nodes by values which come in the same level 
                for(auto k: j.second){
                    smallList.push_back(k);
                }
            }
            bigList.push_back(smallList);
        }

        return bigList;
    }
};