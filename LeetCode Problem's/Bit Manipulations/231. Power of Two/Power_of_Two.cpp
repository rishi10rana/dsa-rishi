class Solution {
public:
    // Approach 1- BruteForce T.C = O(n) 
    /*
    bool isPowerOfTwo(int n) {
        int ans = 1;
        for(int i=0;i<=30;i++){
            if(ans==n){
                return true;
            }

            if(ans<INT_MAX/2){
                ans = ans*2;
            }
        }
        return false;
    }
    */

    // Optimized way - use bitwise opeartors , T.C = O(1)
    bool isPowerOfTwo(int n) {
        // n = 4    4 & 3 = 0
        // n = 7    7 & 6 not equal to 0
        return n > 0 && (n & (n-1))==0;
    }
};