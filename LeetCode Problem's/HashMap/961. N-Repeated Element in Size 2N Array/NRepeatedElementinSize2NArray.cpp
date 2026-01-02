class Solution {
public:
    // My Code
    // T.C = O(n)
    // S.C = O(n)
    /*
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        unordered_map<int, int> mp; // to count freq of each element
        set<int> st; // to count distinct elements
        
        // store freq and find distinct elemtn count
        for(int i=0;i<len;i++){
            st.insert(nums[i]);
            if(mp.contains(nums[i])){
                mp[nums[i]]++;
            }
            else{
                mp[nums[i]] = 1;
            }
        }

        int distinct = st.size();
        int n = distinct - 1; // element which occurs n times
        
        int num = 0;
        // find in map no which occurs n times
        for(auto pair: mp){
            if(pair.second == n){
                num = pair.first;
                break;
            }
        }
        return num;
    }
    */

    // Approach - 1 (Hashmap)
    // T.C = O(n)
    // S.C = O(n)
    /*
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        unordered_map<int, int> mp;
        // store freq occurance of each element in map
        // if we find any element which occurs more than 1 time means that is the no which occurs n time
        // we can observe in question that only one no occurs n times , rest all occurs only 1  times
        for(int i=0;i<len;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                return nums[i];
            }
        }

        return -1;
    }
    */

    // Approach - 1 (HashSet)
    // T.C = O(n)
    // S.C = O(n)
    /*
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        set<int> st;
        // store  element in set
        // if we find any element which is already in set means it is the no which occurs  n times
        // we can observe in question that only one no occurs n times , rest all occurs only 1  times
        for(int i=0;i<len;i++){
            if(st.find(nums[i]) != st.end()){
                return nums[i];
            }
            st.insert(nums[i]);
        }

        return -1;
    }
    */

    // Approach - Bad easy way
    // T.C = O(n)
    // S.C = O(1) as constant space array used
    /*
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        // create an array of size 10001 to store all possibe nums[i] freq
        // koii element jiski freq > 1 milti wahi answer hoga
        int freq[10001];
        memset(freq, 0, sizeof(freq));
        for(int i=0;i<len;i++){
            freq[nums[i]]++;
            if(freq[nums[i]] > 1){
                return nums[i];
            }
        }

        return -1;
    }
    */

    // Nice Approach - Pigeon Hole Principle
    // T.C = O(n)
    // S.C = O(1) True No Space
    int repeatedNTimes(vector<int>& nums) {
        int len = nums.size();

        // the element which repeats n times covers 50% of array
        // as the array size is 2n
        // means inside array their will be atleast one case 
        // always when nums[i] == nums[i-1] OR nums[i] == nums[i-2]
        // that means this nums[i] is the answer

        // one edge case is when array has 4 elements and then repeating element occurs 2 times 
        // but the repeating no is preset in two ends ex -
        // [1,2,3,1] here answer is always nums[2n -1] last element

        for(int i=2;i<len;i++){
            if(nums[i] == nums[i-1] || nums[i] == nums[i-2]){
                return nums[i];
            }
        }

        // means 4 element and repeating at both end case
        return nums[len-1];
    }
};