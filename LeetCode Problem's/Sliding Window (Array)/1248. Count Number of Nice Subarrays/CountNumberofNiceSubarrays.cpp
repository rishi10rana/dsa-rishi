class Solution {
public:
    // Brute force
    // T.C = O(n^2)     S.C = O(k+1)  at most stored k +1    worst case mei saree odd numbers
    /*
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;
        // generate all the subarrays
        for(int i=0;i<n;i++){
            multiset<int> st;
            for(int j=i;j<n;j++){
                // ye jo element hum le rahe iss subarray mei agar wo odd hai to usko yaad rakhne ke liya multi set mei daaldo
                if(nums[j]%2==1) st.insert(nums[j]);

                // check karlo agar no of odds in a subarray = k
                if(st.size()==k){
                    count++;
                }
                else if(st.size() > k){ // jayda ho rahe to aage mat check karo
                    break;
                }
            }
        }

        return count;
    }
    */


    


    // We can use all approaches of question - binary sum with sum
    // appraoch 1 - brute forve, T.C = O(n^2)  S.C = O(1)
    // approach 2 - prefix sum concept,   T.C = O(n) + O(1)   S.C = O(n)   


    // approach - 3 Sliding Window
    // T.C = 2 * O(2n)     S.C = O(1) 
    int solve(vector<int> &nums, int k){
        // ye fucntin humaraa count karta no of subarrays jinka sum<=k hai
        if(k < 0){
            return 0;
        }
        int n = nums.size();

        int l = 0, r = 0, sum = 0;
        int count = 0;
        while(r < n){
            sum = sum + nums[r];
            // check sum kahi k se jayda to nahi jaa raha (invalid window)
            while(sum > k){
                // shrink thw window
                sum = sum - nums[l];
                l++;
            }
            // means sab sahi hai sum <=k
            count = count + (r-l+1);
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
  
        // saree even nums ko 0 banado
        // saree odd nums ko 1 banado

        for(int i=0;i<n;i++){
            if(nums[i]%2==1){ // odd
                nums[i] = 1;
            }
            else{ // even
                nums[i] = 0;
            }
        }

        // now apply kardo conce[t to find the subarray jiska sum == k  (here sum will be count of all odds numbers kyuki odd numbers ko hi sirf 1 bana rakha baki even nos to sab 0 hai)

        // use sliding window
        return solve(nums, k) - solve(nums, k-1);
    }
};