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
    // using simple inoder traversal T.C = O(n) , S.C=O(H or n)
    /*
    int inorder(TreeNode* root, int k, int& i){
        // base case
        if(root==NULL){
            return -1;
        }
        // L 
        int left = inorder(root->left,k,i);
        if(left!=-1){ // means shsayd ans aaya huai upar se upar behj do direct
            return left;
        }

        // N
        i++;
        if(i==k){ // yahi answer
            return root->val;
        }

        // R
        return inorder(root->right,k,i);
    }


    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = inorder(root,k,i);
        return ans;
    }
    */

        
    // using morris inorder traversal
    // T.C = O(n) S.C = O(1)
    void morris(TreeNode* root, int k,int& min){
        int i = 0;
        while(root!=NULL){
            // left exist nahi karta
            if(root->left==NULL){
                // means left karne ke badd yaha aaye
                i++;
                if(i==k){
                    min = root->val;
                }
                root = root->right; // go right
            }
            
            // left exist karta
            else{
                TreeNode* current = root->left;
                while(current->right!=NULL && current->right!=root){ // left ke rightmost tak jaoo
                    current = current->right;
                }
                // left traversed nahi hai
                if(current->right==NULL){
                    current->right = root; // link banao
                    // go left
                    root = root->left;
                }                
            
                // left traversed hai
                else{
                    // means left karne ke badd yaha aaye
                    i++;
                    if(i==k){
                        min = root->val;
                    }
                    current->right = NULL; // link todd doo
                    root = root->right;
                }
            }
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int min = 0;
        morris(root,k,min);
        return min;
    }
};