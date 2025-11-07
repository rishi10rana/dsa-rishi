class KthLargest {
public:
    // will use min heap and maintain its size as k
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // fill just first k elements in min heap
        for(auto &num: nums){
            pq.push(num);

            //check karte raho agar size k badh gaya to pop kardo min elements ko unki zarorat nahi
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    // T.C= O(klogk) + O(2M * logk)
    // let M be no of add calls
    int add(int val) {
        // add element in heap
        pq.push(val);

        // check karo size k se jyada to nahi ho gaya
        if(pq.size() > k){
            pq.pop();
        }

        // top element hi kth largest hota
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */