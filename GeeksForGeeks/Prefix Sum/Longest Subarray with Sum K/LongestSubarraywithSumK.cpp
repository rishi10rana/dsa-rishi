class Solution {
  public:
    // Approach 1: Prefix Sum 
    // T.C = O(n)
    // S.C = O(n)
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int prefixSum = 0;
        int maxSubArrayLen = 0;
        for(int i=0;i<n;i++){
            prefixSum = prefixSum + arr[i];
            int removedSum = prefixSum - k;
            if(mp.find(removedSum) != mp.end()){
                int len = i - mp[removedSum];
                maxSubArrayLen = max(maxSubArrayLen, len);
            }
            if(mp.find(prefixSum) == mp.end()){
               mp[prefixSum] = i;
            }
        }
        
        return maxSubArrayLen;
    }
};