class Solution {
  public:
    // DFS method
    // T.C = O(V + 2E) S.C = O(V)
    /*
    void DFS(int node, vector<vector<int>>& adj, stack<int>& s,vector<bool>& visited){
        visited[node] = 1;
        
        // visit its unvisited neighbours
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]]){
                DFS(adj[node][j], adj, s, visited);
            }
        }
        
        // agar kisi node ke liuya hum pahuch gaya jiska koii neighbour nahi ab jo unvisited
        s.push(node);
    }
    
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<bool> visited(V,0);
        
        vector<vector<int>> adj(V);
        stack<int> s;
        
        int u , v;
        for(int i=0;i<edges.size();i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
        }
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                DFS(0, adj ,s , visited);
            }
        }
        
        // pop the stack to get answer
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
    */
    
    // BFS (Kahns Algorithm) T.C = O(V+E) S.C = O(V)
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<int> indegree(V,0);
        
        vector<vector<int>> adj(V);
        
        int u , v;
        for(int i=0;i<edges.size();i++){
            u = edges[i][0];
            v = edges[i][1];
            adj[u].push_back(v);
        }
        
        // find indegree of all vertices
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        queue<int> q;
        // jinki indegree 0 hai unko queue mei daaldo
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // decrement the indegree of all neighnours of node
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
            }
        }
        return ans;
    }
};