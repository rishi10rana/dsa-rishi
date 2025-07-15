/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    
    // T.C = O(n) , S.C = O(n)
    vector<int> topView(Node *root) {
        
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> mp; // maps a horizontal distance to the data of frst node encountered ath that hd
        
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0)); // store node,horizontal distance
        while(!q.empty()){
            
            pair<Node*,int> temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int hd = temp.second;
            
            // add the node in the map only if its hd is not mapped previosuly to any other node
            if(mp.find(hd)==mp.end()){
                mp[hd] = node->data;
            }
            if(node->left!=NULL){
                q.push(make_pair(node->left,hd-1));
            }
            if(node->right!=NULL){
                q.push(make_pair(node->right,hd+1));
            }
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};