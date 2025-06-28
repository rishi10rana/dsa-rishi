class Solution {
public:
    // T.C = O(1)
    int getSum(int a, int b) {
        int carry = 0;
        // note - negative numbers are handled by 2s complement
        while(b!=0){
            carry = (a & b) << 1; // get any carry before adding
            a = a ^ b; // add numvbers without carry
            b = carry; // consider caary to be added next time
        }
        return a;
    }
};