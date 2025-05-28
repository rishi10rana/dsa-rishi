class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Apply Binary Search
        int low = 0;
        int high = nums.size()-1;

        int mid = low + (high-low)/2;
        while(low<=high){
            if(nums[mid]==target){
                return mid; // means target is found
            }
            else if(nums[mid]<target){
                low = mid + 1; // means search in right part of mid
            }
            else if(nums[mid]>target){
                high = mid - 1; // means search in left part of mid
            }
            mid = low + (high-low)/2;
        }
        // means if element not found tell appropriate location to insert it , that will be [low]
        return low;
    }
};