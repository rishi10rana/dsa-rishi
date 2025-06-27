class Solution {
  public:
    // Approach 1 
    /*
    bool checkKthBit(int n, int k) {
        int count = 0;
        // move to that kth bit
        while(count < k){
            n = n >> 1;
            count++;
        }
        // check
        if(n&1==1){
            return true;
        }
        return false;
    }
    */
  
    // Approach 2
    bool checkKthBit(int n, int k) {
        return (n & (1<<k)) != 0;
    }
};