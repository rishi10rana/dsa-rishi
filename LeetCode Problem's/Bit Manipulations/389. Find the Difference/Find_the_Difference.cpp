class Solution {
public:
    // T.C = O(n)
    char findTheDifference(string s, string t) {
        string result = "";

        char temp = 0; // Assigns the null character
        // traverse all chracters of s and do xor
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            temp = temp ^ (int)ch; 
        }

        // traverse all chracters of t and do xor
        for(int i=0;i<t.length();i++){
            char ch = t[i];
            temp = temp ^ ch; 
            // we can also do without typecasting ch to int as it handled automatically  
        }

        return temp;
    }
};