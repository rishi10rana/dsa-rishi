class Solution {
public:
    // Approach - Using 2 Sum Logic and 3 Pointers
    // T.C = o(n^2)
    // To store answer
    vector<vector<int>> result;
    void twoSum(vector<int>& nums,int target,int i,int j){ // O(n)
        while(i<j){
            if(i<j && nums[i] + nums[j] < target){
                i++;
            }
            else if(i<j && nums[i] + nums[j] > target){
                j--;
            }
            else{ // means nums[i] + nums[j] == target
            // skips duplicates only if we got target
                while(i<j && nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                // add the got triplet in result
                result.push_back({-target,nums[i],nums[j]});

                // if we got triplet then move i and j
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        // their should be atleast three elements to get triplet
        if(n < 3){
            return {};
        }

        result.clear();

        // sort the array first
        sort(nums.begin(),nums.end());

        // choosing the first element in triplet
        // we are going till (n-2) and end also their should be atleast 2 lements remianing for 2 sum to get remaining two elements
        for(int i=0;i<n-2;i++){ // O(n)
            // to prevent choosing duplicates for n1
            if(i> 0 && nums[i] == nums[i-1]){
                continue;
            }
            else{
                int n1 = nums[i];
                int target = -n1;
                // using two sum logic to find other two remaining elements
                twoSum(nums,target,i+1,n-1);
            }
        }
        return result;
    }
};