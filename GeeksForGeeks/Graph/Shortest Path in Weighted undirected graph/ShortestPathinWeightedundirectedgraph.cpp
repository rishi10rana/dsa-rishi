class Solution {
  public:
  
    // T.C = O(ElogV) + O(V)
    // S.C = O(V + E) + O(V)
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
 
        
        // create adjacecny list
        vector<pair<int, int>> adj[n+1];
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back(make_pair(v,wt));
            adj[v].push_back(make_pair(u,wt));
        }
        
        vector<bool> explored(n+1, 0);
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1, -1);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > p;
        p.push({0,1});
        
        dist[1] = 0;
        
        while(!p.empty()){
            // select the smallest distance vertex and it should be unexplored
            int node = p.top().second;
            p.pop();
            
            if(explored[node]){
                continue; // skip it
            }
            explored[node] = 1;
            
            // look at its all neighbours and update their min dist from src node
            for(int j=0;j<adj[node].size();j++){
                int neigh = adj[node][j].first;
                int wt = adj[node][j].second;
                if(!explored[neigh] &&  dist[node] + wt < dist[neigh]){
                    dist[neigh] = dist[node] + wt;
                    parent[neigh] = node;
                    p.push({dist[neigh], neigh});
                }
            }
        }
        
        int dest = n;
        vector<int>path;
        
        // case 1 : no path exists
        if(parent[dest] == -1){ // means no path exist
            path.push_back(-1);
            return path;
        }
        
        // case 2: path exists
        while(dest!=-1){
            path.push_back(dest);
            dest = parent[dest];
            
        }
        path.push_back(dist[n]);
        
        reverse(path.begin(), path.end());
        return path;
    }
};