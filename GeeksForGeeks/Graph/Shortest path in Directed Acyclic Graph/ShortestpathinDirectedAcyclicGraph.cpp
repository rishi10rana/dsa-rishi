// User function Template for C++
class Solution {
  public:
  
    // will give you topological sort in stack
    void DFS(int node, vector<pair<int, int>> adj[], stack<int>& s, vector<bool>& visited){
        visited[node] = 1;
        
        // look at its neighbours
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j].first]){
                DFS(adj[node][j].first, adj, s, visited);
            }
        }
        
        // after coming back and no neighbors present now for node
        s.push(node);
    }
    
    
    // T.C = O(V + E) + O(V + E) + O(V + E) = O(V+E)
    // S.C = O(V + E) + + O(V) due recursion topologial  + O(3V)
    
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        
        // create adjacency list
        vector<pair<int,int>> adj[V];
        for(int i=0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back(make_pair(v, wt));
        }
        
        // find topological sort - using DFS
        stack<int> s;
        vector<bool> visited(V, 0);
        DFS(0, adj, s, visited);
        
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        // empty the stack
        while(!s.empty()){
            int node = s.top();
            s.pop();
            
            // look at its neigbours
            for(int j=0;j<adj[node].size();j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                
                // update its neighbours shortest distance from src
                dist[neigh] = min(dist[neigh], wt + dist[node]);
            }
        }
        
        // now their may be some vertices that were not be able to visted for them the 
        // distance remained INT_MAX so we need to make it -1
        for(int i=0;i<V;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};
