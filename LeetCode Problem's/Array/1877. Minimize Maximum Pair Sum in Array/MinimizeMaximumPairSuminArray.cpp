class Solution {
public:
    // T.C = O(nlogn)
    // S.C = O(1)
    // sort and two pointer
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int r = n-1;
        int maxPairSum = INT_MIN;
        
        //(bada, bada) = (bhut bada pair sum dega) ye mat karo
        while(l < r){
            // chota aur bada element pair karo (at a time)
            int sum = nums[l] + nums[r];
            maxPairSum = max(maxPairSum, sum);
            l++;
            r--;
        }

        return maxPairSum;
    }
};