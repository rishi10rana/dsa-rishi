/*The structure of Node

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
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    
    // T.C = O(H) , S.C = O(1)
    int inOrderSuccessor(Node *root, Node *x) {
        // Your code here
        int successor = -1;
        
        while(root!=NULL){
            if(x->data >= root->data){
                // go  right
                root = root->right;
            }
            else{ // x->data < root->data
                // matlab ek posible badi value mil gayi
                successor = root->data;
                // go left to find any value more close
                root = root->left;
            }
        }
        return successor;
    }
};