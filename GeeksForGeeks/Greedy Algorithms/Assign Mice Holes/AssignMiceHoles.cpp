class Solution {
  public:
    // Greedy Algorithm
    // T.C = O(2nlogn) + O(n) = O(nlogn)
    // S.C = O(1)
    int assignMiceHoles(int N, int M[], int H[]) {
        // code here
        
        // sort the mouse and hole position arrays
        sort(M,M+N);
        sort(H,H+N);
        
        
        int ans = INT_MIN;
        // fhir same index wala mouse ko same index wale hole me place karo
        for(int i=0;i<N;i++){
            ans = max(ans, abs(M[i] - H[i]));
        }
        
        return ans;
    }
};