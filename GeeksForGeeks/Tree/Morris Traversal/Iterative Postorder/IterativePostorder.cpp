// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    // T.C = O(n) , S.C = O(1)
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        
        // Left right node
        // or node right left
        
        // Morris Traversal
        while(node){
            // right does not exits
            if(!node->right){
                ans.push_back(node->data);
                node = node->left;
            }
            
            // right exist karta
            else{
                Node* current = node->right;
                while(current->left!=NULL && current->left!=node){
                    current = current->left;
                }
                
                // right is not traversed
                if(current->left==NULL){
                    ans.push_back(node->data);
                    current->left = node;// link banado
                    node = node->right;
                }
                
                // right is already traversed
                else{
                    current->left = NULL; // link todd do
                    node = node->left;
                }
            }
        }
        // reverse the answer
        reverse(ans.begin(),ans.end());
        return ans;
    }
};