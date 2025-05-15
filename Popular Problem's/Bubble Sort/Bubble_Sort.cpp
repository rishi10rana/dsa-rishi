#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Loop will run for rounds i= 1--> n
    for(int i=1;i<n;i++){
        // Use to check if Zero swapping in a round means array already sorted just break the loop
        bool swapped=false;

        // In a Single round iteration or comparisons from j = 0 ---> n-i
        for(int j=0;j<n-i;j++){
            // swap adjacent elements if condition satisfied
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}
