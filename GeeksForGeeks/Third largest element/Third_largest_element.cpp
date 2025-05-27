class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // Your code here
        int firstLargest = -1;
        int secondLargest = -1;
        int thirdLargest = -1;
        
        // traverse in array
        for(int i=0;i<arr.size();i++){
            if(arr[i]>firstLargest){ // agar firstlargest se bada number aajaye koii
                thirdLargest = secondLargest;
                secondLargest = firstLargest;
                firstLargest = arr[i];
            }
            else if(arr[i]>secondLargest){ // agar firstLAregst se to bada nahi par secondlargest se bada hoo
                thirdLargest = secondLargest;
                secondLargest = arr[i];
            }
            else if(arr[i]>thirdLargest){ // agar first ya second se to nahi par third se bada hoo
                thirdLargest = arr[i];
            }
        }
        
        return thirdLargest;
    }
};