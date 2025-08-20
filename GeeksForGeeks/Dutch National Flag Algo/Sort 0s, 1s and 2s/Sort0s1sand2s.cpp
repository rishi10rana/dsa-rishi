class Solution {
  public:
    // Dutch National Flag Algorithm
    // T.C = O(n) S.C = O(1)
    void sort012(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        
        int low = 0, mid = 0, high = n-1;
        while(mid<=high){
            // 0 shoud be in extreme left
            if(arr[mid]==0){
                swap(arr[mid],arr[low]);
                mid++;
                low++;
            }
            // 1 agar hai to leave it
            else if(arr[mid]==1){
                mid++;
            }
            // 2 should be in the extreme right
            else if(arr[mid]==2){
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};