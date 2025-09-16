class Solution {
public:
    // Approach 1 - Brute Force T.C = O(n^2) , S.C = O(1) 
    /*
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        // to store running sum
        vector<int> runningSum(n, 0);

        for(int i=0;i<n;i++){
            // for each index indiividual find running sum
            int sum = 0;
            for(int j=0;j<=i;j++){ // ruuningSum[i] = sum(num[0] + ...num[i])
                sum = sum + nums[j];
            }
            runningSum[i] = sum;
        }
        return runningSum;
    }
    */

    // Approach 2 - Array Pre - Computation - Prefix Sum Nethod
    // T.C = O(n) , S.C = O(1) 
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        // store runningsum (can be called prefix sum)
        vector<int> runningSum(n, 0);
        runningSum[0] = nums[0]; // copy first element

        for(int i=1;i<n;i++){ 
            // calculates prefix sum for ith index
            runningSum[i] = nums[i] + runningSum[i-1];
        }
        return runningSum;
    }
};