class Solution {
public:
    long long int binarySearch(int n){
        // we are creating an imaginary array from (0 to --> n) which is our search space where nswer can be present.
        int start = 0, end = n;
        // ans variable to store any result which is close  to actual
        long long int ans = -1;
        long long int mid = start + (end-start)/2;
        while(start<=end){
            if(mid*mid == n){
                return mid;
            }
            // means all elements after mid cant give answer
            else if(mid*mid > n){
                end = mid - 1;
            }
            // means this can be a possible answer but maybe after this mid also in right we can get more close answer
            else if(mid*mid < n){
                ans = mid;
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};