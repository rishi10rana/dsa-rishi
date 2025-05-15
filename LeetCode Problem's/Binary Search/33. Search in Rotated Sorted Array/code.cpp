class Solution {
public:
    // Get Pivot Index - can be said as as any index in arrray that can be used as reference for other computations
    // here we find the least element in the sorted ,rotated array
    int pivotIndex(vector<int>& arr,int n){
        int start = 0 , end = n-1;
        int mid = start + (end-start)/2;
        while(start<end){
            // if it lies in 1st line
            if(arr[mid]>=arr[0]){
                start = mid+1;
            }
            // if it lies in 2nd line
            else{
                end = mid;
            }
            mid = start + (end-start)/2;
        }
        return start;
    }
    // binary search algorithm
    int binarySearch(vector<int>& arr,int start,int end,int target){
        int mid = start + (end-start)/2;
        while(start<=end){
            if(arr[mid]==target){
                return mid;
            }
            else if(target>arr[mid]){
                start = mid + 1;
            }
            else if(target<arr[mid]){
                end = mid -1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // get Pivot Index
        int pivot = pivotIndex(nums,n);

        // apply binary search on 2nd Line
        if(target>=nums[pivot] && target<=nums[n-1]){
            return binarySearch(nums,pivot,n-1,target);
        }
        // apply binary search on 1st Line.
        else{
            return binarySearch(nums,0,pivot-1,target);
        }
    }
};