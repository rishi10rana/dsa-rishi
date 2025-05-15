class Solution {
public:
    int firstOcc(vector<int>& arr,int n,int target){
        int start = 0, end = n-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            if(arr[mid]==target){
                ans = mid;
                end = mid-1;
            }
            else if(target>arr[mid]){
                start = mid+1;
            }
            else if(target<arr[mid]){
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }

    int lastOcc(vector<int>& arr,int n,int target){
        int start = 0, end = n-1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while(start<=end){
            if(arr[mid]==target){
                ans = mid;
                start = mid+1;
            }
            else if(target>arr[mid]){
                start = mid+1;
            }
            else if(target<arr[mid]){
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(firstOcc(nums,nums.size(),target));
        result.push_back(lastOcc(nums,nums.size(),target));
        return result;
    }
};