class Solution {
public:
    // optimized approach : bit manipulation
    // T.C = O(n)
    // S.C = O(1)
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n, 0);
        for(int i=0;i<n;i++){
            // exception as 2 only prime no which is even
            if(nums[i] == 2){
                result[i] = -1; // no x for 2
                continue;
            }
            bool found = false; // for safety 
            for(int j=1;j<32;j++){ // check bits
                if((nums[i] & (1<<j)) > 0){
                    // means bit is 1
                    continue;
                }
                // found first 0 from right
                int prev = j - 1;
                // make prev bit 0
                int x = (nums[i] ^ (1 << prev));
                result[i] = x;
                found = true;
                break;
            }   
            if(!found){
                result[i] = -1;
            }
        }
        
        return result;
    }
};