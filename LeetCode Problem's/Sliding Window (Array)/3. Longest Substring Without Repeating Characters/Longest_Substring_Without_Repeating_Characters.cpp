class Solution {
public:
    // Approach - 2 Pointer and Siding Window T.C = O(n) , S.C = O(256)
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        
        // a hash array to maintian check of what character occured at what latest index
        // as 256 chracter in ASCII
        int hash[256];
        for(int i=0;i<256;i++){ // initialize
            hash[i] = -1;
        }
        // or use fill fucntion with array
        // fill(hash, hash + 256,-1);

        int l = 0 , r = 0;
        // keep maxLength = 0 for the case with empty string
        int maxLength = 0; 

        while(r < n){
            if(hash[s[r]] != -1){ // means character is present in hash array
                if(hash[s[r]] >= l){ // means current selected substring mei hai
                    l = hash[s[r]] + 1; // means move by index forward form that location
                }
                // do nothing if character not in current selected substring
            }
            int len = r - l + 1; // length of selected substring
            maxLength = max(maxLength,len);
            hash[s[r]] = r; // update the index at where this chracter may be found last
            r++;
        }
        // note: in the hash array we are passing a chracter instead of index to access becasue 
        // the chracter will be automatically converetd to its ascii corresponding value

        return maxLength;
    }
};