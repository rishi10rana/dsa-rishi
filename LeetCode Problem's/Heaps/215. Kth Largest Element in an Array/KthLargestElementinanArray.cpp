class Solution {
public:
    // Method 1 using sorting , sort the array and get the (n-k)index element from last
    // T.C = O(nlogn)
    /*
    int findKthLargest(vector<int>& nums, int k) {
        // sort 
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int kthlargest = nums[n-k];
        return kthlargest;
    }
    */

    // Method 2 - use max heap
    // T.C = O(nlogn) + O(klogn) = O(klogn)
    /*
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();
        // max heap
        priority_queue<int> pq;
        for(auto &num: nums){
            pq.push(num);
        }

        int count = 1;
        int kthlargest = 0;
        while(count <= k && !pq.empty()){
            kthlargest = pq.top();
            pq.pop();
            count++;
        }

        return kthlargest;
    }
    */

    // Method 3 - best method - use min heap
    // T.C = O(klogk) + O(n-k).logk =  O(nlogk)
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> pq; 
        // store first k elemenets in min heap
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }

        // now compare the remaining elements one by one with the top of min heap
        for(int i=k;i<n;i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};