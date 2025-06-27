class Solution {
public:
    // T.C = O(n)
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0; // to store reverse
        for(int i=0;i<32;i++){
            int lastBit = n & 1; // get last bit
            result = (result << 1) | lastBit; // move left by 1 bit then add the lastbit
            n = n >> 1; // remove this last bit as its work done
        }
        return result;
    }
};