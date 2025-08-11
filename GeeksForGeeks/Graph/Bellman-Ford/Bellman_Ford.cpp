// User function Template for C++

class Solution {
  public:
    // Bellman Ford Algorithm
    // T.C = O(E(V-1)) + E = O(V * E)
    // S.C = O(V)
    
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        // 1e8 = 10^8 = 100000000
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        int E = edges.size();
        
        // relax all the edges (V-1) times
        for(int i=0;i<V-1;i++){
            
            bool flag = 0;
            // relax them
            for(int j=0;j<E;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(dist[u]==1e8){ // skip edges which are like (1e8 + x < 1e8)
                    continue;
                }
                
                if(dist[u] + wt < dist[v]){
                    flag = 1;
                    dist[v] = dist[u] + wt;
                }
            }
            if(flag==0){ // means iss iteration me koii updation hui hi nahi dist mei
                // means shortest path mil gaya
                return dist;
            }
        }
        
        // one more time relax the edges to detect negative cycle if any
        for(int i=0;i<V-1;i++){
            
            // relax them
            for(int j=0;j<E;j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                
                if(dist[u]==1e8){ // skip edges which are like (1e8 + x < 1e8)
                    continue;
                }
                
                if(dist[u] + wt < dist[v]){ // means update hone wala dist
                    vector<int> ans;
                    ans.push_back(-1);
                    return ans;
                }
            }
        }
        
        // yaha tak aagaye matlab koii negative cycle nahi hai and dist update nahi hua means shortest path mil gaya
        return dist;
    }
};
