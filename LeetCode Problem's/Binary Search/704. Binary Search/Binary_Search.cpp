class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Maintain 3 Pointers
        int low = 0;
        int high = nums.size()-1;
        int mid = low + (high-low)/2;

        while(low<=high){
            if(nums[mid]==target){ 
                return mid; // matlab target mil gaya 
            }
            else if(nums[mid]<target){
                low = mid + 1;  // matlab target bada hai , matlab mid ke right mei serach karo ab 
            }
            else if(nums[mid]>target){
                high = mid - 1; // matlab target chota hai , matlab mid ke left mei search karo ab
            }
            mid = low + (high-low)/2; // har iteration ki end mei mid update kardo
        }

        return -1; // agar target nahi mila
    }
};