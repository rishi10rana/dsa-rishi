// User function Template for C++

/* Node of the binary search tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    /*
    // Approach 1
    void inorder(Node* root, vector<Node*>& arr){
        // base case
        if(root == NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root);
        inorder(root->right, arr);
    }
  
    // T.C = O(n) S.C = O(n)
    Node *flattenBST(Node *root) {
        // code here
        
        vector<Node*> arr;
        inorder(root, arr);
        
        // har node ko pakdo uska left null akrdo right ko aage ko next node pe point kardo

        for(int i = 0;i<arr.size()-1;i++){
            Node* node = arr[i];
            node->left = NULL;
            node->right = arr[i+1];
        }
        
        // last element 
        arr.back()->left = NULL;
        arr.back()->right = NULL;
        
        return arr[0];
    }
    */
    
    
    // Approach 2
    void inorder(Node* root, vector<int>& arr){
        // base case
        if(root == NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
  
    // T.C = O(n) S.C = O(n)
    Node *flattenBST(Node *root) {
        // code here
        vector<int> arr;
        inorder(root, arr);
        
        int n = arr.size();
        
        Node* newRoot = new Node(arr[0]);
        Node* current = newRoot;
        
        for(int i=1;i<n;i++){
            // new node banalo
            Node* temp = new Node(arr[i]);
            
            current->left = NULL;
            current->right = temp;
            current = current->right;
        }
       
        // last element 
        current->left = NULL;
        current->right = NULL;
        
        return newRoot;
    }
};