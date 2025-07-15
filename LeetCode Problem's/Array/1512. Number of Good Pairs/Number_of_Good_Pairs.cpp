class Solution {
public:
    // Apprroach 1 - Brute force T.C = O(n^2)
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        // oonsider each possible pair and check whether te pair are good or not
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(i < j && nums[i]==nums[j]){
                    count++;
                }
            }
        }

        return count;
    }
};