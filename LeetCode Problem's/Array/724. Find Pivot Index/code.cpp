class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        // To store total sum of all elements in rightSum
        for(int i=0;i<nums.size();i++){
            rightSum = rightSum + nums[i];
        }

        // Traverse each element in array and check for pivot condition leftSum == rightsum for it.
        for(int i=0;i<nums.size();i++){
            rightSum = rightSum - nums[i];
            if(rightSum==leftSum){
                return i;
            }
            leftSum = leftSum + nums[i];
        }
	
	// if no pivot element found 
        return -1;
    }
};