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
    // to find positon of element in inorder // O(n)
    /*
    int findInPosition(vector<int>& inorder,int element,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    */

    // other wauto find postion is to phela se store karlo 
    void storeMapping(vector<int>& inorder,map<int,int>& mp,int n){
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,
    int& preIndex,int n,map<int,int>& mp){
        // base case
        if(preIndex>=n || inStart > inEnd){
            return NULL;
        }

        // preOrder ke first ko uthate jo humara root hota hai
        int element = preorder[preIndex++];
        // isko node root node banado 
        TreeNode* root = new TreeNode(element);


        // ab iss element ki position find karo in inorder
        // int position = findInPosition(inorder,element,n);
        // map bhi use karsakt to find the positon in inorder fast , bas ek parameter aur badh jayega
        // map ko pass by reference karna warna bhut sarii copy ban jaegi map kii due to recursion
        // aur ye memory exceed cause kardega
        int position = mp[element];


        // abb root ka left banane ke liya aur root ka right banane ke liya call kardo
        root->left = solve(preorder,inorder,inStart,position-1,preIndex,n,mp);
        root->right = solve(preorder,inorder,position+1,inEnd,preIndex,n,mp);

        // wapis jab node pe pahcuha to upar current node jo root hai wahi return kardo
        return root;
    }
 
    // T.C = O(n) * O(n)    // after using map  T.C = O(n)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int inStart = 0;
        int inEnd = n-1;
        int preIndex = 0;

        map<int, int> mp;  // inOrder element -> to their index
        storeMapping(inorder,mp,n);

        TreeNode* root = solve(preorder,inorder,inStart,inEnd,preIndex,n,mp);
        return root;
    }
};