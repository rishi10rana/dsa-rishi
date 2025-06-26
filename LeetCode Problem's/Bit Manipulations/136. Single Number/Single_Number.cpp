class Solution {
public:
    // Aproach - Use XOR sum technique
    // xor cancel out similar values 
    // and xor of anumber with 0 gives back same number
    // T.C = O(n) 
    int singleNumber(vector<int>& nums) {
        // traverse in array and xor them
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result = result ^ nums[i];
        }
        return result; // this wil store the element which occurs only once
    }
};