class Solution {
public:
    // T.C = O(n)
    // S.C = O(1)
    string makeGood(string s) {
        int n = s.length();

        string result = "";
        // check each character which back() of result
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(!result.empty() && (ch == result.back() + 32 || ch == result.back() - 32)){
                result.pop_back(); // aA or Aa 
                // dont add current element 
                // also remove back element of result string
                // as they cause bad string
            }
            else{
                // all safe can tae this character
                result.push_back(ch);
            }
        }
        return result;
    }
};