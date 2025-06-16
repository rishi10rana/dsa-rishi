class Solution {
public:
    // Approach 1 - Brute force T.C = O(n^2)
    /*
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long sum = nums[i]+nums[j];
                        sum = sum + nums[k];
                        sum = sum + nums[l];
                        if(sum==target){
                            vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
    */

    // Approach 2 - using hashset and set to deal with duplicates
    // T.C = O(n^3 + logm) S.C = O(n) + O(q) * 2
    /*
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st; // store only unique quadruplets

        for(int i=0;i<n;i++){ // to fix 1st element
            for(int j=i+1;j<n;j++){ // to to fix second element
                set<long long> hashset; // used to find fourth if it is present in it 
                for(int k=j+1;k<n;k++){ // choose third element by moving it
                    // we need to use long long to dela with etra large input cases
                    long long sum = nums[i]; 
                    sum += nums[j];
                    sum += nums[k];
                    long long fourth = target - (sum);
                    if(hashset.find(fourth)!=hashset.end()){ // means found fourth
                        vector<int> temp = {nums[i],nums[j],nums[k],(int)fourth};
                        sort(temp.begin(),temp.end()); // sort the individual quadruplet
                        st.insert(temp);
                    }
                    hashset.insert((long long)nums[k]);
                }
            }
        }
        vector<vector<int>> result(st.begin(),st.end());
        return result;
    }
    */

    // Approach 3 - Sorting and 2 Pointer
    // T.C = O(n^2 * n) + O(nlogn) , S.C = O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){ /// fix  first element
            if(i>0 && nums[i]==nums[i-1]){
                continue; // skip duplicates for i
            }
            for(int j=i+1;j<n;j++){ // fix second element
                if(j != (i+1) && nums[j]==nums[j-1]){ // to skip duplicates for j
                    continue;
                }
                // in remaining array use 2 pointer to search other 2 elements
                int k = j+1;
                int l = n-1;
                while(k<l){
                    //t odeal with large input tes tcase use long long
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        // no need to sort temp
                        result.push_back(temp);
                        // deal with duplicates
                        while(k<l && nums[k]==nums[k+1]){ k++;}
                        while(k<l && nums[l]==nums[l-1]){ l--;}
                        k++;
                        l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                }
            }
        }
        return result;
    }
};