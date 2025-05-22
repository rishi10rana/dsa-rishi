int helper(vector<int> &nums,int start,int end,int target){
    // 1 - Base Case
    if(start>end){
        return -1; // Not Found
    }

    int mid = start + (end-start)/2;

    if(nums[mid]==target){
        return mid;    // Element Found
    }
    if(nums[mid]<target){ // Search in Right Half
        return helper(nums,mid+1,end,target);
    }
    else{   // Search in Left Half
        return helper(nums,start,mid-1,target);
    }
}

int search(vector<int> &nums, int target) {
    // Write your code here.
    return helper(nums,0,nums.size()-1,target);
}