class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // To keep track of in which position you need to place non-zero elements 
        // (i.e they are needed to placed on left as all zeros need to be in right)
        int nonZero = 0;

        // Traverse in array to check each element if non-zero swap it with current "nonZero" position
        // and increment nonZero++
        for(int j=0;j<nums.size();j++){
            if(nums[j]!=0){
                swap(nums[j],nums[nonZero]);
                nonZero++;
            }
        }
    }
};