class Solution {
public:
    // T.C = O(n)
    int singleNumber(vector<int>& nums) {
        int result = 0;

        // check every bit from 0 to 31
        for(int i=0;i<32;i++){
            int set = 0;
            // select one ith bit and check that it is ON for each number 
            for(int num: nums){
                if(((num>>i)&1)==1){
                    set++;
                }
            }
            // to decide that wether this ith bit should be ON for result or not
            if(set % 3 != 0){
                result = result | (1<<i);
            }
        }
        return result;
    }
};