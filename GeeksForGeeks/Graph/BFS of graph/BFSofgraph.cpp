class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {

        
        // T.C = O(v + e)  S.C = O(v)
        int v = adj.size();
        
        queue<int> q;
        vector<bool> visited(v, 0);
        vector<int> ans;
        
        int node;
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            ans.push_back(node);
            // jis node ko pop kiya uska neighbours ko traverse karo in adj list 
            // aur jo visted nahi hai inho queue mei daalo aur mark kardo visited
            for(int j=0;j<adj[node].size();j++){
                if(!visited[adj[node][j]]){
                    visited[adj[node][j]] = 1;
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};