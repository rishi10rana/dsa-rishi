/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    // T.C = O(n) , S.C = O(n)
    vector<int> diagonal(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            // ye selectd node ke right jaata raho agar exist karta to
            // agar us node ka left milta to usse queue mei daaldo left wale ko
            while(node!=NULL){
                if(node->left!=NULL) q.push(node->left); // left hai to usse queue me store kardo
                ans.push_back(node->data); // current node ko ans mei daaldo
                node = node->right; // aur right mei jaaoo
            }
        }
        return ans;
    }
};