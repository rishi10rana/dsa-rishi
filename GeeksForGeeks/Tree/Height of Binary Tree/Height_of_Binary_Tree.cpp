/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        // base case
        if(node==NULL){
            return -1; // means usse left ya right subtree ki height -1 maanlo
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        int height = max(leftHeight,rightHeight) + 1;
        return height;
    }
};