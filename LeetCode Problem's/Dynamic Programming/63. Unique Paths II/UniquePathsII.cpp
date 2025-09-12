class Solution {
public:
    // Recursive Approach
    // T.C = O(2^n*m) - TLE
    /*
    int valid(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x >= 0 && y >= 0 && obstacleGrid[x][y]==0){
            return true; // can move here
        }
        return false;
    }

    int f(int i, int j, vector<vector<int>> &obstacleGrid){
        // base case
        if(i==0 && j==0){ // ek path mil gaya 
            return 1;
        }

        // ab hmaraa pas two options hote to move (left, up)
        int left = 0;
        if(valid(i,j-1,obstacleGrid)){
            left = f(i, j-1, obstacleGrid);
        }

        int up = 0;
        if(valid(i-1,j,obstacleGrid)){
            up = f(i-1,j,obstacleGrid);
        }

        return left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }

        return f(m-1, n-1, obstacleGrid);
    }
    */

    // DP - Memonization
    // T.C = O(m * n)
    // S.C = O(m * n) + O((m-1) + (n-1))
    /*
    int valid(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x >= 0 && y >= 0 && obstacleGrid[x][y]==0){
            return true; // can move here
        }
        return false;
    }

    int f(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
        // base case
        if(i==0 && j==0){ // ek path mil gaya 
            return 1;
        }

        // check kahi ye subproblem kahi already calculated to nahi
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // ab hmaraa pas two options hote to move (left, up)
        int left = 0;
        if(valid(i,j-1,obstacleGrid)){
            left = f(i, j-1, obstacleGrid, dp);
        }

        int up = 0;
        if(valid(i-1,j,obstacleGrid)){
            up = f(i-1,j,obstacleGrid, dp);
        }

        return dp[i][j] = left + up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }

        return f(m-1, n-1, obstacleGrid, dp);
    }
    */

    // DP - Tabulation
    // T.C = O(m * n)
    // S.C = O(m * n)
    /*
    bool valid(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x >=0 && y >=0 && obstacleGrid[x][y]==0){
            return true; // means yaha par jaa sakte
        }
        return false;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }

        vector<vector<int>> dp(m, vector<int>(n, -1));

        // base case or remaing dp bhar do
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    // two options hai humpe to move
                    int left = 0;
                    if(valid(i, j-1, obstacleGrid)){
                        left = dp[i][j-1];
                    }

                    int up = 0;
                    if(valid(i-1, j, obstacleGrid)){
                        up = dp[i-1][j];
                    }

                    dp[i][j] = left + up;
                }
            }
        }

        // final answer to reach (m-1, n-1) how many unique ways
        return dp[m-1][n-1];
    }
    */

    // DP - space optimization
    // T.C = O(m * n)
    // S.C = O(n)
    bool valid(int x, int y, vector<vector<int>> &obstacleGrid){
        if(x >=0 && y >=0 && obstacleGrid[x][y]==0){
            return true; // means yaha par jaa sakte
        }
        return false;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1){
            return 0;
        }

        vector<int> prev(n, 0);

        // base case or remaing dp bhar do
        for(int i=0;i<m;i++){
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    curr[j] = 1;
                }
                else{
                    // two options hai humpe to move
                    int left = 0;
                    if(valid(i, j-1, obstacleGrid)){
                        left = curr[j-1];
                    }

                    int up = 0;
                    if(valid(i-1, j, obstacleGrid)){
                        up = prev[j];
                    }

                    curr[j] = left + up;
                }
            }
            prev = curr;
        }

        // final answer to reach (m-1, n-1) how many unique ways
        return prev[n-1];
    }
};