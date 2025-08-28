// User function Template for C++

class Solution {
  public:
  
    // Recursive Approach
    // T.C = exponenetial - TLE
    /*
    int maxProfit(vector<int>& val, vector<int>& wt, int W, int index){
        // base case (sirf ek item bacha 0th wala)
        if(index==0){
            return (W/wt[index]) * val[index]; // this will take care of case nahi lena ya lena to kitna lena
        }
        
        // two choices hai pick or not pick
        int notpick = 0 + maxProfit(val, wt, W, index-1);
        
        int pick = 0;
        if(wt[index] <= W){
            pick = val[index] + maxProfit(val, wt, W-wt[index], index);
        }
        
        // ye dono me se jo max profit dega usse lena 
        return max(pick, notpick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // no of items
        int n = wt.size();
        
        int index = n-1; // start from last item
        return maxProfit(val, wt, capacity, index);
    }
    */
    
    // DP - Memonization
    // T.C = O(W)    S.C = O(n * W) + O(W)
    /*
    int maxProfit(vector<int>& val, vector<int>& wt, int W, int index, vector<vector<int>> &dp){
        // base case (sirf ek item bacha 0th wala)
        if(index==0){
            return (W/wt[index]) * val[index]; // this will take care of case nahi lena ya lena to kitna lena
        }
        
        // check
        if(dp[index][W]!=-1){
            return dp[index][W];
        }
        
        // two choices hai pick or not pick
        int notpick = 0 + maxProfit(val, wt, W, index-1, dp);
        
        int pick = 0;
        if(wt[index] <= W){
            pick = val[index] + maxProfit(val, wt, W-wt[index], index, dp);
        }
        
        // ye dono me se jo max profit dega usse lena 
        return dp[index][W] = max(pick, notpick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // no of items
        int n = wt.size();
        
        // 2D Dp
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        
        int index = n-1; // start from last item
        return maxProfit(val, wt, capacity, index, dp);
    }
    */
    
    
    // DP - Tabulation
    // T.C = O(n * W)    S.C = O(n * W)  
    /*
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // no of items
        int n = wt.size();
        
        // 2D Dp
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        
        // sabse base case bhar do
        // item 0th ho to max kitna profit mil akte for differnet capacity
        for(int c=0;c<=capacity;c++){
            dp[0][c] =  (c/wt[0]) * val[0];
        }
        
        // fill the remaining dp
        for(int i=1;i<n;i++){
            
            for(int c=0;c<=capacity;c++){
                
                // two choices
                int notpick = 0 + dp[i-1][c];
                
                int pick = 0;
                if(wt[i] <= c){
                    pick = val[i] + dp[i][c - wt[i]];
                }
                
                dp[i][c] = max(pick, notpick);
            }
        }
        
        // jab last item tak ab pahuch gaye and max capacity hai to ab max kitna proft mil sakta
        return dp[n-1][capacity];
    }
    */
    
    // DP - space optimization - using only 2 Array
    // T.C = O(n * W)    S.C = O(2W)  
    /*
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // no of items
        int n = wt.size();
        
        // two arrays only used for 2 rows
        vector<int> prev(capacity+1, 0);
        vector<int> curr(capacity+1, 0);
        
        // sabse base case bhar do
        // item 0th ho to max kitna profit mil akte for differnet capacity
        for(int c=0;c<=capacity;c++){
            prev[c] = (c/wt[0]) * val[0];
        }
        
        // fill the remaining dp
        for(int i=1;i<n;i++){
            
            for(int c=0;c<=capacity;c++){
                
                // two choices
                int notpick = 0 + prev[c];
                
                int pick = 0;
                if(wt[i] <= c){
                    pick = val[i] + curr[c - wt[i]];
                }
                
                curr[c] = max(pick, notpick);
            }
            prev = curr;
        }
        
        // jab last item tak ab pahuch gaye and max capacity hai to ab max kitna proft mil sakta
        return prev[capacity];
    }
    */
    
    
    // DP - space optimization - using only 1 Array
    // T.C = O(n * W)    S.C = O(W)  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        
        // no of items
        int n = wt.size();
        
        // two arrays only used for 2 rows
        vector<int> curr(capacity+1, 0);
        
        // sabse base case bhar do
        // item 0th ho to max kitna profit mil akte for differnet capacity
        for(int c=0;c<=capacity;c++){
            curr[c] = (c/wt[0]) * val[0];
        }
        
        // fill the remaining dp
        for(int i=1;i<n;i++){
            
            for(int c=0;c<=capacity;c++){
                
                // two choices
                int notpick = 0 + curr[c];
                
                int pick = 0;
                if(wt[i] <= c){
                    pick = val[i] + curr[c - wt[i]];
                }
                
                curr[c] = max(pick, notpick);
            }
        }
        
        // jab last item tak ab pahuch gaye and max capacity hai to ab max kitna proft mil sakta
        return curr[capacity];
    }
};