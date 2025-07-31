class Solution {
  public:
    // DFS approach
    /*
    bool detectCycle(int node,int parent, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = 1;
        
        // uske neighbours ko explore karo
        for(int j = 0;j<adj[node].size();j++){
            // skip parent node
            if(adj[node][j]==parent){
                continue;
            }
            // yaa cycle exist karti - means yaha hum 2 baar visit kar rahe aur ye parent bhi nahi hai
            if(visited[adj[node][j]]){
                return 1;
            }
            // mean yaha tak aagaye to wo neighbour abhi tak visited nahi hai
            if(detectCycle(adj[node][j], node , adj, visited)){
                return 1;
            }
        }
        
        // kisi node ke koii bhi neighbour visit nahi karsakte aur na cycle mili
        return 0;
    }
  
  // T.C = O(V + E) , S.C = O(V)
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        
        vector<bool> visited(V,0);
        vector<vector<int>> adj(V);
        
        int u,v;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            // insert in adj List
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // return detectCycle(0, -1, adj, visited);
        
        
        // for disconnected graphs
        for(int i=0;i<V;i++){
            if(!visited[i] && detectCycle(i,-1,adj,visited)){
                return 1;
            }
        }
        return 0;
    }
    */
    
    // BFS
    bool BFS(int start, vector<vector<int>> adj, vector<bool>& visited){
        //(node, parent)
        queue<pair<int,int>> q;
        q.push(make_pair(start,-1)); 
        visited[start] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int j=0;j<adj[node].size();j++){
                // skip kardo parent ko
                if(adj[node][j]==parent){
                    continue;
                }
                if(visited[adj[node][j]]){
                    return 1; // cycle exist
                }
                // means neighbour not visited till now
                q.push(make_pair(adj[node][j],node));
                visited[adj[node][j]]=1;
            }
        }
        // agar cycle nahi mila
        return 0;
    }
    
    
    // T.C = O(V + E) , S.C = O(V)
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // Code here
        
        vector<bool> visited(V,0);
        vector<vector<int>> adj(V);
        
        int u,v;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            // insert in adj List
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
      
        // for disconnected graph
        for(int i=0;i<V;i++){
            if(!visited[i] && BFS(i, adj, visited)){
                return 1;
            }
        }
        return 0; // cycle nahi mili
    }
};