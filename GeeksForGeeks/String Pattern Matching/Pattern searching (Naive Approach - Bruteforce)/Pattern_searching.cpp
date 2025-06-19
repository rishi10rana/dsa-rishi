// User function Template for C++
class Solution {
  public:
    // Approach - Naive Approach T.C = O(n^2)
    bool searchPattern(string& txt, string& pat) {
        int n = txt.length(); // len of text
        int m = pat.length();   // len of pattern
        
        
        // move "i" aone at time to check whetehr pattern can exist by considering each character
        for(int i=0;i<=n-m;i++){
            int j;
            for(j=0;j<m;j++){ // for each "i" , check pattern from j=0-->m-1
                if(txt[i + j]!=pat[j]){
                    break;
                }
            }
            // means pattern found
            if(j==m){
                    return true;
                }
        }
        // means not found
        return false;
    }
};
