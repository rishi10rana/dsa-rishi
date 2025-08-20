
class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    
    // Recursive Approach
    /*
    int ways(int n){
        // base case
        if(n==0){
            return 1; // yaha se upar pahuch sakte
        }
        if(n<0){
            return 0; // invalid case
        }
        
        return ways(n-1) + ways(n-2) + ways(n-3);
    }
    
    int countWays(int n) {

        // your code here
        return ways(n);    
    }
    */
    
    
    // DP - Top Down Approach
    // T.C = O(n) , S.C = O(n)
    /*
    int ways(int n, vector<int>& dp){
        // base case
        if(n<=1){
            return 1; 
        }
        if(n==2){
            return 2; 
        }
        //check already atored to nahi
        if(dp[n]!=-1){
            return dp[n];
        }
        // store result and recurisve call
        return dp[n] = ways(n-1, dp) + ways(n-2, dp) + ways(n-3, dp);
    }
    */
    
    // DP - Bottom up approach
    // T.C = O(n) , S.C = O(n)
    /*
    int countWays(int n) {
        vector<int> dp(n+1, -1);
        
        // sabse phela base cases bhar do
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        
        // ab baki remaing dp ko bhar do
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        
        // final answer end mei hota
        return dp[n];
    }
    */
    
    
    // DP - futher space optimization
    // T.C = O(n) , S.C = O(1)
    /*
    int countWays(int n) {
        
        if(n<=1){
            return 1;
        }
        if(n==2){
            return 2;
        }
        
        // 4 variables imitilaize karke ans nikal sakte
        int prev3=1, prev2=1, prev1=2, curr;
        
        // ab ans nikal loo 
        for(int i=3;i<=n;i++){
            curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        // final answer 
        return curr;
    }
    */
    
    // Method 2 --------------------------------------
    // niche se upar jayenga 0th stair se nth
    
    // Recursive 
    /*
    int ways(int i,int n){
        // base case
        if(i==n){ // pahauch gaye upar
            return 1;
        }
        if(i>n){
            return 0; // invalid case
        }
        
        // recursion
        return ways(i+1, n) + ways(i+2, n) + ways(i+3, n);
    }
    
    int countWays(int n) {

        // your code here
        int i = 0; // to start from
        return ways(i,n);    
    }
    */
    
    // DP - top - bottom
    // T.C = O(n) , S.C = O(n)
    /*
    int ways(int i,int n,vector<int> &dp){
        // base case
        if(i==n){ // pahauch gaye upar
            return 1;
        }
        if(i>n){
            return 0; // invalid case
        }
        // agar already hai
        if(dp[i]!=-1){
            return dp[i];
        }
        
        // recursion
        return dp[i] = ways(i+1, n, dp) + ways(i+2, n, dp) + ways(i+3, n, dp);
    }
    
    int countWays(int n) {

        vector<int> dp(n, -1);
        // your code here
        int i = 0; // to start from
        return ways(i,n,dp);    
    }
    */
    
    
    // DP - bottom-up
    // T.C = O(n) , S.C = O(n)
    /*
    int countWays(int n) {

        vector<int> dp(n+3, -1);
        
        // sabse phela bases bhar do in dp isliya dp array todha bada liya kyuki yaha bas case bhi tore karenga
        dp[dp.size()-1] = 0;
        dp[dp.size()-2] = 0;
        dp[n] = 1;
        
        // baki remaining dp array bhar do
        for(int i=n-1; i>=0; i--){
            dp[i] = dp[i+1] + dp[i+2] + dp[i+3];
        }
        
        // mena 0th stair se nth stair jane ke liya kitna ways
        return dp[0];
    }
    */
    
    
    // DP - further space optimization
    // T.C = O(n) , S.C = O(1)
    int countWays(int n) {

        // sirf 4 variabese ans nikalenga    
        int curr;
        int next3 = 0;
        int next2 = 0;
        int next1 = 1;
        
        // find answer
        for(int i=n-1; i>=0; i--){
            curr = next1 + next2 + next3;
            next3 = next2;
            next2 = next1;
            next1 = curr;
        }
        
        // mena 0th stair se nth stair jane ke liya kitna ways
        return curr;
    }
};
