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
    //T>C = o(n) , S>C = O(n) will be affected by map
    vector<int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        map<int,int> mp; // maps the horizontal distance to lastest node->data encountered in furing traversal
        queue<pair<Node*,int>> q;
        q.push(make_pair(root,0));
        // Do level-order traversal
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* node = temp.first;
            int hd = temp.second;
            
            // update the latest last node found for each horizontal distance
            mp[hd] = node->data;
            
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