class Solution {
  public:
    int merge(vector<int> &arr,int start,int end){
        // varibale to count inversions
        int count = 0;
        
        int mid = start + (end-start)/2;
        
        // find sizes for two half arrays
        int len1 = mid - start + 1;
        int len2 = end - mid;
        
        // create teo half arrays
        int *left = new int[len1];
        int *right = new int[len2];
        
        // copy the elements in these arrays
        int mainIndex = start;
        for(int i=0;i<len1;i++){
            left[i] = arr[mainIndex];
            mainIndex++;
        }
        for(int i=0;i<len2;i++){
            right[i] = arr[mainIndex];
            mainIndex++;
        }
        
        // merge two arrays in soreted form
        mainIndex = start; // for main array
        int i = 0;  // for left array
        int j = 0;  // for right array
        while(i<len1 && j<len2){
            if(left[i]<=right[j]){
                arr[mainIndex++] = left[i++];
            }
            else{
                arr[mainIndex++] = right[j++];
                count = count + (len1-i);
            }
        }
        
        // add any remaining elements
        while(i<len1){
            arr[mainIndex++] = left[i++];
        }
        while(j<len2){
            arr[mainIndex++] = right[j++];
        }
        
        // delete dynamically allocated memory
        delete []left;
        delete []right;
        
        return count;
    }
  
    int mergeSort(vector<int> &arr,int start,int end){
        int count = 0;
        // Base Case
        if(start>=end){
            return count; // stop dividing as single element array are already sorted
        }
        int mid = start + (end-start)/2;
        
        // Divide in left half
        count = count + mergeSort(arr,start,mid);
        // Divide in right half
        count = count + mergeSort(arr,mid+1,end);
        
        // finally merge arrays in sorted form
        count = count + merge(arr,start,end);
        return count;
    }
    
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return mergeSort(arr,0,arr.size()-1);
    }
};