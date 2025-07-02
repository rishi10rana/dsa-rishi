// User function Template for C++

class Solution {
  public:
    // T.C = O(n) , T.C = O(n)
    string preToInfix(string pre_exp) {
        // Write your code here
        
        int i = pre_exp.length()-1;
        stack<string> st;
        
        while(i >= 0){
            // if any operand
            if(pre_exp[i] >= 'A' && pre_exp[i] <= 'Z' ||
            pre_exp[i] >= 'a' && pre_exp[i] <= 'z' ||
            pre_exp[i] >= '0' && pre_exp[i] <= '9'){
                st.push(string(1,pre_exp[i]));  // helps to create string object by giving size and char then we can pass it to stack
            }
            
            else{ // means operator
                string t1 = st.top();
                st.pop();
                
                string t2 = st.top();
                st.pop();
                
                string com = "(" + t1 + pre_exp[i] + t2 + ")";
                st.push(com);
            }
            i--;
        }
        return st.top();
    }
};