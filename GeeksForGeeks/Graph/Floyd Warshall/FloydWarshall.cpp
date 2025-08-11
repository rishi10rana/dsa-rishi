// User function template for C++

class Solution {
  public:
  
    // Floyd Warshall Algorithm
    // T.C = O(V^3)
    // S.C = O(1) no extra space used
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        
        int n = dist.size();
        
        // first we will select the intermediate node one by one
        for(int k=0;k<n;k++){
            
            // now iterate through each cell of matrix
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]==1e8 || dist[k][j]==1e8){
                        continue; // ignore the case like (1e8 + x)
                    }
                    
                    // update the dist
                    // going from node i --> to j using intermediate node k
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
};