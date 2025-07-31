/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class Info{ // for each node we store these data
    public:
    int maxii;
    int mini;
    bool isBST;
    int size;
};


class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    
    Info solve(Node* root, int& maxSize){
        // base case agar null pahuch gaye to wo bst hota hai
        if(root == NULL){
            return {INT_MIN, INT_MAX, true, 0};
        }
        
        // left call karo right call karo waha se data aayega
        Info left = solve(root->left, maxSize);
        Info right = solve(root->right, maxSize);
        
        // jab wapis root node par aayenga to abb usse check karo aur uska data nikalo
        Info currentNode;
        
        currentNode.size = left.size + right.size + 1;
        currentNode.maxii = max(root->data, right.maxii);
        currentNode.mini = min(root->data, left.mini);
        
        // ab check karo ye node bst hai ki nahi using 3 conditions
        
        if(left.isBST && right.isBST && left.maxii<root->data && root->data<right.mini){
            currentNode.isBST = true; // yes bst hai
        }
        else{
            currentNode.isBST = false; // nahi hai bst
        }
        
        // agar bst hai to isse node tak jo size mila wo answer ho sakta
        if(currentNode.isBST){
            maxSize = max(maxSize, currentNode.size); // update karlo
        }
        
        // jo data mila usse upar bhejdo
        return currentNode;
    }
    
    // T.C = O(n) , S.C = O(height)
    int largestBst(Node *root) {
        
        int maxSize = 0;
        Info temp = solve(root, maxSize); // 
        
        return maxSize;
    }
};