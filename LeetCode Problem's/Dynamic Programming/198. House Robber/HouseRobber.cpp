class Solution {
public:
    // Recursive Approach - will give TLE
    /*
    int robbery(int index, vector<int>& nums){
        // base case
        if(index==0){
            // matlab ek hi ghar bacha to wahi se chori karlo
            return nums[index];
        }
        if(index < 0){ // invalid case ye ghar hi nhai hai
            return 0;
        }

        return max(nums[index] + robbery(index-2, nums), robbery(index-1, nums));
    }

    int rob(vector<int>& nums) {
        int index = nums.size()-1; // last index ya last house se start kar raha
        return robbery(index, nums);
    }
    */

    // DP - top-bottom approach
    // T.C= O(n) , S.C= O(n)
    /*
    int robbery(int index, vector<int>& nums, vector<int> &dp){
        // base case
        if(index==0){
            // matlab ek hi ghar bacha to wahi se chori karlo
            return nums[index];
        }
        if(index==1){
            // gar two hi house bache matlab unhmei se kisi ek koii hi choose karenga to get max cash
            return max(nums[0], nums[1]);
        }
        // check karlo kahi value already calculated to nahi
        if(dp[index]!=-1){
            return dp[index];
        }

        // recursive call or store bhi karte raho
        return dp[index] = max(nums[index] + robbery(index-2, nums, dp), robbery(index-1, nums, dp));
    }

    int rob(vector<int>& nums) {
        int index = nums.size()-1; // last index ya last house se start kar raha

        vector<int> dp(nums.size(),-1);
        return robbery(index, nums, dp);
    }
    */

    // DP - bottom-up approach
    // T.C = O(n) , S.C = O(n)
    /*
    int rob(vector<int>& nums) {
        // no of houses
        int n = nums.size();

        // edge case
        // sirf ek hi ghar hai
        if(n==1){
            return nums[0];
        }

        // matlab ye store karta ith hourse tak hum max kint aamount chori kar paa rahe
        vector<int> dp(n,-1);

        // sabse phela base cases bhar do
        dp[0] = nums[0]; // ek hi house ai
        dp[1] = max(nums[0] , nums[1]); // do house hai

        // ab baki remaing dp bhar do
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        // kitna max amount chori kar paa rahe till n-1th house
        return dp[n-1];
    }
    */

    // DP - bottom-up - further space optimization
    // T.C = O(n) , S.C = O(1)
    int rob(vector<int>& nums) {
        // no of houses
        int n = nums.size();

        // edge case
        // sirf ek hi ghar hai
        if(n==1){
            return nums[0];
        }

        /// gar sirf two house
        if(n==2){
            return max(nums[0] , nums[1]);
        }

        int curr;
        int prev1 = max(nums[0] , nums[1]);
        int prev2 = nums[0];
       

        // ab last hosue tak kint amax amount chori kar sakte wo nikal lo
        for(int i=2;i<n;i++){
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        // kitna max amount chori kar paa rahe till last house
        return curr;
    }
};