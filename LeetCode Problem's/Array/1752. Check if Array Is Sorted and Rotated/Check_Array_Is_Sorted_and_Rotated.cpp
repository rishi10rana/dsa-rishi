class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        // To check count of many time our case (previous element > next element) is true it should not be ore than <=1
        int count = 0;

        // check from i -> 1 to <n
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                count++;
            }
        }

        // check for starting and ending 
        if(nums[n-1]>nums[0]){
            count++;
        }

        // returs true if count <=1 else gives false
        return count<=1;
    }
};
