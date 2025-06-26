class Solution {
  public:
    // T.C = O(n) , S.C = O(n) 
    int countMinReversals(string s) {
        // for a exp to be valid 
        // no of opening brace = no of closing brace
        // means need to be of even length then only we can make it valid
        if(s.length()%2==1){
            return -1; // for odd cant balance
        }
        
        stack<char> st;
        
        // travere the exp
        // to remove the valid expression from string
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            if(ch == '{'){
                st.push(ch); //p ush opening brace
            }
            else{
                if(!st.empty() && st.top()=='{'){
                    st.pop(); // check if match opening found then pop it.
                }
                else{
                    st.push(ch);
                }
            }
        }
        
        // now stack contains only invalid expression
        int a = 0; // to count closing braces 
        int b = 0; // to count opening braces
        while(!st.empty()){
            if(st.top()=='{'){
                b++;
            }
            if(st.top()=='}'){
                a++;
            }
            st.pop();
        }
        
        // fromula to calculate minimum count
        int ans = (a+1)/2 + (b+1)/2;
        return ans;
        
    }
};