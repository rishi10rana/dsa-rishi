class Solution {
public:
    // Using simple recursion
    int fib(int n) {
        // base case
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }

        // recursive call , relation
        int ans = fib(n-1) + fib(n-2);
        return ans;
    }


    // --------------------------------
    // Using  Dynamic Programming (memonization , top-down approach)
    // T.C = O(n) , S.C = O(n)
    /*
    int fibo(int n, vector<int>& dp){
        // base case
        if(n<=1){
            return n;
        }
        // if value already calculated hai to wahi return kardo
        if(dp[n]!=-1){
            return dp[n];
        }
        // vlaue agar calculated nahi hai already to ussei calculate karo aur dp mei store karke rakhlo
        return dp[n] = fibo(n-1, dp) + fibo(n-2, dp); 
    }

    int fib(int n) {
        // To store result for dp;
        vector<int> dp(n+1, -1);
        return fibo(n, dp);
    }
    */


    // -------------------------------------
    // using DP - tabulation (bottom - up)
    // T.C = O(n) , S.C = O(n)
    int fib(int n) {
        // edge case - agar kisi ko oth or 1th chahiye
        if(n<=1){
            return n;
        }

        // To store result for dp;
        vector<int> dp(n+1, -1);
        
        // phela bases khardo bhardo
        dp[0] = 0;
        dp[1] = 1;

        // rest pf the values of dp ko bhardo
        for(int i=2;i<=n;i++){
            // use recursive relation
            dp[i] = dp[i-1] + dp[i-2];
        }

        // finally nth fibonnaci chahiye wahi return akrdo
        return dp[n];
    }


    // --------------------------------------------------------
    // using further space optimization on tabulation approach
    // T.C = O(n) , S.C = O(1)
    int fib(int n) {
        // edge case - agar kisi ko 0th or 1th chahiye
        if(n<=1){
            return n;
        }

        // we will just use 3 variables to find nth fibonnaci
        int curr, prev1 = 1, prev2 = 0;
        for(int i=2;i<=n;i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr; 
        }

        // finally nth fibonnaci chahiye wahi return kardo
        return curr;
    }

};