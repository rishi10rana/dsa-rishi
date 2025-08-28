class Solution {
public:
    // Recursive Approach - TLE
    /*
    int solve(vector<int>& nums, int target){
        // base case
        if(target==0){
            return 1; // ek combination milgaya
        }
        if(target<0){
            return 0; // invalid case combination nahi mila
        }

        int result = 0;
        for(int i=0;i<nums.size();i++){
            result = result + solve(nums, target-nums[i]);
        }

        return result;
    }   

    int combinationSum4(vector<int>& nums, int target) {
        
        return solve(nums, target);
    }
    */

    // DP - Memonization
    // T.C = O(target * n)   S.C = O(target)+ O(n)
    /*
    int solve(vector<int>& nums, int target, vector<int>& dp){
        // base case
        if(target==0){
            return 1; // ek combination milgaya
        }
        if(target<0){
            return 0; // invalid case combination nahi mila
        }
        if(dp[target]!=-1){
            return dp[target];
        }

        int result = 0;
        for(int i=0;i<nums.size();i++){
            result = result + solve(nums, target-nums[i], dp);
        }

        return dp[target] = result;
    }   

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return solve(nums, target, dp);
    }
    */

    // DP - Tabulation
    // T.C = O(target * n)  S.C = O(target)
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        
        // sabse phela base cases bhar do
        dp[0] = 1;

        // ab remaining dp bhar do
        for(int i=1;i<=target;i++){

            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0)
                    dp[i] = dp[i] + dp[i-nums[j]]; 
            }
        }

        // no of combinations shich sum up to target
        return dp[target];
    }
};