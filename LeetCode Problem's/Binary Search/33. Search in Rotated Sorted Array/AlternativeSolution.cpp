#include <iostream>
using namespace std;

// APPROACH - II

/*
int search(int arr[],int n,int target){
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    while(start<=end){
        // target found
        if(target==arr[mid]){
            return mid;
        }
        // Target may be lie in first part
        if(target>=arr[0]){
            if(target<arr[mid]){
                end = mid-1;
            }
            // mid itself lie on left side
            else if(arr[mid]>=arr[0]){
                start = mid +1;
            }
            // mid is in right part then
            else{
                end = mid -1;
            }
        }
        // Target may be lie in right part
        else{
            if(target>arr[mid]){
                start = mid + 1;
            }
            // may be mid lie in left part
            else if(arr[mid]>=arr[0]){
                start = mid + 1;
            }
            // mid in right part and target < arr[mid]
            else{
                end = mid -1;
            }
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main(){
    // Sorted, rotated array
    int arr[7] = {4,5,6,7,0,1,2};
    cout << "index: " << search(arr,7,4) << endl;
    return 0;
}

*/

// APPROACH - III
#include <vector>
#include <algorithm>

// find pivot element index (least value element ka index)
int pivotIndex(vector<int>& arr,int n){
    int start = 0, end = n-1;
    int mid = start + (end-start)/2;
    while(start<end){
        // on 1st line
        if(arr[mid]>=arr[0]){
            start = mid + 1;
        }
        else{
            // on 2nd line
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    int n = arr.size();
    // pivot element divide array in two parts
    int pivot = pivotIndex(arr,n);

    // consider pivot index = 4 then pivotItr = arr.begin()+pivot index
    vector<int>::iterator pivotItr = arr.begin()+pivot; 

    // apply binary search STL algoithm in right part
    if(target>=arr[pivot] && target<=arr[n-1]){
        if(binary_search(pivotItr,arr.end(),target)){
            // lower_bound returns the index of first occurance of target if present
            auto itr = lower_bound(pivotItr,arr.end(),target);
            int index = itr - arr.begin(); // to find the index of found element
            cout << "index: " << index << endl;
        }
        else{
            // if target not found return -1
            cout << "index : -1" << endl;
        }
    }
    // otherwise apply binary search on left part
    else{
        if(binary_search(arr.begin(),pivotItr,target)){
            auto itr = lower_bound(arr.begin(),pivotItr,target);
            int index = itr - arr.begin();
            cout << "index: " << index << endl;
        }
        else{
            cout << "index : -1" << endl;
        }
    }
    return 0;
}