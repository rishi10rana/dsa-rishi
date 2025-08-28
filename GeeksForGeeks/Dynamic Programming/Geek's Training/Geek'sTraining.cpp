class Solution {
  public:
    // Recursive Approach - TLE
    // T.C = exponential
    /*
    int f(int day, int last, vector<vector<int>> &arr){
        // base case
        // 0th day mei konsa task karu taki max point mila
        if(day==0){
            int maxii = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxii = max(maxii, arr[0][task]);
                }
            }
            
            return maxii;
        }
        
        // now for each day what task we can do
        int maxii = 0;
        for(int task=0;task<3; task++){
            if(task!=last){
                int point = arr[day][task] + f(day-1, task, arr);
                maxii = max(maxii, point); // sare task mei se jo max points lakar dega wahi store karna aur upar bhejdena
            }
        }
        
        return maxii;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        
        // no of days
        int n = arr.size();
        
        // initially passing 3 means isse phela koo bhi task nahi kiya abhi
        return f(n-1, 3, arr);
    }
    */
    

    // DP Memonization
    // T.C = O(n * 4)*3    S.C = O(n * 4) + O(n)
    /*
    int f(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp){
        // base case
        // 0th day mei konsa task karu taki max point mila
        if(day==0){
            int maxii = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxii = max(maxii, arr[0][task]);
                }
            }
            
            return maxii;
        }
        
        // check karolo ki ye ubproblem already solved to nahi
        if(dp[day][last]!=-1){
            return dp[day][last];
        }
        
        // now for each day what task we can do
        int maxii = 0;
        for(int task=0;task<3; task++){
            if(task!=last){
                int point = arr[day][task] + f(day-1, task, arr, dp);
                maxii = max(maxii, point); // sare task mei se jo max points lakar dega wahi store karna aur upar bhejdena
            }
        }
        
        return dp[day][last] = maxii;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        
        // no of days
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        // initially passing 3 means isse phela koo bhi task nahi kiya abhi
        return f(n-1, 3, arr, dp);
    }
    */
    
    
    // DP - Tabulation
    // T.C = O(n * 4 * 3)    S.C = O(n * 4)
    /*
    int maximumPoints(vector<vector<int>>& arr) {
        
        // no of days
        int n = arr.size();
        
        vector<vector<int>> dp(n, vector<int>(4, 0));
        
        // sabse phela base case bhar do for 0th day
        for(int last=0;last<4;last++){
            int maxii = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxii = max(maxii, arr[0][task]);
                }
            }
            dp[0][last] = maxii;
        }
        
        // ab remaing dp bhar do
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                int maxii = 0;
                
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int point = arr[day][task] + dp[day-1][task];
                        maxii = max(maxii, point);
                    }
                }
                dp[day][last] = maxii;
            }
        }
        
        
        // final answer dedo ki nth day par jab tumne koii bhi task nahi select kiya tha phela(3) tum max kint apoints mil sakte
        return dp[n-1][3];
    }
    */
    
    
    // DP - Space Optimization
    // T.C = O(n * 4 * 3)    S.C = O(4) -> 2 arrays of size 4
    int maximumPoints(vector<vector<int>>& arr) {
        
        // no of days
        int n = arr.size();
        
        vector<int> prev(4, 0);
        
        // sabse phela base case bhar do for 0th day
        for(int last=0;last<4;last++){
            int maxii = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    maxii = max(maxii, arr[0][task]);
                }
            }
            prev[last] = maxii;
        }
        
        // ab remaing dp bhar do
        for(int day=1;day<n;day++){
            
            vector<int> curr(4, 0);
            for(int last=0;last<4;last++){
                int maxii = 0;
                for(int task=0;task<3;task++){
                    if(task!=last){
                        int point = arr[day][task] + prev[task];
                        maxii = max(maxii, point);
                    }
                }
                curr[last] = maxii;
            }
            prev = curr;
        }
        
        
        // final answer dedo ki nth day par jab tumne koii bhi task nahi select kiya tha phela(3) tum max kint apoints mil sakte
        return prev[3];
    }
};