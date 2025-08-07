class Solution {
  public:
  
     // Bfs (kashns algo)
    // T.C = O(V + E) + O(V^2) S.C = O(V) + O(V^2)
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        
        // make the adjacency list and find indegree of all veretices
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
            // also update indegree
            indegree[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        // jinki indegree 0 hai wo task phela complete honge to unko queue mei daaldo
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
     
        vector<int> ans; // to store order of doing task
        
        // bfs laga do (kahns algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // is node ke neighbours ki indegree ko ek se decremnt karo aur agar 0 hogayi to queue mei daaldo to omplete these task next
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // agr count == no of task ke to matlab saree task complete ho jayenga
        if(ans.size()==n){
            return ans;
        }
        // par agar count != no of task maltab complete nahi kar payenga
        vector<int> temp;
        return temp;
    }
};