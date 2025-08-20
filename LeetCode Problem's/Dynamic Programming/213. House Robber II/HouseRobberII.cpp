class Solution {
public:
    // Apprach - DP bottom up -Using Space Optimization 
    // T.C = O(n)  S.C = O(2n)
    /*
    int robbery(vector<int>& nums){
        // will use 3 variable concept here
        // handle edge case size 1 or 2
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        int curr;
        int prev1 = max(nums[0], nums[1]), prev2 = nums[0];

        // find karo ab max kitna cash chura sakte
        for(int i=2;i<nums.size();i++){
            curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
    
    int rob(vector<int>& nums) {
        
        // no of houses
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        vector<int> arr1(n-1, -1);
        vector<int> arr2(n-1, -1);

        // phela array mei 0th index hoga par last index mat include karo
        for(int i=0;i<n-1;i++){
            arr1[i] = nums[i];
        }

        // dusra array mei last index hoga par 0th index mat include karo
        for(int i=1;i<n;i++){
            arr2[i-1] = nums[i];
        }

        int curr1 = robbery(arr1);
        int curr2 = robbery(arr2);

        return max(curr1, curr2);
    }
    */

    // Approach - correct way to do it no extra array required
    // T.C = O(n) , S.C = O(1)
    int rob(vector<int>& nums) {
        
        // no of houses
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }

        int prev1 = max(nums[0], nums[1]), prev2 = nums[0];
        int curr1 = prev1;

        // find karo ab max kitna cash chura sakte
        // case 1 - 0th ko liya par last index nahi liya
        for(int i=2;i<n-1;i++){
            curr1 = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr1;
        }

        prev1 = max(nums[1], nums[2]), prev2 = nums[1];
        int curr2 = prev1;

        // find karo ab max kitna cash chura sakte
        // case 2 - last index ko liya par 0th nahi liya
        for(int i=3;i<n;i++){
            curr2 = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr2;
        }

        return max(curr1, curr2);
    }
};