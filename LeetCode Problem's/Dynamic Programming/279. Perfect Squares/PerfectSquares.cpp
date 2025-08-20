class Solution {
public:
    // Recursive Approach
    /*
    int helper(int n){
        // base case
        if(n==0){
            return 0; // 0 lane ke liuya mujhe zero perfect square chahiye hote
        }

        int minCount = INT_MAX;
        // diferent values try karo jin se perfect square ban sakta
        for(int i=1; i*i<=n; i++){
            int result = 1 + helper(n-i*i);
            minCount = min(minCount, result);
        }

        return minCount;
    }

    int numSquares(int n) {
        
        return helper(n);
    }
    */

    
    // DP Approach - memonization
    // T.C = O(n) , S.C= O(n)
    /*
    int dp[100001];
    int helper(int n){
        // base case
        if(n==0){
            return 0; // 0 lane ke liuya mujhe zero perfect square chahiye hote
        }
        // check karlo kahi already present to nahi
        if(dp[n]!=-1){
            return dp[n];
        }

        int minCount = INT_MAX;
        // diferent values try karo jin se perfect square ban sakta
        for(int i=1; i*i<=n; i++){
            int result = 1 + helper(n-i*i);
            minCount = min(minCount, result);
        }

        return dp[n] = minCount;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp)); // ye function help karta hai hume to initialize value in a structure
        return helper(n);
    }
    */

    // DP Approach - tabulation
    // T.C = O(n) , S.C= O(n)
    int numSquares(int n) {
        
        // create dp vector
        // dp[i] store karte i value banae ke liya minimum kitna perfect square chaiye honge
        vector<int> dp(n+1, INT_MAX);

        // base case phela bhar do
        dp[0] = 0;

        // ab baki remaing dp bharni hai
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i ;j++){
                dp[i] = min(dp[i], 1 + dp[i-j*j]);
            }
        }

        // final answer hoga humarraa last mei ki "n" value banane ke liya min kitna perfect square chahiye honge
        return dp[n]; 
    }
};