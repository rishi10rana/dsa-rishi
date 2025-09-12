class Solution {
public:
    // brute force - TLE
    // T.C = O(n^2)   S.C = O(26)
    /*
    int characterReplacement(string s, int k) {
        // generate all sobstr
        int n = s.size();
        int maxlen = 0;

        for(int i=0;i<n;i++){
            // to track freq of each character
            int hash[26];
            int maxfreq = 0;
            memset(hash, 0 , sizeof(hash));
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxfreq = max(maxfreq, hash[s[j]-'A']);

                // no of converson required
                int change = (j - i + 1) - maxfreq;
                if(change <= k){ // can consider this substr
                    maxlen = max(maxlen, j-i+1);
                }
                else{ // gar kahi condtion violate huii menas isse aage ke substr ans nahi de skate
                    break;
                }
            }
        }

        return maxlen;
    }
    */

    // Sliding Window 
    // T.C = O(n + n) * O(26)         S.C = O(26)
    /*
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l = 0, r = 0, maxfreq = 0;
        int hash[26] = {0};

        while(r < n){
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r]-'A']);

            // check our window is valid or invalid
            while((r-l+1)-maxfreq > k){
                // shrink the window
                hash[s[l]-'A']--;
                // recalculate maxfreq
                maxfreq = 0;
                for(int i=0;i<26;i++){
                    maxfreq = max(maxfreq, hash[i]);
                }
                l++;
            }

            // means window is valid we can take this substr
            if((r-l+1)-maxfreq <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }

        return maxlen;
    }
    */

    // Sliding Window  (further optimize)
    // T.C = O(n)   S.C = O(26)
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        int l = 0, r = 0, maxfreq = 0;
        int hash[26] = {0};

        while(r < n){
            hash[s[r] - 'A']++;
            maxfreq = max(maxfreq, hash[s[r]-'A']);

            // check our window is valid or invalid
            if((r-l+1)-maxfreq > k){
                // shrink the window by only 1 move
                hash[s[l]-'A']--;
                l++;
            }

            // means window is valid or maybe maxlen will not update so we can take this substr
            if((r-l+1)-maxfreq <= k){
                maxlen = max(maxlen, r-l+1);
            }
            r++;
        }

        return maxlen;
    }
};