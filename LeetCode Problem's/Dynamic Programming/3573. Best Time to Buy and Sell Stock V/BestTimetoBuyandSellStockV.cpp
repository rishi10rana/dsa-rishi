class Solution {
public:
    // Recursion 
    /*
    long long solve(int i, int k, int CASE, vector<int> &prices){
        // base case
        if(i >= prices.size()){
            if( CASE == 0 ) return 0; // valid
            return INT_MIN; // invalid case
        }

        long notTake = solve(i+1, k, CASE, prices);
        long take = INT_MIN;
        if(k > 0){
            // normal (sell)
            if(CASE == 1){
                take = prices[i] + solve(i+1, k-1, 0, prices);
            }
            else  if(CASE == 2){ // short sell (buy)
                take = -prices[i] + solve(i+1, k-1, 0, prices); 
            }
            else{
                // fresh transaction
                // ya to hela buy karo , yaa to phela sell karo
                take = max(-prices[i] + solve(i+1, k, 1, prices), prices[i] + solve(i+1, k, 2, prices));
            }
        }
        return max(take, notTake);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        
        long long result = solve(0, k, 0, prices);
        return result;
    }
    */

    // DP Memonization
    // T.C= O(n * k)
    // S.C = O(n * k) + O(n * k) extra space due recursion stack
    /*
    long long dp[1001][501][3];
    // i, k, case

    long long solve(int i, int k, int CASE, vector<int> &prices){
        // base case
        if(i >= prices.size()){
            if( CASE == 0 ) return 0; // valid
            return INT_MIN; // invalid case
        }
        if(dp[i][k][CASE] != INT_MIN){
            return dp[i][k][CASE];
        }
        // dont take action
        long long notTake = solve(i+1, k, CASE, prices);

        long long take = INT_MIN;
        // take action
        if(k > 0){
            // normal (sell)
            if(CASE == 1){
                take = prices[i] + solve(i+1, k-1, 0, prices);
            }
            else  if(CASE == 2){ // short sell (buy)
                take = -prices[i] + solve(i+1, k-1, 0, prices); 
            }
            else{
                // fresh transaction
                // ya to hela buy karo , yaa to phela sell karo
                take = max(-prices[i] + solve(i+1, k, 1, prices), prices[i] + solve(i+1, k, 2, prices));
            }
        }
        return dp[i][k][CASE] = max(take, notTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        // dp array initialize (3D array)
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int l=0;l<3;l++){
                    dp[i][j][l] = INT_MIN;
                }
            }
        }
        
        long long result = solve(0, k, 0, prices);
        return result;
    }
    */

    // DP Tabulation
    // T.C = O(n * k)
    // T.C = O(n * k)
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        // dp array
        long long dp[1001][501][3];

        // initialize dp array with INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int c=0;c<3;c++){
                    dp[i][j][c] = INT_MIN;
                }
            }
        }

        // fill the base cases first
        for(int l=0;l<=k;l++){
            dp[n][l][0] = 0; 
            dp[n][l][1] = INT_MIN; 
            dp[n][l][2] = INT_MIN; 
        }
        
        // now fill the main cases
        for(int i=n-1;i>=0;i--){
            for(int K=0;K<=k;K++){
                
                // dont take
                dp[i][K][0] = dp[i+1][K][0];
                // case 0: fresh transaction
                if(K > 0){
                    dp[i][K][0] = max(
                        dp[i][K][0],
                        max(
                            -prices[i] + dp[i+1][K][1], // buy
                            prices[i] + dp[i+1][K][2] // short shell
                        )
                    );
                }


                dp[i][K][1] = dp[i+1][K][1]; // no action
                // case 1: normal transaction sell
                if(K > 0){
                    dp[i][K][1] = max(
                        dp[i][K][1],
                        prices[i] + dp[i+1][K-1][0]
                    );
                }
                
                dp[i][K][2] = dp[i+1][K][2]; // no action
                // case 2: short sell (buy)
                if(K > 0){
                    dp[i][K][2] = max(
                        dp[i][K][2],
                        -prices[i] + dp[i+1][K-1][0]
                    );
                }
            }
        }

        // final answer
        // jab starting stock mei hai aur k transactions bacchi hai aur intial case = 0 hai
        return dp[0][k][0]; 
    }
};