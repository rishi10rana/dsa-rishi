void merge(vector <int> &arr,int start,int end){
    int mid = start + (end-start)/2;

    // find the size of two halfs
    int len1 = mid - start + 1;
    int len2 = end - mid;

    // create the 2 half arrays
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

    // merge these two arrays in single in sorted form
    mainIndex = start; // pointer for main array
    int i = 0;  // pointer for left half
    int j = 0;  // pointer for right half

    // compare values and add in main array
    while(i<len1 && j<len2){
        if(left[i]<right[j]){
            arr[mainIndex] = left[i];
            mainIndex++;
            i++;
        }
        else{
            arr[mainIndex] = right[j];
            mainIndex++;
            j++;
        }
    }

    // add any remianing values from left half
    while(i<len1){
        arr[mainIndex++] = left[i++];
    }
    // add any remianing values from right half
    while(j<len2){
        arr[mainIndex++] = right[j++];
    }

    // free the dynamic memory
    delete []left;
    delete []right;

}

void helper(vector <int> &arr,int start,int end){
    // Base Case
    if(start>=end){
        return; // stop dividing array further as 1 element array is already sorted
    }

    int mid = start + (end-start)/2;

    // Divide in left half
    helper(arr,start,mid);

    // Divide in right half
    helper(arr,mid+1,end);

    // Merge the above two arrays in sorted form
    merge(arr,start,end);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    helper(arr,0,n-1);
}