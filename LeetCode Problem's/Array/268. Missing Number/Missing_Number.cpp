class Solution {
public:
    // // Approach 1 - Using an Extra Array , T.C = O(n) , S.C = O(n)
    // int missingNumber(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> check(n+1,0); // to keep track of which element from [0,n] are present in original array

    //     for(int i=0;i<n;i++){
    //         int temp = nums[i];
    //         check[temp]++;  // This temp element is present in "nums" so make the "temp" index in "check" 1
    //     }
    //     int ans = 0;
    //     for(int i=0;i<check.size();i++){ // in "check" array if any value different than 1 (i.e 0) means that index is missing
    //         if(check[i]!=1){
    //             ans = i;
    //         }
    //     }
    //     return ans;
    // }

    // Approach 2 - current element = previous element + 1
    // T.C = O(n) , S.C = O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // We need sorted array for this approach
        sort(nums.begin(),nums.end());

        // if at first 0 not their means 0 missing
        if(nums[0]!=0){
            return 0;
        }
        // if at last element not eequal to n means (n is missing)
        if(nums[n-1]!=n){
            return n;
        }

        int missing = 0;
        // for finding any element missing in main array part
        for(int i=1;i<n;i++){
            // agar (current element != previous element + 1) ka matlab (previous element + 1) missing hai 
            if((nums[i]!=nums[i-1]+1)){ 
                missing = nums[i-1]+1;
                break;
            }
        }
        return missing;
    }
};