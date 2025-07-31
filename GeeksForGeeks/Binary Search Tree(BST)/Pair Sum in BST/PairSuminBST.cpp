/*
Node is as follows
class Node {
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
    void inorder(Node* root, vector<int>& arr){
        // base case
        if(root==NULL){
            return;
        }
        // left 
        inorder(root->left, arr);
        // node
        arr.push_back(root->data);
        // right
        inorder(root->right, arr);
    }
    
    // T.C = O(n) S.C = O(n)
    bool findTarget(Node *root, int target) {
        // your code here
        
        vector<int> arr;
        inorder(root, arr); // get the inorder
        
        // 2 pointer
        int i = 0;
        int j = arr.size()-1;
        while(i<j){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return true; // pair mil gaya
            }
            else if(sum > target){
                j--;
            }
            else if(sum < target){
                i++;
            }
        }
        return false;
    }
};