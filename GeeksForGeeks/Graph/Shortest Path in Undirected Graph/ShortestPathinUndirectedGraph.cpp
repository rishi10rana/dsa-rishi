class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    
    // BFS
    // T.C = O(V + E) S.C = O(V + E) + 3V 
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        
        int V = adj.size();
        
        vector<int> dist(V,-1);
        vector<bool> visited(V, 0);
        queue<int> q;
        
        q.push(src);
        visited[src] = 1;
        dist[src] = 0;
        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            // look at its neighbours
            for(int j=0;j<adj[node].size();j++){
                if(visited[adj[node][j]]){
                    continue; // skip this node
                }
                // agar not visited
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
                
                dist[adj[node][j]] = dist[node] + 1;
            }
        }
        
        // jo nodes visit nahi ho paye unki distance -1 hi rahegi
        return dist;
    }
};