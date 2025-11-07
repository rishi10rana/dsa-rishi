// Mac heap problem
// T.C = O(B * 2logn) = O(B.logn)
int Solution::solve(vector<int> &A, int B) {
    
    // no of rows (each rows has vacant seats)
    int n = A.size();
    
    // max heap
    priority_queue<int> pq;
    for(int i=0;i<n;i++){
        pq.push(A[i]);
    }
    
    int profit = 0;
    while(B && !pq.empty()){
        // 1 max value seat ticket picked for a person
        int seat = pq.top();
        pq.pop();
        profit = profit + seat;
        
        // no of seats remain in that row
        int newSeats = seat - 1;
        if(newSeats) pq.push(newSeats);
        B--;
    }
    
    return profit;
}
