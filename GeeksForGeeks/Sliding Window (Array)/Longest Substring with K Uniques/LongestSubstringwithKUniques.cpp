class Solution {
  public:
    // Bruteforce Approach
    // T.C = O(n^2)  S.C = O(k)
    /*
    int longestKSubstr(string &s, int k) {
        
        int n = s.length();
        int maxlen = 0;
        
        // generate all the substrings 
        for(int i=0;i<n;i++){
            set<char> st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                // check karo agar k se jyada characters ai to condn violate hai to iska aage ke substr bhi consider mat karna
                if(st.size() > k){
                    break;
                }
                // substr with exactly k distinct characters so consider this substr
                else if(st.size()==k){
                    int len = j - i + 1;
                    maxlen = max(maxlen, len);
                }
                else{ // means st.size() < k
                    // skip thses substr also
                    continue;
                }
            }
        }
        
        // edge case 
        // mili hi nahi koii substr
        if(maxlen==0){
            return -1;
        }
        return maxlen;
    }
    */
    
    
    // Optimal Approach - Sliding Window
    // T.C = O(n + n) = O(2n)   S.C = O(k) 
    /*
    int longestKSubstr(string &s, int k) {
        
        int n = s.length();
        int l = 0, r = 0, maxlen = 0;
        map<char, int> mp;
        
        while(r < n){
            // consider this in window
            mp[s[r]]++;
            // check kahi window mei k se kam distinct chars to nahi
            // gar aisa hai dont consider that substr or window
            if(mp.size() < k){
                r++;
                continue;
            }
            
            // check karo kahi window condition violate to nahi kar raha kahi k se jyada distinct chars hogaye
            if(mp.size() > k){
                // shrink the window until it becomes valid
                while(mp.size() > k){
                    mp[s[l]]--;
                    if(mp[s[l]]==0){
                        mp.erase(s[l]);
                    }
                    l++;
                }
            }
            
            // agar sabkhuch sahi matalb window or substr mei exactly k distinct chars
            // so consider that substr
            if(mp.size()==k){
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        
        // edeg case agar koii substr mili hi nahi
        if(maxlen==0){
            return -1;
        }
        return maxlen;
    }
    */

    // Most Optimal  - Sliding Window
    // T.C = O(n)   S.C = O(k) 
    int longestKSubstr(string &s, int k) {
        
        int n = s.length();
        int l = 0, r = 0, maxlen = 0;
        map<char, int> mp;
        
        while(r < n){
            // consider this in window
            mp[s[r]]++;
            // check kahi window mei k se kam distinct chars to nahi
            // gar aisa hai dont consider that substr or window
            if(mp.size() < k){
                r++;
                continue;
            }
            
            // check karo kahi window condition violate to nahi kar raha kahi k se jyada distinct chars hogaye
            if(mp.size() > k){
                // shrink the window by only 1 move from left
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            
            // agar sabkhuch sahi matalb window or substr mei exactly k distinct chars
            // so consider that substr
            if(mp.size()==k){
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        
        // edeg case agar koii substr mili hi nahi
        if(maxlen==0){
            return -1;
        }
        return maxlen;
    }
};