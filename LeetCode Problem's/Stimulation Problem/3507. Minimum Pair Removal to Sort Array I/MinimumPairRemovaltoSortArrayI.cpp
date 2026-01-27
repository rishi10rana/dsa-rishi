class Solution {
public:
    // approach : bruteforce
    // T.C = O(n * n)= O(n^2)
    // S.C = O(1)
    int minimumPairRemoval(vector<int>& nums) {

        int opr = 0;
        while(!is_sorted(nums.begin(), nums.end())){// do jabtak ar sorted na ho jaye
            // each time ek element reduce ho jata
            int sum = INT_MAX;
            int idx = -1;
            // find min sum pair each time
            for(int i=0;i<nums.size()-1;i++){
                int s = nums[i] + nums[i+1];
                if(s < sum){
                    sum = s;
                    idx = i;
                }
            }
            // replace the pair with its min sum
            nums[idx] = sum;
            nums.erase(nums.begin() + (idx+1)); // manually bhi kar sakte
            opr++;
        }
        return opr;
    }
};