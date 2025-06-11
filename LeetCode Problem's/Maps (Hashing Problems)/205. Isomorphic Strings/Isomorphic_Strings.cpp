class Solution {
public:
    // Approach - O(n)
    /*
    bool isIsomorphic(string s, string t) {
        // ued to map 1 character of "s" --> to 1 character of "t"
        unordered_map<char, char> mp;
        // to keep track of what character we have mapped to (so that we do not map any another character again to them)
        set<char> used;

        int len1 = s.length();
        int len2 = t.length();
        if(len1!=len2){ // optional as already len are equal - given
            return false; // length doesnt matchh means they cant be isomorphic
        }

        // traverse one charcter from each at a time
        for(int i=0;i<len1;i++){
            // safe case - charcters from both "s" and "t" not present , so add them in map and set
            // if s[i] already present in map then dont add them.
            // if t[i] aleready present in set dont add them.
            if(mp.find(s[i]) == mp.end() && used.find(t[i]) == used.end()){
                used.insert(t[i]);
                mp[s[i]] = t[i];
            }
            // to deal with condition if s[i] present in map then check it is map to correct character t[i] or not.
            // this cae will also deal with if element no present in map but cant be mapped to the given t[i] as this t[i] is already mapped to some one.
            // if a ky not found in map it gives value 0.
            else if(mp[s[i]] != t[i]){
                return false; // if not means now it cant be isomorphic
            }
        }

        // means nothing goes wrong then it is isomorphic
        return true;
    }
    */

    // Approach 2 - use two maps , T.C = O(n)
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1; // map s -> t
        unordered_map<char, char> mp2; // map t -> s

        int n = s.length(); // same length sting as given

        // traverse both string together
        for(int i=0;i<n;i++){
            // case 1 - charecter  s[i] in mp1 preent but not mapped to correct t[i]
            // case 2 - chracter s[i] not present in map , but t[i] present mp2 but not mapped to corret s[i]
            if(mp1.find(s[i]) != mp1.end() && mp1[s[i]] != t[i] || mp2.find(t[i]) != mp2.end() && mp2[t[i]] != s[i]){
                return false;
            }

            // safe case add them
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }

        // everything goes correct so isomporhic
        return true;
    }
};