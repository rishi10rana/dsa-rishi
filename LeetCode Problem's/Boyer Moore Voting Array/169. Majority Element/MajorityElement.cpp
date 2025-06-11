class Solution {
public:
    // Approach 1- Brute Force , T.C = O(n^2) , S.C = O(1)
    /*
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // select one element at a time
        for(int i=0;i<n;i++){
            int count = 0;
            // and calculate its occurance in array
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            // if any element found which satisfies ondition for majority element immediately return it
            if(count > n/2){
                return nums[i];
            }
        }
        // majority element will always exist as said in question this is just , as int function 
        // need to return something as part of syntaxz
        return -1;
    }
    */

    // Approach 2 - Boyer Moore Voting algorithm T.C = O(n) , S.C = O(1)
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // maintain a candidate (that can be majority element) and count
        int count = 0;
        int maj = NULL;

        // traverse each element
        for(int i=0;i<n;i++){
            if(nums[i]==maj){ 
                count++;
            }
            else if(count == 0){ // to matlab maj element ko change kardo ab shayd ye wala ho sakta
                maj = nums[i];
                count = 1; 
            }
            else{ 
                count--;
            }
        }
        // Verification step no required kyuki ek hi majority niklega humesha
        return maj;
    }
};