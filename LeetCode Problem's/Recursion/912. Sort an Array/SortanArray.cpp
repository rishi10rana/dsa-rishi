class Solution {
public:
    void merge(vector<int> &nums,int low,int mid,int high){
        int len1 = mid - low + 1; // size of left array
        int len2 = high - mid;  // size of right array
        int *temp = new int[len1+len2]; // dynamically create array using calculated size

        int left = low;
        int right = mid + 1;
        int k = 0;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                temp[k] = nums[left];
                left++;
                k++;
            }
            else{
                temp[k] = nums[right];
                right++;
                k++;
            }
        }

        while(left<=mid){
            temp[k] = nums[left];
            left++;
            k++;
        }

        while(right<=high){
            temp[k] = nums[right];
            right++;
            k++;
        }

        // Copy the merged sorted in original array
        k = 0;
        for(int i=low;i<=high;i++){
            nums[i] = temp[k];
            k++;
        }

        delete []temp; // delete to dealocate memory given to temp array
    }

    void mergeSort(vector<int> &nums,int low,int high){
        // Base Condition
        if(low>=high){
            return; // stop here
        }

        // Divide it
        int mid = low + (high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};