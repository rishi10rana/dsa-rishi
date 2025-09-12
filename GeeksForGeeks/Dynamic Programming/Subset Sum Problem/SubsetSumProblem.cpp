class Solution {
  public:
    // Recursive Approach - TLE
    // T.C = O(2^n)   s.C = O(n)
    /*
    bool f(vector<int>& arr, int index, int target){
        // base case (target reached)
        if(target==0){
            return true;
        }
        // means reached last element
        if(index==0){
            // agar ye true deta means target mil gaya kyuki hum ye inde 0 wale lelenga
            // agar false means index 0 wale lena se bhi target nahi milta
            return arr[index]==target; 
        }
        
        // two choice
        int notpick = f(arr, index-1, target);
        int pick = false;
        if(target>=arr[index]){ // tabhi hum pick kar sakte kisi element ko
            pick = f(arr, index-1, target-arr[index]);
        }
        
        return pick || notpick; // gar kisi ek se bhi answer mil raha matlab wahi bhej do
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        return f(arr, n-1, sum);
        
    }
    */
    
    
    // DP Memonization
    // T.C = O(n * sum)   s.C = O(n * sum) + O(n)
    /*
    bool f(vector<int>& arr, int index, int target, vector<vector<int>> &dp){
        // base case (target reached)
        if(target==0){
            return true;
        }
        // means reached last element
        if(index==0){
            // agar ye true deta means target mil gaya kyuki hum ye inde 0 wale lelenga
            // agar false means index 0 wale lena se bhi target nahi milta
            return arr[index]==target; 
        }
        
        // check 
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        // two choice
        int notpick = f(arr, index-1, target, dp);
        int pick = false;
        if(target>=arr[index]){ // tabhi hum pick kar sakte kisi element ko
            pick = f(arr, index-1, target-arr[index], dp);
        }
        
        return dp[index][target] = pick || notpick; // gar kisi ek se bhi answer mil raha matlab wahi bhej do
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(arr, n-1, sum, dp);
        
    }
    */
    
    // DP Tabulation
    // T.C = O(n * sum)   s.C = O(n * sum)
    /*
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
        
        // sabse phela base cases bhar do
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        dp[0][arr[0]] = true;
        
        // remaining dp bhar do
        for(int index=1;index<n;index++){
            for(int target=1;target<=sum; target++){
                // two choice
                int notpick = dp[index-1][target];
                int pick = false;
                if(target>=arr[index]){
                    pick = dp[index-1][target-arr[index]];
                }
                
                dp[index][target] = pick || notpick;
            }
        }
        
        return dp[n-1][sum];
    }
    */
    
    
    // DP space optimization
    // T.C = O(n * sum)   s.C = O(2n) - using only two arrays
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector<bool> prev(sum+1, 0);
        vector<bool> curr(sum+1, 0);
        
        // sabse phela base cases bhar do
        prev[0] = true;
        curr[0] = true;
        
        prev[arr[0]] = true;
        
        // remaining cases solve kardo
        for(int index=1;index<n;index++){
            for(int target=1;target<=sum; target++){
                // two choice
                int notpick = prev[target];
                int pick = false;
                if(target>=arr[index]){
                    pick = prev[target-arr[index]];
                }
                
                curr[target] = pick || notpick;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};