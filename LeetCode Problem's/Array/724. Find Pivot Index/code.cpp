class Solution {
public:
    // Approach 1 : T.C = O(N) , S.C = O(1)
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

    // Approach 2 - Pre-Computation - T.C = O(N) , S.C = O(N)
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int* leftSum = new int[n];

        int totalSum =nums[0];
        leftSum[0] = nums[0];
        for(int i=1;i<n;i++){
            leftSum[i] = nums[i] + leftSum[i-1];
            totalSum = totalSum + nums[i];
        }

        for(int i=0;i<n;i++){
           int rightSum = (i>0)? totalSum-leftSum[i-1]-nums[i] : totalSum - nums[i];
           if(i>0 && rightSum==leftSum[i-1]){
                return i;
           }    
           else if(i==0){ // means i=0 means leftsum to 0 hoga
                // check karlo agar right bhi zero to 
                // pivot hai yaha
                if(rightSum==0){
                    return i;
                }
           }
        }
        return -1;
    }
};