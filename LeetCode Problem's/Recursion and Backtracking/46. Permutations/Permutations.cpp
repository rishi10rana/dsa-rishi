class Solution {
private:
    void helper(vector<int> &nums,int index,vector<vector<int>> &ans){
        // Base Case
        if(index>=nums.size()){
            ans.push_back(nums); // pass the changed nums to the "ans"
            return; // stop as index goes out
        }

        // For a particular index swap it with all other values one by one present in its forward
        // This is done to place all elements one by one in a particular position
        for(int j=index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            // Now call the function recursively for next index (to determine next position)
            helper(nums,index+1,ans);
            // when backtrack undo the changes that you made by swapping
            swap(nums[index],nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // To store all possible permutation combination
        int index = 0; // to keep track of current element
        helper(nums,index,ans); // function form all permuutations
        return ans;
    }
};