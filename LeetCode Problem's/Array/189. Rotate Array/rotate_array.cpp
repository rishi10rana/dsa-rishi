class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Create a temp vector to store rotated array
        vector<int> temp(n);

        // Traverse each element of original array and apply rotate formula on it
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }

        // finally after getting rotataed array store it back in "nums"
        nums=temp;
    }
};