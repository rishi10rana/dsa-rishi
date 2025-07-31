// Function to search a node in BST.

// T.C = O(Height) or worst = O(n)
// S.C = O(Height)
// recursive approach
bool search(Node* root, int x) {

    // base case
    if(root==NULL){
        return false; // node is not found , abssent
    }
    if(root->data == x){
        return true; // element found
    }
    
    // where to go
    if(x < root->data){
        return search(root->left, x); // go to left
    }
    else{
        return search(root->right, x); // go to right
    }
}