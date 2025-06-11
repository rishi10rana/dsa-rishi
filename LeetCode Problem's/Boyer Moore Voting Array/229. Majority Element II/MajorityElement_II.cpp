class Solution {
public:
    // Approach - 1 Bruteforce T.C = O(n^2)
    /*
    vector<int> majorityElement(vector<int>& nums) {
        // store answer
        vector<int> result;
        // sort given list of numbers first
        sort(nums.begin(),nums.end());
        int n = nums.size();

        // this will help us traverse to only distinct elements at a time and skip duplicates
        for(int i=0;i<n;){
            int count = 0;
            for(int j=i;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            // if the count of a no. satisfies condition then add it in answer
            if(count>n/3){
                result.push_back(nums[i]);
            }
            // helps to skip duplicates
            i = i + count;
        }
        return result;
    }
    */
    // Approach 2 - Boyer Moore Voting Algo - T.C = O(n) , S.C = O(1)
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        int n = nums.size();

        // as two majority elements come so take two variables
        int count1 = 0;
        int maj1 = NULL;
        int count2 = 0;
        int maj2 = NULL;

        // traverse each element
        for(int i=0;i<n;i++){
            if(nums[i]==maj1){
                count1++; // maj1 ka count bada do
            }
            else if(nums[i]==maj2){
                count2++; // maj2 ka count bada do
            }
            else if(count1 == 0){
                maj1 = nums[i]; // to maj1 change kardo
                count1 = 1;
            }
            else if(count2 == 0){
                maj2 = nums[i]; // to maj2 change kardo
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        // Verification as we get to values that can be majority but check them by checkimg their count by traversing
        int freq1 = 0;
        int freq2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==maj1){
                freq1++;
            }
            else if(nums[i]==maj2){
                freq2++;
            }
        }

        // add them if true
        if(freq1 > floor(n/3)){
            result.push_back(maj1);
        }
        if(freq2 > floor(n/3)){
            result.push_back(maj2);
        }
        
        return result;
    }
};