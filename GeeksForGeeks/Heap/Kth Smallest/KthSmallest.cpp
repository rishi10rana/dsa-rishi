class Solution {
  public:
    // Method 1 sort the array and find the kth (k-1)index element from start
    // T.C = O(nlogn)
    /*
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int min = arr[k-1];
        return min;
    }
    */
    
    // Method 2 using the min heap to get smallest element each time
    // T.C = O(nlogn) + O(k * logn) = O(klogn)
    /*
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &num: arr){
            pq.push(num);
        }
        
        int count = 1;
        int smallest = 0;
        while(count<=k && !pq.empty()){
            smallest = pq.top();
            pq.pop();
            count++;
        }
            
        return smallest;
    }
    */
    
    
    // Method 3 - Most Optimized (use max heap)
    // T.C = O(klogk) + O((n-k).logk) = O(nlogk)
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        
        priority_queue<int> pq;
        // initially put first k elements in max heap
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k;i<n;i++){
            // compare the new element with top
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        // at end the top element in max heap will be the kth smallest element
        return pq.top();
    }
};