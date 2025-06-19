class Solution {
public:
    // Approach - Sliding Window Algorithm T.C = O(n) , S.C = O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = 0; // to store the sum of elements in window
        // store intially sum of first k elements
        for(int i=0;i<k;i++){
            sum = sum + nums[i];
        }

        int maxSum = sum; // to store max sum as it will give max average
        // set bound of your window (using some pointers)
        int startIndex = 0; // ye current window ka part hai jisse minus karna
        int endIndex = k; // ye current window ka just aage wala element jisse add karna
        while(endIndex < n){

            sum = sum - nums[startIndex]; // to remove previous element
            startIndex++;

            sum = sum + nums[endIndex]; // to add next element
            endIndex++;

            // update max sum each time
            maxSum = max(maxSum,sum);
        }

        // output max average in double
        return (double) maxSum/k;

    }
};