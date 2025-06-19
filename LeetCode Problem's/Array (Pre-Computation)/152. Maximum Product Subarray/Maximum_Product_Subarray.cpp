class Solution {
public:
    // Approach = Prefix , Suffix Computation T.C = O(n) , S.C = O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProduct = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        // traver whole array at same time calculate total prefix product from left and 
        // suffix product from right
        for(int i=0;i<n;i++){
            // to deal with any 0 if encountered 
            // after each 0 conside a new subarray
            if(prefix==0) prefix = 1;
            if(suffix==0) suffix = 1;

            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            // find max from corresponding prefix and suffix and update the maxProduct
            maxProduct = max(maxProduct,max(prefix,suffix));
        }
        return maxProduct;
    }

    // Aproach - BruteForce T.C = O(n^2) S.C = O(1)
    /*
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxProduct = INT_MIN;
        // try all possible subarrays 
        for(int i = 0;i<n;i++){
            int product = 1;
            for(int j = i;j<n;j++){
                product = product * nums[j];
                maxProduct = max(maxProduct,product);
            }
        }
        return maxProduct;
    }
    */
};