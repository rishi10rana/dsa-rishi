// User function template for C++
class Solution {
  public:
    // Recursive Approach - TLE
    /*
    int solve(vector<int> &nums, int index){
        // base case
        if(index < 0){
            return 0; // ye idnex exist hi nahi karta to isaki wajah se sum 0 hoga
        }
        if(index==0){
            // last element hai to include kar hi lenha kyuki koii -ve number todhi hai answer badega hi
            return nums[index]; 
        }
        
        // ab tow choices hai humpe after selecting an index
        int include = nums[index] + solve(nums, index-2);
        
        int exclude = 0 + solve(nums, index-1);
        
        // jo bhi inhme se max sum de raha hoga wo return kardo
        return max(include, exclude);
    }
  
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        
        int n = arr.size();
        return solve(arr, n-1); // starting from last index
    }
    */
    
    
    // DP - Memonization
    // T.C= O(n) , S.C = O(n) + O(n)
    /*
    int solve(vector<int> &nums, int index, vector<int>& dp){
        // base case
        if(index < 0){
            return 0; // ye idnex exist hi nahi karta to isaki wajah se sum 0 hoga
        }
        if(index==0){
            // last element hai to include kar hi lenha kyuki koii -ve number todhi hai answer badega hi
            return nums[index]; 
        }
        // check alredy to nahi
        if(dp[index]!=-1){
            return dp[index];
        }
        
        // ab tow choices hai humpe after selecting an index
        int include = nums[index] + solve(nums, index-2, dp);
        
        int exclude = 0 + solve(nums, index-1, dp);
        
        // jo bhi inhme se max sum de raha hoga wo return kardo
        return dp[index] = max(include, exclude);
    }
  
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n, -1);
        
        return solve(arr, n-1, dp); // starting from last index
    }
    */
    
    
    
    // DP - Tabulation
    // T.C = O(n) , S.C = O(n)
    /*
    int findMaxSum(vector<int>& arr) {
        
        int n = arr.size();
        vector<int> dp(n, -1);
        
        // sabse phela base cases bhar do
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]); // dono adjacent hai aur two elements hai inmei se jo max hoga wo store karo
    
        // fill the remaing dp
        for(int i=2;i<n;i++){
            int include = arr[i] + dp[i-2];
            int exclude = 0 + dp[i-1];
            
            dp[i] = max(include, exclude);
        }
        
        // final answer hoga ki las element ko include karke max kitna sum mil sakta
        return dp[n-1];
    }
    */
    
    
    // DP - further space optimization
    // T.C = O(n) , S.C = O(1)
    int findMaxSum(vector<int>& arr) {
        
        int n = arr.size();
        
        // handle edge case
        if(n==1){
            return arr[0];
        }
        
        if(n==2){
            return max(arr[0], arr[1]);
        }
        
        // bus 3 variable se hi answer nikal jayega
        int curr;
        int prev2= arr[0];
        int prev1 = max(arr[0], arr[1]); // dono adjacent hai aur two elements hai inmei se jo max hoga wo store karo
    
        // fill the remaing dp
        for(int i=2;i<n;i++){
            int include = arr[i] + prev2;
            int exclude = 0 + prev1;
            
            curr = max(include, exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        
        // final answer hoga ki las element ko include karke max kitna sum mil sakta
        return curr;
    }
    
    
};