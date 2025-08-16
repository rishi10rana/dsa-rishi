class Solution {
public:
    // Recursion Approach -- Not Optimized -- TLE
    /*
    int count(int i, int n){
        // base case
        if(i==n){ /// means pahuch gaye
            return 1;
        }
        if(i>n){ // invalid case
            return 0;
        }

        // recursive call
        return count(i+1, n) + count(i+2, n);
    }
    
    int climbStairs(int n) {
        int i = 0; // start point
        return count(i, n);
    }
    */

    // Approach - DP - top down approach
    // T.C = O(n) , S.C = O(n)
    /*
    int count(int i, int n, vector<int>& dp){
        // base case
        if(i==n){ /// means pahuch gaye
            return 1;
        }
        if(i>n){ // invalid case
            return 0;
        }
        // agar result already calculated hai to wahi return kardo
        if(dp[i]!=-1){
            return dp[i];
        }

        // recursive call
        return dp[i] = count(i+1, n, dp) + count(i+2, n, dp);
    }
 
    int climbStairs(int n) {
        int i = 0; // start point
        
        // to store results for dp
        vector<int> dp(n+2, -1);

        return count(i, n, dp);
    }
    */


    // DP - bottom- Up approach
    // T.C = O(n) , S.C = O(n)
    /*
    int climbStairs(int n) {

        // create dp array to store results
        vector<int> dp(n+2 , -1);

        // base case ki values ko phela hi store karlo
        dp[n+1] = 0;
        dp[n] = 1;

        // ab loop ko use karo to find the remaining value
        for(int i=n-1;i>=0;i--){
            // use karna recursion wali equation
            dp[i] = dp[i+1] + dp[i+2];
        }

        // final count yaha store hoga
        return dp[0];
    }
    */

    // Space Optimization on tabulation
    // T.C = O(n) , S.C = O(1)
    /*
    int climbStairs(int n) {

        // we dont need to have whole dp 
        // kyuki dp[i] ki value uske next doo values se mil jaati hai

        // just use 3 variables
        int curr, next1 = 1, next2 = 0;

        // ab loop ko use karo to find the remaining value
        for(int i=n-1;i>=0;i--){
            curr = next1 + next2;
            next2 = next1;
            next1 = curr;
        }

        // final count yaha store hoga
        return curr;
    }
    */


    // Method-2 -------------------------------

    // recursive approach - TLE
    /*
    int count(int i){
        // base case
        if(i==0){ // pahuch gaye
            return 1;
        }
        if(i<0){ // invalid case
            return 0;
        }

        // recursive call
        return count(i-1) + count(i-2);
    }

    int climbStairs(int n) {
        return count(n);
    }
    */

    // DP - top - down 
    // T.C = O(n) , S.C = O(n)
    /*
    int count(int i,vector<int> &dp){
        // base case aisa set kiya taki -1 ki call jaye hi nahi
        if(i<=1){ // pahuch gaye
            return 1;
        }
        // check karlo ki already hai to nahi
        if(dp[i]!=-1){
            return dp[i];
        }

        // recursive call and store karo result
        return dp[i] = count(i-1, dp) + count(i-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return count(n, dp);
    }
    */

    // DP - bottom - up
    // T.C = O(n) , S.C = O(n)
    /*
    int climbStairs(int n) {
        
        // create dp to store values
        vector<int> dp(n+1, -1);

        // base case phela hi bhardo
        dp[0] = 1;
        dp[1] = 1;

        // ab baki sare remaining dp bhar do
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        // final count return kardo
        return dp[n];
    }
    */

    // DP - bottom - up - further space optimization
    // T.C = O(n) , S.C = O(1)
    int climbStairs(int n) {
        
        // hum just 3 varaibles se bhi dp[i] ki value nikal sak te hue dp array ki zaroorat nahi
        int curr = 1, prev1 = 1, prev2 = 1;

        // ab answer nikal loo to reach ith nth stair
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        // final count return kardo
        return curr;
    }
};