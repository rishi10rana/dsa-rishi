class Solution {
  public:
    // method 1- sorting 
    // T.c = O(nlogn) + O(n)
    /*
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        
        // sort array in asc
        sort(A, A+N);
        
        long long sum = 0;
        for(long long i=K1;i<K2-1;i++){
            sum = sum + A[i];
        }
        
        return sum;
    }
    */
    
    
    // method - 2 using max heap
    // T.C = k1.logk1 + (n-k1).2logk1 + O(k1) 
    //        + k2.logk2 + (n-k2).2logk2 + O(k2)
    /*
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        
        priority_queue<long long> pq1; // to store first k1 smallest elements
        priority_queue<long long> pq2; // to store first k2-1 smallest elements
        
        // store first k1 elements in pq1
        for(int i=0;i<K1;i++){
            pq1.push(A[i]);
        }
        
        
        // store first k2-1 elements in pq2
        for(int i=0;i<K2-1;i++){
            pq2.push(A[i]);
        }
        
        
        // now mantain only first k1 smallest elements in pq1
        for(int i=K1;i<N;i++){
            if(A[i] < pq1.top()){
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        
        // now maintain only first k2-1 smallest elements in pq2
        for(int i=K2-1;i<N;i++){
            if(A[i] < pq2.top()){
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        // now add the first k1 smallest element and first k2 smallest element
        int sum1 = 0;
        while(!pq1.empty()){
            sum1 = sum1 + pq1.top();
            pq1.pop();
        }
        
        int sum2 = 0;
        while(!pq2.empty()){
            sum2 = sum2 + pq2.top();
            pq2.pop();
        }
        
        
        // required sum
        return sum2 - sum1;
    }
    */
      
    // method 3 - best method - used max heap
    // T.C = O(NlogN) + O(K2 * logN)
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
        
        
        priority_queue<int , vector<int>, greater<int>> pq;
        for(int i=0;i<N;i++){
            pq.push(A[i]);
        }
        
        
        long long sum = 0;
        long long count = 1;
        
        while(count <= K2 && !pq.empty()){
            int element = pq.top();
            pq.pop();
            if(K1 < count && count < K2){
                sum = sum + element;
            }
            count++;
        }
        
        return sum;
    }
};