/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void helper(Node* root,int sum,int& maxSum,int len, int& maxLen){
        // base case
        if(root==NULL){ // shayad leaf node ho sakta isliya ans update rakho
            if(len > maxLen){
                maxSum = sum;
                maxLen = len;
            }
            else if(len==maxLen){
                maxSum = max(maxSum,sum);
            }
            return;
        }
            
        sum = sum + root->data;
        helper(root->left,sum,maxSum,len+1,maxLen);
        helper(root->right,sum,maxSum,len+1,maxLen);
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int sum = 0;
        int maxSum = INT_MIN;
        
        int len = 0;
        int maxLen = 0;
        helper(root,sum,maxSum,len,maxLen);
        return maxSum;
    }
};