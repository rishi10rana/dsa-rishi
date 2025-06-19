class Solution {
public:
    // Approach - i used algorithm to calculate longest possible prefix suffix length from the KMP algo
    // T.C = O(n) , S.C = o(n)
    string longestPrefix(string s) {
        int n = s.length();

        // LPS - array to store the longest possible prefix which is also suffix upto ith index for string "s"
        vector<int> LPS(n, 0);
        
        int length = 0; // to maintain the length of longest happy prefix that we could get till last index
        // as here we need longest happy prefix which is also suffix so we consider length we got a last index
        LPS[0] = 0;
        
        int i = 1;
        while(i < n){ // traverse to calculate LPs till eash ith index
            if(s[i]==s[length]){
                length++;
                LPS[i] = length;
                i++;
            }
            else{ // means not match
                if(length!=0){ // check for LPS by reducing length
                    length = LPS[length-1];
                }
                else{ // means till this ith index we cant get any LPS so;
                    LPS[i] = 0;
                    i++;
                }
            }
        }

        // using length of happy prefix we found we can either take no of charcters = length
        // from either prefix (from beginning) of "s" or from sufix (from end) 
        string result = "";
        i = 0;
        while(i < length){
            result.push_back(s[i]);
            i++;
        }
        return result;
    }
};