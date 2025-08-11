// User function Template for C++

class Solution {
  public:
  
    // Greedy Algorithm
    // T.C = O(n)
    // S.C = O(n)
    vector<int> minPartition(int N) {
        // code here
        
        int currency[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int note = 0, i = 0;
        
        vector<int> ans;
        while(N){
            note = N / currency[i];
            while(note--){
                ans.push_back(currency[i]);
            }
            
            // N = N - note*currency[i];
            N = N % currency[i];
            i++;
        }
        
        return ans;
    }
};