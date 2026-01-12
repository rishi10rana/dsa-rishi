class Solution {
public:
    // simple use - frequency map
    //  T.C = O(n)
    // S.C = O(n) due to map
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> result;
        unordered_map<int, int> mp;
        
        int n = changed.size();
        // agar total size odd hai means koi ek element ka double ya half exist nahi karta 
        // means this is not a valid changd array
        if(n % 2 != 0){ // odd
            return {};
        }
        
        // sort
        sort(changed.begin(), changed.end());

        // freq count
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }

        // another traverse to find origianal array
        for(int i=0;i<n;i++){
            if(mp.find(changed[i]) != mp.end() && mp[changed[i]] == 0){ // means considered this no.
                continue; // skip it
            }
            else if (mp.find(changed[i] * 2) == mp.end() || mp[changed[i] * 2] == 0){ // means is element ka double naa half exist karta
                return {};
            }
            // means double exists
            mp[changed[i]]--; // selected no ki freq decrement kardo   
            // also uske double ki freq ko bhi decrement kardo as considered both of them
            mp[changed[i] * 2]--;
            // add as this element double exist
            result.push_back(changed[i]);
        }
        return result;
    }
};