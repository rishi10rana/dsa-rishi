/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution {
  public:
    // T.C = O(n)
    void preorder(Node* root, int &count){
        // base case
        if(root==NULL){
            return;
        }
        // for a leaf node
        if(root->left==NULL && root->right==NULL){
            count++;
        }
        preorder(root->left,count);
        
        preorder(root->right,count);
    }
  
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node* root) {
        // write code here
        int count = 0;
        preorder(root,count);
        return count;
    }
};