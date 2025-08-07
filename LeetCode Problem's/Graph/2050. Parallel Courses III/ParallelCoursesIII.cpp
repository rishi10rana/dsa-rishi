class Solution {
public:
    // Kahns algorithm
    // T.C = O(V+E) , S.C = O(v)
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        // create the adj List
        vector<int> adj[n];
        for(int i=0;i<relations.size();i++){
            // convert them in zero-based indxing to make it easier to solve
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        // store the indegree
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }

        // jinki indegree 0 hai nhe queue mei daal do
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        // this vector stores the max time required to complete previous course
        vector<int> courseTime(n, 0);

        // kahns algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // iska neighbours ke indegree ko decrement kardo
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }

                // for the neighbours node make their courseTime
                // max time to complete previous course + current course time
                courseTime[adj[node][j]] = max(courseTime[adj[node][j]], courseTime[node] + time[node]);     
            }
        }

        // now add the time to complete each course in the courseTime vector as it stored time to comple previous courses
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, courseTime[i] + time[i]);
        }

        // this will be the minimum time to complete all course
        return ans;
    }
};