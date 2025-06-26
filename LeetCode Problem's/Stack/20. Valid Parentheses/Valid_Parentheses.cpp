class Solution {
public:
    // Approach - Using stack and map
    /*
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mp = {{'(',')'},{'{','}'},{'[',']'}};

        for(char ch: s){
            // check opening bracket - do push
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }
            // check for closing bracket
            if(ch==')' || ch=='}' || ch==']'){
                // check if the current character matches to the correspomding top 
                if(!st.empty() && ch == mp[st.top()]){
                    st.pop(); 
                }
                else{
                    return false;
                }
                // if not matchs do nothing
            }
        }
        if(st.empty()){ // means expression valid if stack empty
            return true;
        } 
        return false; // means not valid
    }
    */

    // Approach 2 - T.C = O(n) , S.C = O(n)
    bool isValid(string s) {
        stack<char> st;

        // if an opening bracket -> push
        // if a closing bracket which matches the top -> pop

        // traverse entire expression
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch=='['){ // means an opening bracket
                st.push(ch);
            }
            else{ // means a closing bracket
                if(!st.empty()){
                    char top = st.top();
                    if(ch == ')' && top=='(' || ch == '}' && top == '{' || ch == ']' && top == '['){
                        st.pop(); // got matching so pop
                    }
                    else{ 
                        return false; // means current ch doesnt match with top
                    }
                }
                else{ // means stack empty but encountered a closing bracket
                    return false;
                }
            }
        }
        // means agar yaha tak aagayae matlab expression valid par tabhi bhi check karlo
        if(st.empty()){
            return true;
        }
        return false;
    }
};