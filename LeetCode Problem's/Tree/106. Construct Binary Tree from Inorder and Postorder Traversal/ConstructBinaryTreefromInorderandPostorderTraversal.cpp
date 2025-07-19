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
    // helps to find the index of the root in the inorder
    void createMapping(vector<int>& inorder,map<int, int>& mp,int n){
        for(int i=0;i<n; i++){
            mp[inorder[i]] = i; 
        }
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int& postIndex,map<int, int>& mp){
        // base case 
        if(postIndex < 0 || inStart > inEnd){
            return NULL;
        }

        // create the root node using the current postIndex
        int element = postorder[postIndex--];
        TreeNode* root = new TreeNode(element);

        // find the element now in inorder
        int position = mp[element];

        // int this case first make right subtree then left subtree as here we start from 
        // rightmost index of preorder
        root->right = helper(inorder, postorder, position+1, inEnd, postIndex,mp);
        root->left = helper(inorder, postorder, inStart, position-1, postIndex,mp);

        return root;
    }

    // T.C = O(n*logn + n) S.C = O(n + height)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inStart = 0;
        int inEnd = n - 1;
        int postIndex = n - 1;
        map<int, int> mp;
        createMapping(inorder,mp,n); // this function just maps the element of inorder to their indexes

        TreeNode* ans = helper(inorder,postorder,inStart,inEnd,postIndex,mp);
        return ans;
    }
};