class Solution {
public:
    // Recursive Approach
    // T.C = expoenential O(2^m*n)
    /*
    int f(int i, int j, vector<vector<int>> &grid){
        // base case
        if(i==0 && j==0){ // reached the destn
            return grid[0][0];
        }
        if(i<0 || j<0){ // invalid path dont consider it
            return 1e9; // here INT_MAX pass nahi kiya kyuki wo kisi path mei add hokar int overflow de sakta
        }

        // two moves
        int left = grid[i][j] + f(i,j-1,grid);
        int up = grid[i][j] + f(i-1,j,grid);

        return min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return f(m-1, n-1, grid);    
    }
    */

    // DP Memonization
    // T.C = O(m * n)     S.C = O(m * n) + O((m-1) + (n-1)) 
    /*
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        // base case
        if(i==0 && j==0){ // reached the destn
            return grid[0][0];
        }
        if(i<0 || j<0){ // invalid path dont consider it
            return 1e9; // here INT_MAX pass nahi kiya kyuki wo kisi path mei add hokar int overflow de sakta
        }
        // check
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // two moves
        int left = grid[i][j] + f(i,j-1,grid,dp);
        int up = grid[i][j] + f(i-1,j,grid,dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n, -1));
        return f(m-1, n-1, grid,dp);    
    }
    */

    // DP Tabulation
    // T.C = O(m * n)     S.C = O(m * n)
    /*
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n, 0));

        // sabse phela base case bhar do
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[i][j];
                }
                else{
                    // two moves
                    int left = 0;
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    else left = 1e9;

                    int up = 0;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    else up = 1e9;

                    dp[i][j] = min(left, up);
                }
            }
        }

        // final naswer min path sum to reach (m-1,n-1)
        return dp[m-1][n-1];
    }
    */

    // DP space optimization
    // T.C = O(m * n)     S.C = O(m)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n,0);

        // sabse phela base case bhar do
        for(int i=0;i<m;i++){

            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j] = grid[i][j];
                }
                else{
                    // two moves
                    int left = 0;
                    if(j>0) left = grid[i][j] + curr[j-1];
                    else left = 1e9;

                    int up = 0;
                    if(i>0) up = grid[i][j] + prev[j];
                    else up = 1e9;

                    curr[j] = min(left, up);
                }
            }
            prev = curr;
        }

        // final naswer min path sum to reach (m-1,n-1)
        return prev[n-1];
    }
};