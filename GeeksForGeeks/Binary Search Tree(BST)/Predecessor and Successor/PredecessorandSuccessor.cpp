/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    Node* findPre(Node* root, int key){
        Node* pre = NULL;
        while(root!=NULL){
            if(key > root->data){
                // choti value predecessor ho sakti
                pre = root;
                // go right
                root = root->right;
            }
            else{  // key <= root->data;
                // go left
                // to check shayd koi cloe value mil jaye
                root = root->left;
            }
        }
        return pre;
    }
    
    Node* findSuc(Node* root, int key){
        Node* suc = NULL;
        while(root!=NULL){
            if(key >= root->data){
                // go to right
                root = root->right;
            }
            else{ // key < root->data;
                // value baddi mil gayi shayd answer ho
                suc = root;
                // go to left
                root = root->left;
            }
        }
        return suc;
    }
    
  // T.C = O(H) , S.C = O(1)
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        Node* predecessor = findPre(root, key);
        Node* successor = findSuc(root, key);
        
        ans.push_back(predecessor);
        ans.push_back(successor);
        return ans;
    }
};