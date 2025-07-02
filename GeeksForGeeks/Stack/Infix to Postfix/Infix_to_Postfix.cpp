class Solution {
  public:
    // provides the values to compare precedence of operators
    int precedence(char ch){
        if(ch=='^') return 3;
        else if(ch=='*' || ch=='/') return 2;
        else if(ch=='+' || ch=='-') return 1;
        return -1;
    }
    
    // T.C = O(n) , S.C = O(n)
    string infixToPostfix(string& s) {
        // code here
        int i = 0; // iterator
        string ans = "";
        stack<char> st;
        
        while(i < s.length()){
            // if it an opearand
            if(s[i]>='A' && s[i]<='Z' || 
            s[i]>='a' && s[i]<='z' ||
            s[i]>='0' && s[i]<='9'){
                ans = ans + s[i];
            }
            
            // if opening bracket
            else if(s[i]=='('){
                st.push(s[i]);
            }
            
            // if closing bracket
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='('){
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop(); // to remove the bacha hua '('
            }
            
            // matlab opeartor hai
            else{
                while(!st.empty() && precedence(s[i]) <= precedence(st.top())){
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]); // phir aagar sab safe hai to add kardo
                // ye tab bhi ad kardega jab incoming operator ki precedence high ho
            }
            i++;
        }
        // pop the remaining operators
        while(!st.empty()){
            ans = ans + st.top();
            st.pop();
        }
        
        return ans;
    }
};
