class Solution {
public:
    // brute force
    // T.C = O(n^2)    S.C = O(3) at max set size can be 3
    /*
    int numberOfSubstrings(string s) {
        int n = s.length();

        int count = 0;
        // generate all the substrings
        for(int i=0;i<n;i++){
            unordered_set<char> st;
            for(int j=i;j<n;j++){
                st.insert(s[j]);
                // valid substring agar usmei atleast one occurance of all three chracters (a,b,c)
                if(st.size()==3){
                    count++;
                }
                // else select nahi karenga wo substring
            }
        }

        return count;
    }
    */

    // Sliding Window
    // T.C = O(n) + O(n) = O(2n)  // S.C = O(3) at max 3 char jo sakte at max 
    int solve(string &s, int k){
        int n = s.length();
        int l = 0, r = 0, ans = 0;
        unordered_map<char, int> mp; // (char , freq)

        while(r < n){
            mp[s[r]]++;
            while(mp.size() > k){
                // shrink the window
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
            // means window safe hai substr consider kar sakte
            if(mp.size() <= k){ // jitna uss substring ki lenth hogi utne hi substr hum consider kar sakte and thse all substr end at "r index"
                ans = ans + (r-l+1);
            }
            r++;
        }

        return ans;
    }
    
    int numberOfSubstrings(string s) {

        // find karlo all substr jinke andar distinct char 3 ya 3 se kam hai
        // and find all substr jinki distinct chars 2 ya 2 se kam hai

        //  substr jinke andar distinct cjars 2 ya 2 se kam hai wo aready included honge in all substr jinki andar distinct chars 3 ya 3 se kam hai

        // to get no of substr jinke andar distinct chars exactly 3 hoo
        return solve(s, 3) - solve(s, 2);
    }
};