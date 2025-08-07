class Solution {
  public:
  
    // Bfs (kashns algo)
    // T.C = O(V + E) + O(V^2) S.C = O(V) + O(V^2)
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        
        // make the adjacency list and find indegree of all veretices
        vector<int> adj[N];
        vector<int> indegree(N, 0);
        
        for(int i=0;i<P;i++){
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            
            // also update indegree
            indegree[prerequisites[i].first]++;
        }
        
        queue<int> q;
        // jinki indegree 0 hai wo task phela complete honge to unko queue mei daaldo
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
     
        int count = 0; // to count no of elements in answer
     
        // bfs laga do (kahns algorithm)
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            
            // is node ke neighbours ki indegree ko ek se decremnt karo aur agar 0 hogayi to queue mei daaldo to omplete these task next
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // agr count == no of task ke to matlab saree task complete ho jayenga
        
        // par agar count != no of task maltab complete nahi kar payenga
        return count == N;
    }
};