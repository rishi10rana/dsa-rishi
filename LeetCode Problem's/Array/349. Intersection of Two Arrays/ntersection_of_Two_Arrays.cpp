class Solution {
public:
    // Approach 1 - Use Two Sets T.C = O(m + n) , S>C = O(m + n)
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        int len1 = nums1.size();
        int len2 = nums2.size();

        // set make sures that no duplicates
        unordered_set<int> set1(nums1.begin(),nums1.end()); // store num1 elements
        unordered_set<int> set2; // store answer

        // num2 ka agar koii element set1 me mil jaye to us element ko answer mei add kardo
        for(int &num : nums2){
            if(set1.find(num) != set1.end()){
                set2.insert(num);
            }
        }

        // send result in vector
        // shortcut way to store content of one data structure(stl) in another
        vector<int> result(set2.begin(),set2.end());
        return result;
    }
    */

    // Approach 2 - use only 1 set T.C = O(m + n) , S.C = O(m)
    /*
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        int len1 = nums1.size();
        int len2 = nums2.size();

        // set make sures that no duplicates
        unordered_set<int> set1(nums1.begin(),nums1.end()); // store num1 elements
        vector<int> result; // to store answer

        // num2 ka agar koii element set1 me mil jaye to us element ko answer mei add kardo
        for(int &num : nums2){
            if(set1.find(num) != set1.end()){
                result.push_back(num);
                set1.erase(num); // after use remove that element so that no other element match with it
                // to prevent duplicates 
            }
        }

        return result;
    }
    */

    // Approach 3 - use set and binary search T.C = O(mlogm + n.logm) , S.C = O(n)
    /*
    bool binarySearch(vector<int>& arr, int num){
        int low = 0;
        int high = arr.size()-1;
        int mid = low + (high - low)/2;

        while(low<=high){
            if(arr[mid]==num){
                return true;
            }
            else if(arr[mid]<num){
                low = mid + 1;
            }
            else if(arr[mid]>num){
                high = mid - 1;
            }
            mid = low + (high-low)/2;
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        int len1 = nums1.size();
        int len2 = nums2.size();

        // Sort to apply binary search for searching an element of nums2 in nums1
        sort(nums1.begin(),nums1.end());

        // store without duplicates
        unordered_set<int> set1;

        // num2 ka agar koii element set1 me mil jaye to us element ko answer mei add kardo
        for(int &num : nums2){
            if(binarySearch(nums1,num)){
                set1.insert(num);
            }
        }

        // send answer in vector
        vector<int> result(set1.begin(),set1.end());
        return result;
    }
    */

    // Approach 4 - use sorting and 2 pointer T.C = O(m + n + mlogm + nlogn) , S.C = O(1)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {     
        int len1 = nums1.size();
        int len2 = nums2.size();

        // sort both
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        // maintian two pointer one for eeach array
        int i = 0;
        int j = 0;

        vector<int> result; // answer

        while(i<len1 && j<len2){
            if(nums1[i]==nums2[j]){
                result.push_back(nums1[i]); 

                // To skip duplicates in both num1 and num2
                while(i<(len1 - 1) && nums1[i]==nums1[i+1]){
                    i++;
                }
                while(j<(len2 - 1) && nums2[j]==nums2[j+1]){
                    j++;
                }
                // move both pointers to next element
                i++; 
                j++;
            }
            // matlab nums1[i] kyuki chota hai current nums2[j] , to aage bada do i ko
            else if(nums1[i]<nums2[j]){  
                i++;
            }
            else if(nums1[i]>nums2[j]){ // similarly for this
                j++;
            }
        }

        return result;
    }
};