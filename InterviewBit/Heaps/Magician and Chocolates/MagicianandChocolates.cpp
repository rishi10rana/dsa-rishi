// T.C = O(A * 2logn)
int Solution::nchoc(int A, vector<int> &B) {
    // no of bags
    int n = B.size(); 
    
    // create a max heap
    priority_queue<int> pq;
    
    for(int i=0;i<n;i++){
        pq.push(B[i]);
    }
    
    int unit = 1;
    long long result = 0;
    
    while(unit <= A && !pq.empty()){
        int chocalate = pq.top();
        pq.pop();
        result = (result + chocalate) % 1000000007;
        
        int newChocalate = floor(chocalate/2);
        if(newChocalate) pq.push(newChocalate);
        unit++;
    }
    
    return result;
}
