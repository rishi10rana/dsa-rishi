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
    // T.C = O(n + n) = O(2n) as traversing all nodes of tree 2 times
    // S.C = O(n) recursion stack
    long totalSum = 0;
    long maxP = INT_MIN;
    //  this function helps to find the total sum of all nodes in the tree
    int find_total_sum(TreeNode* root){
        // base case
        if(root == NULL){
            return 0; // kyuki waha to koii node nahi hai means waha se sum 0 aayega
        }

        int leftSum = find_total_sum(root->left);
        int rightSum = find_total_sum(root->right);
        // at current node
        long sum =  root->val + leftSum + rightSum;

        return sum;
    }

    // find the max product fucntion
    int find_max_product(TreeNode* root){
        // base case
        if(root == NULL){
            return 0;
        }

        int leftSum = find_max_product(root->left);
        int rightSum = find_max_product(root->right);
        // jis node par hai hum agar usse subtree banaye
        long subtreeSum = root->val + leftSum + rightSum;

        // remaining subtree sum
        long remainingsubtreeSum = totalSum - subtreeSum;

        // update max product
        maxP = max(maxP, subtreeSum * remainingsubtreeSum);

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        
        // we need total sum of all nodes in tree
        totalSum = find_total_sum(root);

        // this fucntion call will help to find the max product possible by splitting tree in two
        find_max_product(root);

        return maxP % 1000000007;
    }
};