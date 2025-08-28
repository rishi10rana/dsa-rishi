class Solution {
public:
    // Recursive Approach - TLE
    // T.C = exponenetial
    /*
    int solve(string &text1, string &text2, int index1, int index2){
        // base case
        if(index1 < 0 || index2 < 0){
            return 0; // range ke abahr chale gaye to lcs mil ga hi nahi waha to 0
        }

        // two case 
        // match - means 1 length ka subsequence mil gaya
        if(text1[index1]==text2[index2]){
            return 1 + solve(text1, text2, index1-1, index2-1);
        }

        // not match
        return 0 + max(solve(text1, text2, index1-1, index2), solve(text1, text2, index1, index2-1) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        return solve(text1, text2, n-1, m-1);
    }
    */

    // DP - Memonization
    // T.C = O(N * M)
    // S.C = O(N * M) + O(N + M)
    /*
    int solve(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp){
        // base case
        if(index1 < 0 || index2 < 0){
            return 0; // range ke abahr chale gaye to lcs mil ga hi nahi waha to 0
        }
        // check
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }


        // two case 
        // match - means 1 length ka subsequence mil gaya
        if(text1[index1]==text2[index2]){
            return dp[index1][index2] = 1 + solve(text1, text2, index1-1, index2-1, dp);
        }

        // not match
        return dp[index1][index2] = 0 + max(solve(text1, text2, index1-1, index2, dp), solve(text1, text2, index1, index2-1, dp) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, n-1, m-1, dp);
    }
    */

    // DP - Memonization - shifting of index
    // T.C = O(N * M)
    // S.C = O(N * M) + O(N + M)
    /*
    int solve(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp){
        // base case
        if(index1 == 0 || index2 == 0){
            return 0; // range ke abahr chale gaye to lcs mil ga hi nahi waha to 0
        }
        // check
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }

        // two case 
        // match - means 1 length ka subsequence mil gaya
        if(text1[index1-1]==text2[index2-1]){
            return dp[index1][index2] = 1 + solve(text1, text2, index1-1, index2-1, dp);
        }

        // not match
        return dp[index1][index2] = 0 + max(solve(text1, text2, index1-1, index2, dp), solve(text1, text2, index1, index2-1, dp) );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
        return solve(text1, text2, n, m, dp);
    }
    */

    // DP - Tabulation
    // T.C = O(n * m)
    // S.C = O(n*m)
    /*
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));
        
        // sabse phela base cases bhar do
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }

        // ab remaing dp bhar do
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                // match
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }

                // not match
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
    */

    // DP - space optimization - using only two rows (arrays)
    // T.C = O(n * m)
    // S.C = O(2m)
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);
        
        // sabse phela base cases bhar do
        for(int j=0;j<=m;j++){
            prev[j] = 0;
        }

        // ab curr nikalo last tak
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                // match
                if(text1[i-1]==text2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }

                // not match
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};