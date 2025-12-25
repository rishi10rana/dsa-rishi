class Solution {
public:
    // Recusion
    // T.C = O(2^n)
    // S.C = O(n)
    /*
    int solve(int i, int p, vector<int>& nums){
        // base case
        if(i >= nums.size()){
            // means outof bound ab koii LIS nahi milsakta
            return 0;
        }

        // two options hai kisi element ke pass
        // take or skip
        // take
        int take = 0;
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(i+1, i, nums);
        }

        // skip
        int skip = solve(i+1, p, nums);

        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        // i, p(prev index taken), nums
        return solve(0, -1, nums);    
    }
    */

    /*
    // DP Memonization
    // T.C = O(n+1 * n+1) = O(n^2)
    // S.C = O(n+1 * n+1) = O(n^2) + recursion stack
    // dp array 2states - i, p
    int dp[2501][2501];
    int solve(int i, int p, vector<int>& nums){
        // base case
        if(i >= nums.size()){
            // means outof bound ab koii LIS nahi milsakta
            return 0;
        }
        // check kahi already store to nahi answer
        if(p != -1 && dp[i][p] != -1){
            return dp[i][p];
        }

        // two options hai kisi element ke pass
        // take or skip
        // take
        int take = 0;
        if(p == -1 || nums[p] < nums[i]){
            take = 1 + solve(i+1, i, nums);
        }

        // skip
        int skip = solve(i+1, p, nums);

        // store karlena result also
        if(p != -1){
            dp[i][p] = max(take, skip);
        }
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        // initialize dp array with -1
        memset(dp, -1, sizeof(dp));

        // i, p(prev index taken), nums
        return solve(0, -1, nums);    
    }
    */

    // DP Tabulation
    // T.C = O(n(n + 1))/2 = O(n^2)
    // S.C = O(n)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // 1d dp array
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[j] < nums[i]){ // means this new element can create a new LIS ending at i
                    // by adding the element to the LIS ending at j
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // scan dp for max value
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(dp[i] > ans){
                ans = dp[i];
            }
        }
        return ans;
    }
};