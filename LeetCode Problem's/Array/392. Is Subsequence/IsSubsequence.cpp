class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 2 Pointer
        int i = 0; // For s string
        int j = 0; // For t string

        while(i<s.length() && j<t.length()){ // agar dono mei se koii bhi range ke bahar chala jaye to rok dena
            if(s[i]==t[j]){ // equal hua to "i" bada dena
                i++;
            }
            j++; // warna har iteration mei "j" bada te rahoo
        }
        if(i==s.length()){ // iska matlab humne pura "s" string cover kar liya matlab ye "s" subsequence ,
        // "t" mei presnt hai
            return true;
        }
        else{
            return false;
        }
    }
};