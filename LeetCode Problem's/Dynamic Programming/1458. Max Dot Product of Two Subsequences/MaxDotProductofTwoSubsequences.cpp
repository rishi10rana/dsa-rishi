class Solution {
public:
    // Recursion
    // T.C = O(2^m * 2^n) = O(2^(m+n)) exponential
    /*
    int m;
    int n;
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        // base case
        if(i == m || j == n){
            // cant do cross product as the subseq cannot be empty
            // invalid case
            return -1e9;
        }

        // we have 4 possibilities
        // 1st possibility (normal cross product just take  i and j)
        int val = nums1[i] * nums2[j];
        // 2nd possibility (take  i and j and also call for other elements to consider 
        // them in  subsequence maybe)
        int take_i_j = (nums1[i] * nums2[j])  + solve(nums1, nums2, i+1, j+1);
        // 3rd possibility (take i and skip current j and choose any other j for subsequence)
        int take_i = solve(nums1, nums2, i, j+1);
        // 4th possibility (take j and skip i choose some other i)
        int take_j = solve(nums1, nums2, i+1, j);

        // current i and j ki 4 possibility se jo max de wahi return karo
        return max({val, take_i_j, take_i, take_j});

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        // i, j
        return solve(nums1, nums2, 0, 0);
    }
    */

    // DP + Memonize
    // T.C = O(m+1 * n+1) states being stored = O(m * n)
    int m;
    int n;
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        // base case
        if(i == m || j == n){
            // cant do cross product as the subseq cannot be empty
            // invalid case
            return -1e9;
        }

        if(dp[i][j] != -1e9){
            return dp[i][j];
        }

        // we have 4 possibilities
        // 1st possibility (normal cross product just take  i and j)
        int val = nums1[i] * nums2[j];
        // 2nd possibility (take  i and j and also call for other elements to consider 
        // them in  subsequence maybe)
        int take_i_j = (nums1[i] * nums2[j])  + solve(nums1, nums2, i+1, j+1);
        // 3rd possibility (take i and skip current j and choose any other j for subsequence)
        int take_i = solve(nums1, nums2, i, j+1);
        // 4th possibility (take j and skip i choose some other i)
        int take_j = solve(nums1, nums2, i+1, j);

        // current i and j ki 4 possibility se jo max de wahi return karo
        return dp[i][j] = max({val, take_i_j, take_i, take_j});

    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();

        // initialize dp array with -ve value
        for(int i=0;i<500;i++){
            for(int j=0;j<500;j++){
                dp[i][j] = -1e9;
            }
        }

        // i, j
        return solve(nums1, nums2, 0, 0);
    }
};