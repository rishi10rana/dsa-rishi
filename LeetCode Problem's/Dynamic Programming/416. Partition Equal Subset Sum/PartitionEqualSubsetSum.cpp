class Solution {
public:
    // Recursive Approach - TLE
    // T.C = O(2^n)  S.C = O(n)
    /*
    bool f(vector<int> &nums, int index,  int target){
        // base case
        if(target==0){
            return true;
        }
        if(index==0){
            return nums[index] == target;
        }

        // two options
        int nottake = f(nums, index-1,  target);
        int take = false;
        if(target >= nums[index]){
            take = f(nums, index-1, target-nums[index]);
        }

        return take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum%2==1){
            return 0; // means odd sum cat patition
        }

        // even sum means maybe partition possible 
        int target = totalSum/2; // if their exist a subsequence in nums which can give this target
        // means their wil exist other subsequnece which will give remianig totalSum/2

        // so if subsequecne found means can do partition , but if subsequenec not fou nd means cant partition
        return f(nums, n-1, target); 
    }
    */


    // DP Memonization 
    // T.C = O(n * target)  S.C = O(n * target) + O(n)
    /*
    bool f(vector<int> &nums, int index,  int target, vector<vector<int>>  &dp){
        // base case
        if(target==0){
            return true;
        }
        if(index==0){
            return nums[index] == target;
        }
        // check
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        // two options
        int nottake = f(nums, index-1,  target, dp);
        int take = false;
        if(target >= nums[index]){
            take = f(nums, index-1, target-nums[index], dp);
        }

        return dp[index][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();

        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum%2==1){
            return 0; // means odd sum cat patition
        }

        // even sum means maybe partition possible 
        int target = totalSum/2; // if their exist a subsequence in nums which can give this target
        // means their wil exist other subsequnece which will give remianig totalSum/2

        // so if subsequecne found means can do partition , but if subsequenec not fou nd means cant partition

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(nums, n-1, target, dp); 
    }
    */

    // DP Tabulation 
    // T.C = O(n * target)  S.C = O(n * target)
    /*
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum%2==1){
            return 0; // means odd sum cat patition
        }

        // even sum means maybe partition possible 
        int sum = totalSum/2; // if their exist a subsequence in nums which can give this target
        // means their wil exist other subsequnece which will give remianig totalSum/2

        // so if subsequecne found means can do partition , but if subsequenec not fou nd means cant partition
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        // base cases bhar do
        for(int i=0; i<n;i++){
            dp[i][0] = true;
        }

        if(nums[0] <= sum) 
            dp[0][nums[0]] = true;

        // ab remaining dp bhar do
        for(int index=1;index<n;index++){
            for(int target=1;target<=sum;target++){
                // two choice
                int notpick = dp[index-1][target];
                int pick = false;
                if( target>=nums[index]){
                    pick = dp[index-1][target-nums[index]];
                }

                dp[index][target] = pick || notpick;
            }
        }

        return dp[n-1][sum];
    }
    */

    // space optimization 
    // T.C = O(n * target)  S.C = O(2n) - using two arrays
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }

        if(totalSum%2==1){
            return 0; // means odd sum cat patition
        }

        // even sum means maybe partition possible 
        int sum = totalSum/2; // if their exist a subsequence in nums which can give this target
        // means their wil exist other subsequnece which will give remianig totalSum/2

        // so if subsequecne found means can do partition , but if subsequenec not fou nd means cant partition
        
        vector<bool> prev(sum+1, 0);
        vector<bool> curr(sum+1, 0);
        
        // base cases bhar do
        prev[0] = true;
        curr[0] = true;

        if(nums[0] <= sum) 
            prev[nums[0]] = true;

        // ab remaining dp bhar do
        for(int index=1;index<n;index++){
            for(int target=1;target<=sum;target++){
                // two choice
                int notpick = prev[target];
                int pick = false;
                if( target>=nums[index]){
                    pick = prev[target-nums[index]];
                }

                curr[target] = pick || notpick;
            }
            prev = curr;
        }

        return prev[sum];
    }
};