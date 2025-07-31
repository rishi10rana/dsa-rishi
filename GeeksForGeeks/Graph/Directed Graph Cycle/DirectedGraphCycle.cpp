class Solution {
  public:
    /*
    // T.C = O(V + E) , S.C = O(V)
    // DFS
    bool DFS(int node , vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& path){
        visited[node] = 1;
        path[node] = 1;
        
        // visit its unvisited neighbours
        for(int j=0;j<adj[node].size();j++){
            // kahi laredy mera part mei hai to means cycle ban rahi
            if(path[adj[node][j]]==1){
                return 1;
            }
            // agar already visited path hai to mat jao cycle nahi miilegi waha
            if(visited[adj[node][j]]){
                continue;
            }
            // last case visited nahi visit karo aur check karlo cycle deta ki nahi
            if(DFS(adj[node][j], adj, visited, path)){
                return 1;
            }
        }
        
        // agar kisi path ke end tak pahuch gaye agae koii noedes nahi to picha return ajao uar path ko unmark karte raho
        path[node] = 0;
        return 0;
    }
  
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> adj(V);
        
        // u--> v
        int u, v;
        for(int i=0;i<edges.size();i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> path(V,0);
        vector<bool> visited(V,0);
        
        // do this to eveb check disconnected graphs
        for(int i=0;i<V;i++){
            if(!visited[i] && DFS(i, adj, visited, path)){
                return 1;
            }
        }
        return 0;
    }
    */
    
    
    
    // BFS Kahns Algorithm
    // T.C = O(V + E) , S.C = O(V)
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<vector<int>> adj(V);
        
        // u--> v
        int u, v;
        for(int i=0;i<edges.size();i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> indegree(V,0);
        
        // indegree nikal rahe 
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        // jinka indegree 0 hai unko queue mei daaldo kyuki ubka koii parent nahhi hai wo sabse phela print honge
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();;
            
            ans.push_back(node);
            
            // is node ke neighbourse k indegree ko 1 se decrement kardo
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // count size of result array
        int count = ans.size();
        
        // in kahn algorithm , directed acyclic graph       count == V
        // but in directed cyclic graph     count != V
        if(count!=V){
            return 1; // yes cyclic
        }
        else{
            return 0;
        }
    }
};