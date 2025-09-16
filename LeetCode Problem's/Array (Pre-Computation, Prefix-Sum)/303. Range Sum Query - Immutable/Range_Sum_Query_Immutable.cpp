class NumArray {
public:
    /*
    // Approach - 1 : T.C = O(n * Q) Q = no of queries 
    // Instance Variable different for each object - to store i/p array
    vector<int> arr;

    // Initialize the value in this instance variabe from the given input
    NumArray(vector<int>& nums) {
        // store nums in arr
        this->arr = nums;
    }   
    
    int sumRange(int left, int right) {
        // // use 2 pointer like approrach 
        // int sum = 0;
        // while(left<=right){
        //     sum = sum + this->arr[left];
        //     left++; // only move one by one to reach right and acess all elements in between one by one
        // }

        // or use accumulate function - to calculate sum for a range
        int sum = accumulate(this->arr.begin()+left,this->arr.begin()+right+1,0);
        return sum;
    }
    */

    // Approach - 2 : Prefix Sum - T.C = O(n x 1)
    vector<int> arr;
    vector<int> prefixSum; 

    // Initialize the value in this instance variabe from the given input
    NumArray(vector<int>& nums) {
        // store nums in arr
        this->arr = nums;
        int n = nums.size();
        prefixSum.resize(n);// used to re set the vector size
        calculatePrefix(nums);
    }   
    // store prefeix sum
    void calculatePrefix(vector<int>& nums){
        this->prefixSum[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            prefixSum[i] = nums[i] + prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        // To deal with case if (left-1)<0
        if(left-1>=0){
            return prefixSum[right] - prefixSum[left-1];
        }
        return prefixSum[right];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */