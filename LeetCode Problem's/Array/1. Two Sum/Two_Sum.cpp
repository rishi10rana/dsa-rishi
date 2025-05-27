class Solution {
public:
    // Approach - Two Pointer , T.C = O(n) , S.C = O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        // Two Pointer pointing at start and end of array
        int i = 0;
        int j = nums.size()-1;

        // To store answer index list
        vector<int> ans;
        // Copy of original array as to solve i will sort the original array
        vector<int> copy = nums;
        sort(nums.begin(),nums.end());    
    
        // Store values whose sum give target
        int first = -1;
        int second = -1;
        while(i<j){
            int sum = nums[i] + nums[j];
            if(sum==target){ 
                first = nums[i];
                second = nums[j];
                break;
            }
            else if(sum>target){
                j--; // to reduce sum to match to target
            }
            else if(sum<target){
                i++; // to increase sum to match to target
            }
        }

        // To store index values which are answer
        int firstIndex = -1;
        int secondIndex = -1;
        // To find the original index's using first and second values
        for(int i=0;i<copy.size();i++){
            if(firstIndex == -1 && copy[i]==first){
                firstIndex = i;
            }
            else if(secondIndex == -1 && copy[i]==second){
                secondIndex = i;
            }
        }
        // Add indexs to answer
        ans.push_back(firstIndex);
        ans.push_back(secondIndex);

        return ans;
    }
};