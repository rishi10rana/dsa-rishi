class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, int node, vector<bool>& visited){
        visited[node] = 1;

        // visit its neigbour
        /*
        for(int &i: adj[node]){
            if(!visited[i]){
                DFS(adj, i, visited);
            }
        }
        */

        for(int j=0;j<isConnected.size();j++){
            if(isConnected[node][j]==1 && !visited[j]){
                DFS(isConnected, j, visited);
            }
        }
    }

    // DFS Method
    // T.C = (V+E)
    // S.C = (V)
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // create an adjaceney list
        // unordered_map<int, vector<int>> adj;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(isConnected[i][j]==1){
        //             adj[i].push_back(j);
        //             adj[j].push_back(i);
        //         }
        //     }
        // }

        vector<bool> visited(n, 0);
        int province = 0;

        // ek ek city ki padkdo aur usmei dfs lagao to mark all the connceted citites from it kyuki wo ek province banayengi aur jab dfs khatamho us city ke liya tab uska province o se incremenet kardo
        for(int i=0;i<n;i++){
            if(!visited[i]){
                // DFS(adj, i, visited);
                DFS(isConnected, i, visited);
                province++;
            }
        }

        return province;
    }
};