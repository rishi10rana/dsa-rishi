class Solution {
public:
    string removeDuplicates(string s) {
        // Create a empty string which will act as a stack to store answer
        string result = "";

        // Traverse individual characters of the string one by one
        for(int i=0;i<s.length();i++){
            // pop the last character from stack if the incoming character selected is also same
            if(!result.empty() && s[i]==result.back()){
                result.pop_back();
            }
            // if this character is not same to previous one , simply push the currently
            // selected charcater in stack
            else{
                result.push_back(s[i]);
            }
        }

        // return the answer 
        return result;
    }
};