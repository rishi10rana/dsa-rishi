class Solution {
public:
    // Recursion Approach - TLE - T.C = 2^(m * n)
    /*
    int solve(int i, int j){
        // base case
        if(i == 0 && j == 0){
            return 1; // reached the destination so count this path
        }
        if(i < 0 || j < 0){
            return 0; // invalid (out of boundary) 
        }

        // we have two moves possible
        int up = solve(i-1, j);
        int left = solve(i,j-1);
        return up + left;
    }

    int uniquePaths(int m, int n) {
        
        return solve(m-1, n-1);
    }
    */

    // DP Memonization 
    // T.C = O(m * n)    S.C = O(m * n) + O((m-1) + (n-1))
    /*
    int solve(int i, int j, vector<vector<int>> &dp){
        // base case
        if(i == 0 && j == 0){
            return 1; // reached the destination so count this path
        }
        if(i < 0 || j < 0){
            return 0; // invalid (out of boundary) 
        }
        // check karlo kahi tumne ye sub problem already solve to nahi kari
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        // we have two moves possible
        int up = solve(i-1, j, dp);
        int left = solve(i,j-1, dp);
        return dp[i][j] = up + left;
    }

    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(m-1, n-1, dp);
    }
    */

    // DP Tabulation
    // T.C = O(m * n)  S.C = O(m*n)
    /*
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // sabse phela base case bhar do and then remaining dp ko bhar do
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // base case
                if(i==0 && j==0){
                    dp[i][j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    if(i-1>=0) 
                        up = dp[i-1][j]; // tum yaha yaa to apne upar wale se aaye hoge
                    if(j-1>=0) 
                        left = dp[i][j-1]; // yaa tum apne left wale se aaye hoge
                    dp[i][j] = up + left;
                }   
            }
        }

        // final answer dedo ki (m-1,n-1) tak pahuchne ke kitna tarika
        return dp[m-1][n-1];
    }
    */

    // space optimization
    // T.C = O(m * n)  S.C = O(m)
    int uniquePaths(int m, int n) {
        
        vector<int> prev(n,0);

        // sabse phela base case bhar do and then remaining dp ko bhar do
        for(int i=0;i<m;i++){
            vector<int> curr(n, 0);
            for(int j=0;j<n;j++){
                // base case
                if(i==0 && j==0){
                    curr[j] = 1;
                }
                else{
                    int up = 0;
                    int left = 0;
                    up = prev[j]; // tum yaha yaa to apne upar wale se aaye hoge
                    if(j-1>=0) left = curr[j-1]; // yaa tum apne left wale se aaye hoge
                    curr[j] = up + left;
                }   
            }
            prev = curr;
        }

        // final answer dedo ki (m-1,n-1) tak pahuchne ke kitna tarika
        return prev[n-1];
    }
};