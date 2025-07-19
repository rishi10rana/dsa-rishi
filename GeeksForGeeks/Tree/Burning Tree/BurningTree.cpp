/*
class Node {
  public:
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
    Node* createMapping(Node* root, map<Node*,Node*>& nodeToParent,int target){
        // use Level Order
        // also find target Node
        Node* temp;
        
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL; // root ka koii parent nahi hota
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            
            if(node->data == target){
                temp = node;
            }
            
            if(node->left!=NULL){
                nodeToParent[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right!=NULL){
                nodeToParent[node->right] = node;
                q.push(node->right);
            }
        }
        return temp; 
    }
    
    // This wil burn the tree and return the minimum time
    int burnTree(Node* target, map<Node*,Node*>& nodeToParent){
        // use level order traversal
        
        int time = 0;
        
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(target);
        visited[target] = 1;
        while(!q.empty()){
            int size = q.size();
            bool flag = 0; // to check ek elemet pop karne ke baad queue me koii chnage aat hai kya
        
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                
                // iss queue se nikale gaye node ke bhai bando ko check karo (left , right , Parent)
                if(node->left!=NULL && !visited[node->left]){
                    visited[node->left] = 1;
                    q.push(node->left);
                    flag = 1;
                }
                
                if(node->right!=NULL && !visited[node->right]){
                    visited[node->right] = 1;
                    q.push(node->right);
                    flag = 1;
                }
                
                if(nodeToParent[node]!=NULL && !visited[nodeToParent[node]]){
                    visited[nodeToParent[node]]=1;
                    q.push(nodeToParent[node]);
                    flag = 1;
                }  
            }
            if(flag==1){ // queue me change hua hai to time update kardo
                time++;
            }
        }
        
        return time;
    }
  
    // T.C = O(n) as level order used in both functions
    // S.C= O(n)
    int minTime(Node* root, int target) {
        // code here
        map<Node*,Node*> nodeToParent;
        Node* targetNode = createMapping(root,nodeToParent,target);
        
        int ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};