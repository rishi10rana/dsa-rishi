class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use 2 pointer
        // Jaha Par writer point kar raha hoga waha se aage par hum element dal denga
        int write = 0;
        for(int read=1;read<nums.size();read++){ // read all elements one by one
            if(nums[read]!=nums[write]){  // this will immediately an element which was not 
            // equal to previous nums[writer]
                write++;
                nums[write] = nums[read];
            }
        }

        // To get the size of new array with only distinct elements
        int k = write + 1;
        return k;
    }
};