// User function template for C++
class Solution {
  public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    
    
    // T.C = O(n) , S.C = O(1)
    int maxRepeating(int k, vector<int>& arr) {
        // code here
        
        unordered_map<int,int> mp;
        int maxFreq = 0;
        
        // store occurance of each element in map and also store max time ana element can occur
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
            maxFreq = max(maxFreq, mp[arr[i]]);
        }
        
        // find all elemetns which occur max time from it the ans is the element which has smallest value
        int ans = INT_MAX;
        
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]] == maxFreq){
                // can be answer
                ans = min(ans, arr[i]);
            }
        }
        return ans;
    }
};