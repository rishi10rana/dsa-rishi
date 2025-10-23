class Solution {
public:
    // prefix sum concept
    // T.C = O(maxEl)     ,    S.C = O(maxEl)
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxEl = *max_element(begin(nums), end(nums));

        vector<int> freq(maxEl+1, 0);
        for(int &x: nums){
            freq[x]++;
        }

        // cummulative freq
        for(int i=1;i<=maxEl;i++){
            freq[i] = freq[i] + freq[i-1];
        }

        int result = 0;
        // chose possible targets one-by-one
        for(int target=0;target<=maxEl;target++){
            if(freq[target]==0){
                continue;
            }

            int l = max(target-k,0);
            int r = min(target+k,maxEl);

            // count of elements from[l,r] in nums that can be changed 
            int totalCount = freq[r] - (l-1 > 0 ? freq[l-1] : 0);

            // count of target (they dont need to be changed) 
            int targetCount = freq[target] - (target-1 > 0 ? freq[target-1] : 0);

            // count of number(operations) that need to be changed/performed
            int needChange = totalCount - targetCount;

            // max freq we can get for target
            int maxFreq = min(numOperations, needChange) + targetCount;

            // update the freq
            result = max(result, maxFreq);
        }

        return result;
    }
};