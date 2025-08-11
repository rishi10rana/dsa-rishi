// User function Template for C++

class Solution {
  public:
    // Greedy
    // T.C = O(logR)           base = 10
    // S.C = O(1)
    int rotationCount(long long R, long long D) {
        // code here
        
        int ans = 0;
        int first, second; // to store the digit of R and D one by one
        
        while(R!=0){
            first = R % 10;
            second = D % 10;
            
            // minimum move select karo to get desired number either clockwise or anticlockwise
            ans = ans + min(abs(first-second), 10 - abs(first-second));
            
            R = R / 10;
            D = D / 10;
        }
        
        return ans;
    }
};