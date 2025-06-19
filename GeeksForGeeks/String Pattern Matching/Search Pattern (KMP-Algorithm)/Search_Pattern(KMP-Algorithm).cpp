class Solution {
  public:
    // Approach - KMP - Knuth-Morris-Pratt Pattern Matching Algoithm
    // T.C = O(n + m) , S.C = O(m)
    void computeLPS(string &pat,vector<int> &LPS){
        int m = pat.length();
        int length = 0; // store length of the last longest possible prefix sufix equal
        
        LPS[0] = 0; // we know always
        
        int i = 1;
        while( i < m){
            if(pat[i] == pat[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{ // not matched
                if(length != 0){
                    length = LPS[length - 1];
                }
                else{ // means we cant find LPS so for this "i"
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
  
    vector<int> search(string& pat, string& txt) {
        // code here
        int n = txt.length();
        int m = pat.length();
        
        // result indexes
        vector<int> result;
        
        // LPS -  create an LPS array which stores the length of the longest possible prefix with the sufix equal for the pattern
        // LPS[i] = length of longest prefix and sufix equal from [0..i]
        vector<int> LPS(n,0);
        computeLPS(pat,LPS);
        
        // Apply KMP Algorithm
        int i = 0;
        int j = 0;
        while(i < n){ // run till whole text not traversed
            if(txt[i] == pat[j]){
                i++;
                j++;
            }
            if(j==m){ // found pattern
                result.push_back(i-j); // pass the index
                j = LPS[j-1];
            }
            else if(txt[i] != pat[j]){
                if(j!=0){
                    j = LPS[j-1];
                }
                else{ // j==0
                    i++;
                }
            }
        }
        // answer
        return result;
    }
};