class Solution {
public:
    // DP Recursion + Memonization
    // T.C = O(n * 12 * (12 * 3)) = O(n)
    // S.C = O(n * 12) = O(n)
    int M = 1e9 + 7;
    // 12 ways to color 1st row
    string states[12] = {"RYR", "RYG", "RGR", "RGY", "YRY", "YRG", "YGY", "YGR", "GRG", "GRY", "GYG", "GYR"};

    // dp vector (2 state)
    vector<vector<int>> dp;
    int solve(int n, int prev){
        // base case
        if(n == 0){ // means we nicely coloured all row of grid so this 
            // is one of the valid way to paint the grid
            return 1;
        }
        // check state answer already calculated or not
        if(dp[n][prev] != -1)
            return dp[n][prev];

        int result = 0;
        string last = states[prev]; // pattern used to color prev row
        for(int i=0;i<12;i++){ // pick pattern to color current row
            if(i == prev) continue; // skip: same pattern cant be sued to color two adjacent rows

            string current = states[i];
            bool conflict = false;
            for(int j=0;j<3;j++){
                if(last[j] == current[j]){
                    // means yaha conflict ho raha ye color pattern use nahi kar sakte
                    conflict = true;
                    break;
                }
            }
            if(!conflict){ // if conflict b/w last row and curr row color pattern means we can take
                // this color pattern for this curr row
                result = (result + solve(n-1, i)) % M;
            }
        }
        return dp[n][prev] = result; 
    }

    int numOfWays(int n) {
        int result = 0; // total ways to color the n * 3 grid
        dp.resize(n, vector<int>(12, -1)); // resize dp vector

        for(int i=0;i<12;i++){ // pick the way to colour 1st row and call the solve fucntion to colour 
            // remaining n-1 rows
            result = (result + solve(n-1, i)) % M;
        }

        return result;
    }
};