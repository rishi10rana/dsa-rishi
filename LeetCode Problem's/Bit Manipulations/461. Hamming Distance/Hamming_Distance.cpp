class Solution {
public:
    // Approach 1 T.C = O(n)
    /*
    int hammingDistance(int x, int y) {
        int hammingDistance = 0;

        // if teo bits smae their xor give 0 , if they are not same their xor give 1
        // check each 32 bit 
        for(int i=0;i<32;i++){
            int bit1 = (x >> i) & 1;
            int bit2 = (y >> i) & 1;
            if((bit1 ^ bit2) == 1){ // means bits not same at this ith position
                hammingDistance++;
            }
        }
        return hammingDistance;
    }
    */

    // Approach 2
    /*
    */
    int hammingDistance(int x, int y) {
        int hammingDistance = 0;

        x = x ^ y;
        // count the no of sits bits in x
        while(x!=0){
            x = x & (x-1);
            hammingDistance++;
        }
        return hammingDistance;
    }
};