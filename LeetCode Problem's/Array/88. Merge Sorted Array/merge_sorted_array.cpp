class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans; // ans ko temporary store karne ke liya
        int i=0,j=0;    // 2 pointer approach use karenga dono array ke element ka track rakhne ke liya

        // compare karenga dono array ke elements ko chota walo ko phela place karenga par ye tabtak hi hoga 
        // jabtak dono mei lemenet present ho compare karne ke liya 
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // To copy remaining elements of nums1[] if any remaining
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        } 
        
        // To copy remaining elements of nums2[] if any remaining
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        // Store the final "ans" to the "nums1" itself
        nums1 = ans;
    }
};