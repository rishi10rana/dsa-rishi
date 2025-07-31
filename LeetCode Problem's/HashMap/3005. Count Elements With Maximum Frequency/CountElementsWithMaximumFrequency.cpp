class Solution {
public:
    // hashmap
    // T.C = O(n) , S.C = O(1)
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int ,int> mp;

        int maxFreq = 0;

        // store the count of each element in map and max time an element can exist
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxFreq = max(maxFreq , mp[nums[i]]);
        }

        int freq = 0;
        // count the no which occur "maxFrrq" no of times
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]] == maxFreq){
                freq++;
            }
        }

        return freq;
    }
};