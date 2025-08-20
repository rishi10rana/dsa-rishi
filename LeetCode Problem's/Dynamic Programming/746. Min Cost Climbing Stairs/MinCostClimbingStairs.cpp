class Solution {
public:
    // Recursive Approach - will give TLE
    /*
    int minCostToReach(int n, vector<int>& cost){
        // base case
        if(n<=1){
            // kyuki 1 or 0 stiar se hum start kar sakte to waha par pahuchne ki cost 0 hoti
            return 0;
        }

        // recursive call
        return min(cost[n-1] + minCostToReach(n-1, cost), cost[n-2] + minCostToReach(n-2, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        
        // store the value of top of the stair
        int n = cost.size();
        return minCostToReach(n, cost);
    }
    */

    // DP - top-to-bottom approach
    // T.C = O(n)  S.C = O(n)
    /*
    int minCostToReach(int n, vector<int>& cost, vector<int> &dp){
        // base case
        if(n<=1){
            // kyuki 1 or 0 stiar se hum start kar sakte to waha par pahuchne ki cost 0 hoti
            return 0;
        }
        // check
        if(dp[n]!=-1){
            return dp[n];
        }

        // recursive call
        return dp[n] = min(cost[n-1] + minCostToReach(n-1, cost, dp), cost[n-2] + minCostToReach(n-2, cost, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {

        // store the value of top of the stair
        int n = cost.size();

        vector<int> dp(n+1, -1);
        return minCostToReach(n, cost, dp);
    }
    */

    // DP - bottom - up approach
    // T.C = O(n) , S.C = O(n)
    /*
    int minCostClimbingStairs(vector<int>& cost) {

        // store the value of top of the stair (mo .of stairs)
        int n = cost.size();

        // indirectly waise ye dp store karta ki ith stair tak pahuchne ki min cost kya hai
        vector<int> dp(n+1, -1);

        // sabse phela base cases bhar do
        dp[0] = 0;
        dp[1] = 0;

        // ab baki remaining DP bhar do
        for(int i=2;i<=n;i++){
            dp[i] = min(cost[i-1] + dp[i-1]  , cost[i-2] + dp[i-2]);
        }

        // answer hoga nth stair tak pahuchne ki min cost
        return dp[n];
    }
    */

    // DP - bottom - up - further space optimization
    // T.C = O(n) , S.C = O(1)
    int minCostClimbingStairs(vector<int>& cost) {

        // store the value of top of the stair (no .of stairs)
        int n = cost.size();

        // just use 3 variables kyuki kis floor mei reach karne ki min cost ek to cost array p e aur piche ke 2 stairs ke min ost pe depend karti
        int curr;
        int prev1 = 0;
        int prev2 = 0;

        // ab nth stair tak pahuchne ke min ocst nikalo
        for(int i=2;i<=n;i++){
            curr = min(cost[i-1] + prev1, cost[i-2] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        // answer hoga nth stair tak pahuchne ki min cost
        return curr;
    }
};