class Solution {
public:
    // Approach - Sliding Window with Set T.C = O(n) , S.C = O(n)
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // To maintainthat n duplicates occusr in a subarray
        unordered_set<int> st;
        
        long long result = 0;
        long long sum = 0;
        
        int i = 0;
        int j = 0;
        while(j < n){
            // check if the element already present in current window so remove all till that element
            // is not removed from set
            while(st.find(nums[j])!=st.end()){
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            sum = sum + nums[j];
            st.insert(nums[j]);
            // if window size reached then update the result and shrink the window
            if(j-i+1 == k){
                result = max(result,sum);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }

    // Approach - Sliding Window with Map T.C = O(n) S.C = O(n)
    /*
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n= nums.size();

        unordered_map<int, int> mp; // stores element->index mapping
        
        long long result = 0;
        long long sum = 0;

        int i = 0;
        int j = 0;
        while(j < n){
            // check if element already prsent in window and map
            while(mp.find(nums[j])!=mp.end()){
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }

            sum += nums[j];
            mp[nums[j]] = j;
            
            // window max size reached , so update the result
            if(j-i+1 == k){
                result = max(result,sum);
                sum -= nums[i];
                mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return result;
    }
    */
};