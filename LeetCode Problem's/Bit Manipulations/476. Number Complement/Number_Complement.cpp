class Solution {
public:
    // T.C = O(1) as counrting only no of actual bits in num which is fixed and lie within 32 bit
    int findComplement(int num) {
        // count the no of actual bits in num
        int count = 0;
        int temp = num;
        while(temp!=0){
            temp = temp >> 1;
            count ++;
        }

        // Create Mask 
        unsigned int mask = (1U <<count) - 1; 

        // Method 1 using (&) 
        // return (~num) & mask;


        // Method 2 uaing (^)
        return num ^ mask;
    }   
};