class Solution {
public:
    // Approach 1 : Used Stack T.C = O(n) , S.C = O(n)
    bool isDigit(char ch){
        return (ch>='0' && ch<='9') ? true : false;
    }
    bool isSpace(char ch){
        return (ch==' ') ? true: false;
    }
    int calculate(string s) {
        stack<int> st;
        int currentNumber = 0; // to track current number
        char operation = '+'; // to track last opeartion we need to perfom

        for(int i=0;i<s.length();i++){
            char currentChar = s[i];
            // it is a digit
            if(isDigit(currentChar)){ // to form the currentNumber
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }
            if(!isDigit(currentChar) && !isSpace(currentChar) || i==s.length()-1){ // means an opeartor
                if(operation == '-'){
                    st.push(-currentNumber);
                }
                else if(operation == '+'){
                    st.push(currentNumber);
                }
                else if(operation == '*'){
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop * currentNumber);
                }
                else if(operation == '/'){
                    int stackTop = st.top();
                    st.pop();
                    st.push(stackTop / currentNumber);
                }
                operation = currentChar; // last operation perform kardiya to ab update kardo
                currentNumber = 0; // ye number ka kaam hoga to reset kardo
            }
        }

        // alst mei stack humaraa individual expression ka ans store kare hoga un sabko add kardo
        int sum = 0;
        while(!st.empty()){
            sum = sum + st.top();
            st.pop();
        }
        
        return sum;
    }

    /*
    // Approach 2 :  Using just variables T.C = O(n) , S.C = O(1)
    bool isDigit(char ch){
        return (ch>='0' && ch<='9') ? true : false;
    }
    bool isSpace(char ch){
        return (ch==' ') ? true: false;
    }
    int calculate(string s) {
        int currentNumber = 0; // to track current number
        char lastOperation = '+'; // to track last opeartion we need to perfom
        int result = 0; 
        int lastNumber = 0;

        for(int i=0;i<s.length();i++){
            char currentChar = s[i];
            // agar digit aaye
            if(isDigit(currentChar)) {
                currentNumber = (currentNumber*10) + (currentChar - '0');
            }
            // ki agar opeartor aaye ya last index value
            if(!isDigit(currentChar) &&!isSpace(currentChar) || i==s.length()-1){
                if(lastOperation == '+' || lastOperation == '-'){
                    result = result + lastNumber;
                    lastNumber = (lastOperation == '+') ? currentNumber: -currentNumber ;
                }
                else if(lastOperation == '*'){
                    lastNumber = lastNumber * currentNumber; 
                }
                else if(lastOperation == '/'){
                    lastNumber = lastNumber / currentNumber; 
                }
                lastOperation = currentChar; // update kardo isse ab
                currentNumber = 0; // currentNumber ko bhi reset kardo
            }
        }

        // last mei jab iteration khatam hojaegi lastNu mber mei last expression jo evaluate husa hoga
        // wo present hoga usee bhi final result mei add kardo
        result = result + lastNumber;
        return result;
    }
    */
};