class Solution {
public:
    // Approach 1
    /*
    int hammingWeight(int n) {
        int setBits = 0;
        while(n!=0){
            if((n&1)==1){
                setBits++;
            }
            n = n >> 1;
        }
        return setBits;
    }
    */

    // Approach 2 T.C = O(n) n = no of bits in binary represntation of number  S.C = O(1)
    int hammingWeight(int n) {
        int count = 0;
        while(n!=0){
            n = n & (n-1);
            count++;
        }
        return count;
    }
    
};