// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    // Function to return the maximum sum of non-adjacent nodes.
    
    
    // maintain two things in pair for ach node
    // (max sum by including that node , max sum by not including that node)
    pair<int, int> helper(Node* root){
        if(root==NULL){
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        
        pair<int, int> result;
        
        result.first = root->data + left.second + right.second;
        result.second = max(left.first,left.second) + max(right.first,right.second);
        
        return result;
    }
    
    // T.C = O(n) , S.C = O(height)
    int getMaxSum(Node *root) {
        // code here
        pair<int ,int> ans = helper(root);
        return max(ans.first,ans.second);
    }
};