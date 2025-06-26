class Solution {
  public:
    bool isOperator(char ch){
        return (ch == '+' || ch == '-' || ch =='*' || ch=='/')? true: false;
    }
    
    // T.C = O(n) , S.C = O(n)
    int checkRedundancy(string s) {
        stack<char> st;
        
        // traverse through whole expression
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            // if opening bracket yaa koii opeartor aaye to push kardo
            if(ch == '(' || isOperator(ch)){
                st.push(ch);
            }
            // agar closing bracket aaye
            if(ch ==')'){
                // to find that b/w this ')' and the last '(' we got is their an opeartor b/w them
                bool found = false; 
                while(st.top()!='('){
                    if(isOperator(st.top())){
                        found = true;
                    }
                    st.pop(); // to pop that remianing '('
                }
                st.pop();
                if(!found){ // means opeartor not found
                    return 1; // redundant brackets their
                }
            }
        }
        return 0; // means no redundant brackets
    }
};
