class Solution {
public:
    // Approach - Bruteforce T.C = O(n^2)  S.C = O(1) - TLE
    /*
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // generate all the subarrays but consider only those where no of zeroes are atmost k and keep a updatig the max possible substring length

        int maxlength = 0;
        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j=i;j<n;j++){
                if(nums[j]==0){
                    zeros++; // 0 mila to update zeros count
                }

                if(zeros<=k){ // we have atmost k zeroes so consider substr valid and update max substring length
                    int len = j - i + 1;
                    maxlength = max(maxlength, len);
                }
                else{ // means no of zeroes exceed dont take further substrings
                    break;
                }
            }
        }

        return maxlength;
    }
    */

    // Optimal - Sliding Window
    // T.C = O(2n)    S.C = O(1)
    /*
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0,r = 0, maxlen = 0, zeroes = 0;
        while(r < n){
            // agar 0 mila
            if(nums[r]==0){
                zeroes++;
                // check agar consdition violate huii no of zereos jyada ho re
                while(zeroes > k){
                    if(nums[l]==0){ // agar 0 nikal raha when moving "l" tab zereos ko decerement kardo
                        zeroes--;
                    }
                    l++;
                }
            }

            // agr sab safe hai
            if(zeroes<=k){
                int len = r - l +1;
                maxlen = max(maxlen, len);
            }
            r++;
        }

        return maxlen;
    }
    */

    // Most Optimal - Sliding Window
    // T.C = O(n)    S.C = O(1)
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0,r = 0, maxlen = 0, zeroes = 0;
        while(r < n){
            // agar 0 mila
            if(nums[r]==0){
                zeroes++;
            }

            // agar condition violate huii to window ko shrink kardo by one element
            if(zeroes > k){
                if(nums[l]==0){ // jo lement hata rahe agar wo hai to decrement zeroes
                    zeroes--;
                }
                l++;
            }

            // check karo sab sahi too
            if(zeroes <= k){
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }

        return maxlen;
    }
};