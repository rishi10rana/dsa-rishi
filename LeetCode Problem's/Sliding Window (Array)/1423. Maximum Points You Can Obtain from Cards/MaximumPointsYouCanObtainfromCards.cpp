class Solution {
public:
    // Sliding Window / 2 Pointer Approacj
    // T.C = O(k + k)= O(2k)        S.C = O(1)
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lsum = 0; // sum of elements considered on left side
        int rsum = 0; // sum of elements considered on right side
        int maxSum = 0;
        // first k card lsum
        for(int i=0;i<k;i++){
            lsum = lsum + cardPoints[i];
        }
        maxSum = lsum;

        // modified sliding window
        int l = k - 1;
        int r = n - 1;
        while(l >= 0){
            // remove 1 element from left and add 1 element from right
            lsum = lsum - cardPoints[l];
            rsum = rsum + cardPoints[r];
            maxSum = max(maxSum, lsum + rsum);
            l--;
            r--;
        }

        return maxSum;
    }
};