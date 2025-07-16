/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    // T.C = O(n) S.C = O(height)
    Node* helper(Node* root, int& k, int node){
        // base case 
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==node){ // matlab node to mil gaya
            return root;
        }
        
        Node* leftAns = helper(root->left, k ,node);
        Node* rightAns = helper(root->right, k ,node);
        
        // jab wapis aa rahe ho kisi node pe
        
        if(leftAns!=NULL && rightAns==NULL){
            k--; // matlab ye ek ancestor hai
            if(k<=0){
                k = INT_MAX;
                return root; // means yahi node kth ancestor hai
            }
            return leftAns;
        }
        
        if(leftAns==NULL && rightAns!=NULL){
            k--; // matlab ye ek ancestor hai
            if(k<=0){
                k = INT_MAX;
                return root; // means yahi node kth ancestor hai
            }
            return rightAns;
        }
        
        else{ // means dono side null aaya
            return NULL;
        }
    }
  
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        Node* ans = helper(root,k,node);
        if(ans==NULL || ans->data == node){ // means kth ancesror nahim milaa ya nahi ho sakta
            return -1;
        }
        return ans->data;
    }
};
