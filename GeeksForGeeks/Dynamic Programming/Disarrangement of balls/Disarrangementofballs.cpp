// User function Template for C++

class Solution {
  public:
  
    // Recursive Approach
    /*
    int solve(int n){
        // base case
        if(n==1){ // agar sirf ek element baccha to usse wrong psotiton mei place karne ke 0 tarika honge
            return 0;
        }
        if(n==2){ // agar sirf two elements honge to unnhe disarrange karne ke sirf 1 tarika hoga
            return 1;
        }
        
        // recursive relation
        int ans = (n-1) * (solve(n-2) + solve(n-1));
        return ans;
    }
    
    int countDer(int n) {
        return solve(n);
    }
    */
    
    
    // Dp Memonization
    // T.C = O(n) S.C = O(n) + O(n)
    /*
    int solve(int n, vector<int>& dp){
        // base case
        if(n==1){ // agar sirf ek element baccha to usse wrong psotiton mei place karne ke 0 tarika honge
            return 0;
        }
        if(n==2){ // agar sirf two elements honge to unnhe disarrange karne ke sirf 1 tarika hoga
            return 1;
        }
        // check already value stored to nahi
        if(dp[n]!=-1){
            return dp[n];
        }
        
        // recursive relation
        return dp[n] = (n-1) * (solve(n-2, dp) + solve(n-1, dp));
    }
    
    int countDer(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    */
    
    // Dp Tabulation
    // T.C = O(n) S.C = O(n)
    /*
    int countDer(int n) {
        vector<int> dp(n+1, -1);
        
        // sabse phela base case bhar do
        dp[1] = 0;
        dp[2] = 1;
        
        
        // remianing case bhar do in dp
        for(int i=3;i<=n;i++){
            dp[i] = (i-1) * (dp[i-2] + dp[i-1]);
        }
        
        // final answer no of ways to dearrange n elements
        return dp[n];
    }
    */
    
    // Space optimization
    // T.C = O(n) S.C = O(1)
    int countDer(int n) {
        
        // edge cases
        if(n==0 || n==1){
            return 0;
        }
        
        if(n==2){
            return 1;
        }
        
        int curr = 0;
        int prev1 = 1;
        int prev2 = 0;
        
        
        // find for nth element
        for(int i=3;i<=n;i++){
            curr = (i-1) * (prev2 + prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        
        // final answer no of ways to dearrange n elements
        return curr;
    }
};