/*Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
    void inorder(Node* root, vector<int>& arr){
        // base case
        if(root==NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right,arr);
    }
  
   // craete balanced bst using inorder array
    Node* inorderToBST(int start, int end, vector<int>& arr){
        // base case 
        if(start>end){
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        // mid ko node banado
        Node* root = new Node(arr[mid]);
        
        // left subtree ke liya call kardo
        root->left = inorderToBST(start,mid-1,arr);
        
        // right subtree ke liya call kardo
        root->right = inorderToBST(mid+1,end,arr);
        
        
        // jab wapis node par aao to ussi node ko upar bhej do
        return root;
    }
  
    // T.C = O(n) S.C = O(n)
    Node* balanceBST(Node* root) {
        // Code here
        
        vector<int> arr;
        inorder(root, arr);
        
        int start = 0;
        int end = arr.size()-1;
        return inorderToBST(start,end,arr);
    }
};