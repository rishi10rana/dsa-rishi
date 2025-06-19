class Solution {
public:
    // Optimal Approach - Kadane's Algorithm T.C = O(n) , S.C = O(1)
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        int maxiSum = INT_MIN;
    
        // no need to handle for empty array as array will atleast contain 1 element

        // traverse each element
        for(int i=0;i<n;i++){
            sum = sum + nums[i]; // find sum using each eleement

            if(sum > maxiSum){ // if any greater sum found , then update ans
                maxiSum = sum;
            }
            // But check for any element if found that sum coming less than 0 then no
            // need to consider that element part of subarray (So again start)
            if(sum < 0){
                sum = 0;
            }
        }

        return maxiSum;
    }

    // Approach - Brute Force T.C = O(n^2) S.C = O(1) - TLE
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();    
        int maxiSum = INT_MIN; 

        // trys all possible subarray possible and fin sum for it and will store the 
        // maximum sum it coint find for a subarray 
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                maxiSum = max(maxiSum,sum);
            }
        }
        return maxiSum;
    }
};