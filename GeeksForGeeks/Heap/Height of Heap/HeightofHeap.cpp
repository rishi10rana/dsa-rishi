class Solution {
  public:
   // T.C = O(logn)
    int heapHeight(int n, int arr[]) {
        // code here
        
        if(n == 1){
            return 1;
        }
        
        // count the no of times you are dividing n by 2 t hat is the height
        int count = 0;
        while(n > 1){
            n = n/2;
            count++;
        }
        
        return count;
    }
};