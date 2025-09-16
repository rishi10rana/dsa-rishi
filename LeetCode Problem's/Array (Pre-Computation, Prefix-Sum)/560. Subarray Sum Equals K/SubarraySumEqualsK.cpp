class Solution {
public:
    // brute force approach
    // T.C = O(n^2)      S.C = O(1)
    /*
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int countOfSubArray = 0;

        // generate all the subarrays
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                if(sum==k){
                    countOfSubArray++;
                }
            }
        }

        return countOfSubArray;
    }
    */

    // prefix sum concept
    // T.C = O(n) + O(1)      S.C = O(n)
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> map;
        map[0] = 1;
        int prefixSum = 0, cnt = 0;
        for(int i=0;i<n;i++){
            prefixSum = prefixSum + nums[i];
            int remove = prefixSum - k;
            cnt = cnt + map[remove];
            map[prefixSum]++;
        }

        return cnt; // no of subarrays with sum k
    }
};