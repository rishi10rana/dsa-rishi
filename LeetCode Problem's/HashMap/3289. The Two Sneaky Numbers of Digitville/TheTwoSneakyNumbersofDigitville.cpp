class Solution {
public:
    // T.C = O(n)
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        vector<int> freq(100, 0);
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            freq[value]++;

            // always check kahi ye two bar occur to nahi kar raha
            if(freq[value] == 2){
                // add that digit it in the result
                result.push_back(value);
            }
        }

        return result;
    }
};