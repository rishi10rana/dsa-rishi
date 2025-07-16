// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // other wauto find postion is to phela se store karlo 
    void storeMapping(vector<int>& inorder,map<int,int>& mp,int n){
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
    }
  
    Node* solve(vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,
    int& preIndex,int n,map<int,int>& mp){
        // base case
        if(preIndex>=n || inStart > inEnd){
            return NULL;
        }

        // preOrder ke first ko uthate jo humara root hota hai
        int element = preorder[preIndex++];
        // isko node root node banado 
        Node* root = new Node(element);


        // ab iss element ki position find karo in inorder
        // int position = findInPosition(inorder,element,n);
        // map bhi use karsakt to find the positon in inorder fast , bas ek parameter aur badh jayega
        int position = mp[element];


        // abb root ka left banane ke liya aur root ka right banane ke liya call kardo
        root->left = solve(preorder,inorder,inStart,position-1,preIndex,n,mp);
        root->right = solve(preorder,inorder,position+1,inEnd,preIndex,n,mp);

        // wapis jab node pe pahcuha to upar current node jo root hai wahi return kardo
        return root;
    }    
  
  
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = preorder.size();
        int inStart = 0;
        int inEnd = n-1;
        int preIndex = 0;

        map<int, int> mp;  // inOrder element -> to their index
        storeMapping(inorder,mp,n);

        Node* root = solve(preorder,inorder,inStart,inEnd,preIndex,n,mp);
        return root;
    }
};