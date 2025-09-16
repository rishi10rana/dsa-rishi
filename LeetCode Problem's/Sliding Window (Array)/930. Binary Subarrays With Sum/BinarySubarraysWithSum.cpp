class Solution {
public:
    // bruteforce method
    // T.C = O(n^2)    S.C = O(1)
    /*
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;

        // generate all the subarrays using 2 for loop
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum = sum + nums[j];
                if(sum==goal){ // consider this subarray as it gives goal
                    count++;
                }
            }
        }

        return count;
    }
    */

    // prefix sum concept
    // T.C = O(n) * O(1)     S.C = O(n) as tworst case each index have different prefix sum
    /*
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> map;  // (prefixSum, count = means pheal kitna bar ye prefix sum mil chuka hai hume)
        map[0] = 1;
        int prefixSum = 0, cnt = 0;
        for(int i=0;i<n;i++){
            prefixSum = prefixSum + nums[i];
            // subarays jinka sum (prefisSuum -k)
            int remove = prefixSum - goal;
            // jitna subarrays mila utne hi subarrays jinka sum k hoga wo exist karenga
            cnt = cnt + map[remove];
            // store yaha tak prefix sum kya mila
            map[prefixSum]++;
        }

        return cnt;
    }
    */

    // Sliding window
    // T.C = 2 * O(2n)      S.C = O(1)
    int solve(vector<int> &nums, int goal){
        if(goal < 0 ){ // aisa koi subarray mil hin hai sakte
            return 0;
        }

        int n = nums.size();
        int l = 0, r = 0, sum = 0;
        int ans = 0;
        while(r < n){
            sum = sum + nums[r];
            while(sum > goal){
                // shrink kardo piche se jab tak condition fhirse se safe na ho jaye
                sum = sum - nums[l];
                l = l + 1;
            }
            // means sab safe hai sum <= goal chal raha
            // hum usse subarray mei currenly window respresent kar raha uske length barabar hum utne subarrays ko pick kar sakte usmei se
            ans = ans + (r-l+1);
            r = r + 1;
        }

        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {  

        // dekho humne nikal all subarays jinka sum<=goal  hai
        // agar hum nikal le wo saree subarrays jinka sum<=goal-1
        // means subarrays jinka sum<=goal-1      wo bhi included honge in in subarrays jinka sum<=goal hai
        // too jinka sum<=goal     mei se agar jinka sum<=goal-1    kardiya to hum mil jayega wo subarays jinka sum==goal hai

        // This will also handle edge cases like goal < 0      or      all num 0s and goal >= 0
        return solve(nums, goal) - solve(nums, goal-1);
    }
};