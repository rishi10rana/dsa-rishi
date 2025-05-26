#include <bits/stdc++.h>

int partition(vector<int> &arr,int s,int e){
    // find pivot element
    int pivot = arr[s];

    // find the count of elements which are smaller than pivot
    int count = 0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    // find the picot index and swap the pivot to its correct position
    int pivotIndex = s + count;
    swap(arr[s],arr[pivotIndex]);

    // fulfil condition of all elements in left of pivot should be samll 
    // and all elements in right should be large using 2 Pointer
    int i = s;
    int j = e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){ // move forward if the element fulfills condition
            i++;
        }
        while(arr[j]>pivot){ // move backward if the element fulfills condition
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){ // if conditon not fulfilled 
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    // return kardena pivot elemente ka index for further partioning
    return pivotIndex;
}

void helper(vector<int> &arr,int s,int e){
    // Base Case
    if(s>=e){
        return; // stop here dont partition more
    }

    // find pivot index for partitioning
    int p = partition(arr,s,e);

    // Recursively partition left part and right part using pivot index
    helper(arr,s,p-1);
    helper(arr,p+1,e);
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    helper(arr,0,arr.size()-1);
    return arr;
}
