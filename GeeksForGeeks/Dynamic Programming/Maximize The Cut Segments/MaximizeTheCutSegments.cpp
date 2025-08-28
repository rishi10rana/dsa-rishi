class Solution {
  public:
  
    // Recursive Approach - TLE
    /*
    int solve(int n, int x,  int y, int z){
        // base case
        if(n==0){ // means 0 length ko todh ne me max kitma segment lagte
            return 0;
        }
        if(n<0){ // invald case means is choice ke through hum segmenet nahi tod sakte
            return INT_MIN;
        }
        
        // 3 ways mei hum segment tod sakte
        int a = 1 + solve(n-x, x, y, z);
        int b = 1 + solve(n-y, x, y, z);
        int c = 1 + solve(n-z, x, y, z);
        
        int ans = max(a,max(b,c));
        return ans;
    }
    
    
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        int ans = solve(n, x, y, z);
        if(ans<0){ // segements not possible
            return 0;
        }
        return ans;
    }
    */
    
    // DP Memonization
    // T.C = O(n)  S.C = O(n) + O(n)
    /*
    int solve(int n, int x,  int y, int z, vector<int>& dp){
        // base case
        if(n==0){ // means 0 length ko todh ne me max kitma segment lagte
            return 0;
        }
        if(n<0){ // invald case means is choice ke through hum segmenet nahi tod sakte
            return INT_MIN;
        }
        // check
        if(dp[n]!=-1){
            return dp[n];
        }
        
        // 3 ways mei hum segment tod sakte
        int a = 1 + solve(n-x, x, y, z, dp);
        int b = 1 + solve(n-y, x, y, z, dp);
        int c = 1 + solve(n-z, x, y, z, dp);
        
        return dp[n] = max(a,max(b,c));
    }
    
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n+1,-1); 
        
        int ans = solve(n, x, y, z, dp);
        if(ans<0){ // segements not possible
            return 0;
        }
        return ans;
    }
    */
    
    
    // DP Tabulation
    // T.C = O(n)   S.C = O(n)
    int maximizeTheCuts(int n, int x, int y, int z) {
        // Your code here
        vector<int> dp(n+1,-1); 
        
        // sabse phela base case bhar do
        dp[0] = 0;
        
        // ab remaining dp bhar do
        for(int i=1;i<=n;i++){
            // 3 choice hai unhe le kar  ya nah lekar jo max value aaye hume wo ans mei store karni 
            
            if(i-x>=0 && dp[i-x]!=-1)
                dp[i] = max(dp[i], 1 + dp[i-x]);
            
            if(i-y>=0 && dp[i-y]!=-1)
                dp[i] = max(dp[i], 1 + dp[i-y]);
            
            if(i-z>=0 && dp[i-z]!=-1)
                dp[i] = max(dp[i], 1 + dp[i-z]);
        }
        
        if(dp[n]<0){ // segements not possible
            return 0;
        }
        return dp[n];
    }
};