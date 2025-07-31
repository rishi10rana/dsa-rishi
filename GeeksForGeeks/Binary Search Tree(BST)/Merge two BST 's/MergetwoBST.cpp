/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    
    // LNR
    void inorder(Node* root, vector<int>& arr){
        if(root == NULL){
            return;
        }
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }
    
    void mergeTwoSortedArrays(vector<int> inorder1, vector<int> inorder2, vector<int>& finalInorder){
        int i = 0;
        int j = 0;
        int index = 0;
        while(i<inorder1.size() && j<inorder2.size()){
            if(inorder1[i]<=inorder2[j]){
                finalInorder[index] = inorder1[i];
                i++;
                index++;
            }
            else{
                finalInorder[index] = inorder2[j];
                j++;
                index++;
            }
        }
        
        while(i<inorder1.size()){
            finalInorder[index] = inorder1[i];
            i++;
            index++;
        }
        
        while(j<inorder2.size()){
            finalInorder[index] = inorder2[j];
            j++;
            index++;
        }
    }
    
    Node* inorderToBST(vector<int>& inorder, int start, int end){
        // base case
        if(start > end){
            return NULL;
        }
        
        int mid = start + (end-start)/2;
        Node* root = new Node(inorder[mid]);
        
        root->left = inorderToBST(inorder, start, mid-1);
        root->right = inorderToBST(inorder, mid+1, end);
        
        return root;
    }
    
    
    // T.C = O(m + n) , S.C = O(m + n)
    vector<int> merge(Node *root1, Node *root2) {
        
        // Step 1 store the inorder of both the BST
        vector<int> inorder1;
        inorder(root1, inorder1);
        
        vector<int> inorder2;
        inorder(root2, inorder2);
        
        // Step 2 now merge the above two sorted inorder to form 1 single inorder
        int n = inorder1.size() + inorder2.size();
        vector<int> finalInorder(n, 0);
        mergeTwoSortedArrays(inorder1, inorder2, finalInorder);
        
        
        // sTep 3 is final inorder jo hume mila merge karke upar ke dono ko isse BST bana lo
        // inorder to BST
        int start = 0;
        int end = finalInorder.size()-1;
        Node* newRoot = inorderToBST(finalInorder, start, end); // bst ban gaya
        
        // jo bst bana uska inorder store karke dedo
        vector<int> result;
        inorder(newRoot, result);
        return result;
    }
};