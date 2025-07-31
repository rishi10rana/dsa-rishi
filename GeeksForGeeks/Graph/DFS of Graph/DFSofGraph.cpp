class Solution {
  public:
  
    void solveDFS(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans){
        visited[node] = 1;
        ans.push_back(node);
        
        // ab id "node" ke unvisited neighbourse ko visit karo
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){ // if not visitd
                solveDFS(adj[node][j], adj, visited, ans);
            }
        }
    }
  
 
    // T.C = O(v + e) S.C = O(v)
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> visited(V,0);
        vector<int> ans;
        solveDFS(0, adj, visited, ans);
        return ans;
    }
};