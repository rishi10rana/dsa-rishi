class Solution {
private:
    void helper(vector<int> nums,vector<int> output,int index,vector<vector<int>> &ans){
        // Base Case
        if(index>=nums.size()){
            ans.push_back(output); // add the final output to ans
            return; // stop at this point
        }

        // Exclude an element
        helper(nums,output,index+1,ans); // just increment index by 1 and call function for next element

        // Include an element - add the element first in output then call function for next element
        int element = nums[index];
        output.push_back(element);
        helper(nums,output,index+1,ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; // To store the acutal collection of all subsets
        vector<int> output; // to store individual subsets
        int index = 0; // pointer to maintain cuurent element to deal with 
        helper(nums,output,index,ans); // call the actual function to solve
        return ans; // give the ans
    }   
};