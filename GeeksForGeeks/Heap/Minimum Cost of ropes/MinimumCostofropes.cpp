class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // min heap
        priority_queue<int, vector<int>, greater<int>> p;
        
        for(int i=0;i<n;i++){
            p.push(arr[i]);
        }
        
        int cost = 0;
        while(p.size() >= 2){
            int rope1 = p.top();
            p.pop();
            
            int rope2 = p.top();
            p.pop();
            
            int newRope = rope1 + rope2;
            cost = cost + newRope;
            p.push(newRope);
        }
        
        return cost;
    }
};