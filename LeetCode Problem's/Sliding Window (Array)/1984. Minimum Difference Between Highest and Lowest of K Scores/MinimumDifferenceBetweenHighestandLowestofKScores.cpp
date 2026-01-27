class Solution {
public:
    // my code: fixed sliding window and sorting
    // T.C = O(nlogn + n)
    // S.C = O(1)
    /*
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        int minDiff = INT_MAX;
        int i = 0;
        int j = i + (k-1);
        // pick each time fixed k size contiguous window and check diff
        while(i < n && j < n){
            if(j -i +1 == k){
                int d = nums[i] - nums[j];
                minDiff = min(minDiff, d);
                i++;
            }
            j++;
        }

        return minDiff;
    }
    */

    // simple code
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int minDiff = INT_MAX;
        int i = 0;
        int j = k -1;
        while(j < n){
            int minEl = nums[i];
            int maxEl = nums[j];
            minDiff = min(minDiff, maxEl-minEl);
            i++;
            j++;
        }
        return minDiff;
    }
};