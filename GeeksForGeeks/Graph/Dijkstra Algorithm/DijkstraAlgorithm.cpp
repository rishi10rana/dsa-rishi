// User Function Template
class Solution {
  public:
    
    // Method 1 - will give TLE
    // T.C = O(V + E) + O(V) + O(V*(V-1)) = O(V^2)
    // S.C = O(V + E) + O(V) = O(V)
    /*
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // create adj list
        vector<pair<int, int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        vector<bool> explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        for(int i=0;i<V;i++){
            
            // select the minimum and unexplored vertex
            int minDist = INT_MAX;
            int minNode = -1;
            for(int j=0;j<V;j++){
                if(!explored[j] && dist[j] < minDist){
                    minDist = dist[j];
                    minNode = j;
                }
            }
            // once selected a vertex mark it explored
            explored[minNode] = 1;
            
            // look at its neighbours
            for(int j=0;j<adj[minNode].size();j++){
                
                int neigh = adj[minNode][j].first;
                int wt = adj[minNode][j].second;
                if(!explored[neigh] && dist[minNode] + wt <dist[neigh]){
                    // dist[neigh] = min(dist[neigh], dist[minNode] + wt);
                    dist[neigh] = dist[minNode] + wt;
                }
            }
        }
        
        return dist;
    }
    */
    
    
    // Method 2 - using priority queue
    // T.C = O(V+E) + ElogV + ELogV = O(ElogV) 
    // S.C = O(V+E) + O(2V) + O(E) = O(V + E)
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // create adj list
        vector<pair<int, int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        vector<bool> explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> p;
        p.push({0, src}); // (dist, node)
        
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            
            if(explored[node]){
                continue; // skip it
            }
            
            explored[node] = 1;
            // look at its neighbours
            for(int j=0;j<adj[node].size();j++){
                
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                if(!explored[neigh] && dist[node] + wt <dist[neigh]){
                    dist[neigh] = dist[node] + wt;
                    p.push({dist[neigh], neigh});
                }
            }
        }
        
        return dist;
    }
    /*
    */
    
    // Method 3 - using ordered set
    /*
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // create adj list
        vector<pair<int, int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }
        
        vector<bool> explored(V, 0);
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        
        set<pair<int, int>> s;
        s.insert({0, src}); // (dist, node)
        
        while(!s.empty()){
            set<pair<int, int>>::iterator itr = s.begin(); // points to first element in set (smallest element)
            int node = (*itr).second;
            s.erase(itr);
            
            if(explored[node]){
                continue; // skip it
            }
            
            explored[node] = 1;
            // look at its neighbours
            for(int j=0;j<adj[node].size();j++){
                
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                if(!explored[neigh] && dist[node] + wt <dist[neigh]){
                    dist[neigh] = dist[node] + wt;
                    s.insert({dist[neigh], neigh});
                }
            }
        }
        
        return dist;
    }
    */
};