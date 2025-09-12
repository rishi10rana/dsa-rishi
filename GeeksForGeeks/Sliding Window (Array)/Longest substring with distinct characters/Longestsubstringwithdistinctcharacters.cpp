class Solution {
  public:
    
    // Brute force - T.C = O(n^2)  S.C = O(256)
    /*
    int longestUniqueSubstr(string &s) {
        
        int n = s.length();
        // generate all substrings
        
        int maxlength = 0;
        for(int i=0;i<n;i++){
            // to track currently jo hum "i" ko use karke substring bana rahe unhme hum konsa character consider kar chuke hai taki substring wtih repeated character na le
            int hash[256] = {0};
            for(int j=i;j<n;j++){
               if(hash[s[j]]!=0){ // means ab iska aage se jo bhi substring milegi unhe mat consider karo
                   break;
               }
               
               int len = j - i + 1;
               maxlength = max(maxlength, len);
               hash[s[j]] = 1; 
            }
        }
        
        return maxlength;
    }
    */
    
    
    // Sliding Window - T.C = O(n)   S.C = O(256)
    int longestUniqueSubstr(string &s) {
        
        int n = s.length();
        // generate all substrings
        
        // to track konse character hum visit karchuka aur unhe last kaha dekha tha
        int hash[256];
        memset(hash, -1, sizeof(hash)); // initialize all value with -1
        int l=0,r=0; // 2 pointer
        int maxlength = 0;
        
        while(r<n){
            // character already seen hai
            if(hash[s[r]]!=-1){
                if(hash[s[r]] >= l){  // means within window , too update karo "l" ko aage badhao
                    l = hash[s[r]] + 1;
                }
            }
        
            int len = r - l + 1;
            maxlength = max(maxlength, len);
            hash[s[r]] = r; // kaha dekha last uska index store karlo
            r++;
        }
        
        return maxlength;
    }
};
