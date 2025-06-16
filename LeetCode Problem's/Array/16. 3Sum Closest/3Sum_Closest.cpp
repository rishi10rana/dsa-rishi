class Solution {
public:
    // Approach - sorting and 2 pointers
    // T.C = O(n^2 + nlogn) , S.C = O(1)
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        // initally set large to have maximum difference or gap in numberline
        int minDifference = INT_MAX;
        
        // no need to set it to this , we can also set 0
        int closestSum = nums[0] + nums[1] + nums[2];;

        for(int i=0;i<n-2;i++){ // fix one element
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(target-sum) < minDifference){ 
                    // update to the sum which gives lowest or minnmum difference
                    closestSum = sum;
                    minDifference = abs(target-sum);
                }
                // apply same 2 sum approach
                // sum == target no need to deal with it 
                if(sum<target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return closestSum;
    }
};