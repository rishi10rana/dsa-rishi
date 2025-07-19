// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // T.C = O(n) S.C = O(1)
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans;
        
        // Node
        // Left
        // Right
        
        // Morris Traversal
        while(root!=NULL){
            // left exist nahi karta
            if(!root->left){
                ans.push_back(root->data);
                root = root->right;
            }

            // left exist karta hai
            else{
                Node* current = root->left;
                while(current->right!=NULL && current->right!=root){ // left node ke rightmost tak jao
                    current = current->right;
                }
                
                // left traversed nahi hai
                if(current->right==NULL){
                    ans.push_back(root->data);
                    current->right = root; // link banado
                    root = root->left;
                }
                
                // left phela se hi traversed hai
                else{
                    current->right = NULL; // link todd do
                    root = root->right;
                }
            }
        }
        return ans;
    }
};