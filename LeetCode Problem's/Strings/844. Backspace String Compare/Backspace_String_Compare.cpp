class Solution {
public:
    // Approach - like 2 pointer  T.C = O(n + m) = O(n)   S.C = O(m+n)
    bool backspaceCompare(string s, string t) {
        string str1 = "";
        string str2 = "";
        int i = 0;
        int j = 0;
        while(i<s.length()){ // o(n)
            if(s[i]>='a' && s[i]<='z'){
                str1 = str1 + s[i];
            }
            else{ // means # then pop last element
                if(!str1.empty())
                    str1.pop_back();
            }
            i++;
        }

        while(j<t.length()){ // O(m)
            if(t[j]>='a' && t[j]<='z'){
                str2 = str2 + t[j]; 
            }
            else{ // means #
                if(!str2.empty())
                    str2.pop_back();
            }
            j++;
        }

        // check finally strings are equal or not
        if(str1.compare(str2)==0){
            // means equal 
            return true;
        }
        else{
            return false;
        }
    }
};