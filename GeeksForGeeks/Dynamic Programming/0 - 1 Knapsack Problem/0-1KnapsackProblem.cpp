class Solution {
  public:
    // Recursive Approach - TLE
    // T.C= O(n * W)
    // S.C = O(n * W) + O(recursion)
    /*
    int solve(int W, vector<int>& val, vector<int> &wt, int index){
        // base case
        // if last item hi hai humaraa pus to usse compare karenga max capacity se agar agar chota ya barabar hai tabhi place karenga
        if(index==0){
            if(wt[0]<=W){
                // le liya
                return val[0];
            }
            else{ // nahi liya
                return 0;
            }
        }
        
        // abb yaha humne ek item ko select kar rakha hai 
        // usse yaha to to incliude karenga ya exclude karenga
        int include = 0;
        if(wt[index]<=W){
            include = val[index] + solve(W-wt[index], val, wt, index-1);
        }
        
        // exclude kardiya
        int exclude = 0 + solve(W,val,wt,index-1);
        
        // ab humaraa pas iss item ko include kareke ya exclude karke jo ans aaya tha uss mei jo max value dega usse uper bhej dena
        int ans = max(include, exclude);
        return ans;
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // no of items
        int n = wt.size();
        
        int index = n - 1; // yaha hum last index se start karna wala recursion use kar rahe
        return solve(W,val,wt,index);
        
    }
    */
    
    
    // DP - Top - Down
    // T.C < O(n * W)
    // S.C = O(n * W) + O(recursion)
    /*
    int solve(int W, vector<int>& val, vector<int> &wt, int index,vector<vector<int>>& dp){
        // base case
        // if last item hi hai humaraa pus to usse compare karenga max capacity se agar agar chota ya barabar hai tabhi place karenga
        if(index==0){
            if(wt[0]<=W){
                // le liya
                return val[0];
            }
            else{ // nahi liya
                return 0;
            }
        }
        
        // check value already to nahi
        if(dp[index][W]!=-1){
            return dp[index][W];
        }
        
        // abb yaha humne ek item ko select kar rakha hai 
        // usse yaha to to include karenga ya exclude karenga
        int include = 0;
        if(wt[index]<=W){
            include = val[index] + solve(W-wt[index], val, wt, index-1, dp);
        }
        
        // exclude kardiya
        int exclude = 0 + solve(W,val,wt,index-1, dp);
        
        // ab humaraa pas iss item ko include kareke ya exclude karke jo ans aaya tha uss mei jo max value dega usse uper bhej dena
        int ans = max(include, exclude);
        return dp[index][W] = ans;
        
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // no of items
        int n = wt.size();
        
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        
        int index = n - 1; // yaha hum last index se start karna wala recursion use kar rahe
        return solve(W,val,wt,index,dp);
        
    }
    */
    
    
    // Dp - tabulation
    // T.C = O(n * W)
    // S.C = O(n * W)
    /*
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // no of items
        int n = wt.size();
        
        
        // create dp
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        
        // sabse phela base cases ko initialize kardo (index 0 wala case - 0th item)
        for(int c =0;c<=W;c++){
            if(wt[0] <= c){ // le sakte 
                dp[0][c] = val[0];
            }
            else{ // nahi le sakte
                dp[0][c] = 0;
            }
        }
        
        // ab baki remaining dp bhardo
        for(int index=1;index<n;index++){
            for(int c=0;c<=W;c++){
                
                // humne ek item select kiya aur ek cpacity select kardi ab yaha ab max kitna value ddal sakte
                // option hai humaraa pus hum current item include karsakte ya exclude
                
                int include = 0;
                if(wt[index] <= c){
                    include = val[index] + dp[index-1][c-wt[index]]; 
                }
                
                int exclude = dp[index-1][c];
                
                // inhme se joii max value dega wahi yaha store karenga
                dp[index][c] = max(include, exclude);
            }
        }
        
        // final answer ab last item sleect kara aur max capacity ab baatao kitna max value store kar sakte
        return dp[n-1][W]; 
    }
    */
    
    // Dp - further space optimization
    // T.C = O(n * W)      S.C = O(2 * W)  using two arrays only
    /*
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // no of items
        int n = wt.size();
        
        
        // create two rows
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        
        // sabse phela base cases ko initialize kardo (index 0 wala case - 0th item)
        // fill kardo iss prev mei
        for(int c =0;c<=W;c++){
            if(wt[0] <= c){ // le sakte 
                prev[c] = val[0];
            }
            else{ // nahi le sakte
                prev[c] = 0;
            }
        }
        
        // ab curr row ko nikla lo using prev row
        for(int index=1;index<n;index++){
            for(int c=0;c<=W;c++){
                
                // humne ek item select kiya aur ek cpacity select kardi ab yaha ab max kitna value ddal sakte
                // option hai humaraa pus hum current item include karsakte ya exclude
                
                int include = 0;
                if(wt[index] <= c){
                    include = val[index] + prev[c-wt[index]]; 
                }
                
                int exclude = prev[c];
                
                // inhme se joii max value dega wahi yaha store karenga
                curr[c] = max(include, exclude);
            }
            prev = curr;
        }
        
        // final answer ab last item sleect kara aur max capacity ab baatao kitna max value store kar sakte
        return prev[W]; 
    }
    */
    
    // Dp - further space optimization
    // T.C = O(n * W)    S.C = O(W)  using single array only
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // no of items
        int n = wt.size();
        
        
        // create two rows
        vector<int> curr(W+1,0);
        
        // sabse phela base cases ko initialize kardo (index 0 wala case - 0th item)
        // fill kardo iss curr mei
        for(int c =0;c<=W;c++){
            if(wt[0] <= c){ // le sakte 
                curr[c] = val[0];
            }
            else{ // nahi le sakte
                curr[c] = 0;
            }
        }
        
        // ab curr row ko nikla lo using prev row
        for(int index=1;index<n;index++){
            for(int c=W;c>=0;c--){
                
                // humne ek item select kiya aur ek cpacity select kardi ab yaha ab max kitna value ddal sakte
                // option hai humaraa pus hum current item include karsakte ya exclude
                
                int include = 0;
                if(wt[index] <= c){
                    include = val[index] + curr[c-wt[index]]; 
                }
                
                int exclude = curr[c];
                
                // inhme se joii max value dega wahi yaha store karenga
                curr[c] = max(include, exclude);
            }
        }
        
        // final answer ab last item sleect kara aur max capacity ab baatao kitna max value store kar sakte
        return curr[W]; 
    }
};