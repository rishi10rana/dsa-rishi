class Solution {
public:
    // T.C = O(n) , S.C = O(n)
    int calculate(string s) {
        int n = s.length();
        stack<int> st;  // to perfom some expression evaulation which if it contins bracket
        int number = 0; // to form the number 
        int result = 0; // to store final ans
        int sign = 1;   // 1--> +ve    , -1 --> -ve

        // traver expresion
        for(int i=0;i<n;i++){
            // agar digit aaye
            // to number form karlo
            // spaces agar aata to koii bhi condition nahi chalti wo skip hojate hai
            if(isdigit(s[i])){ // ye inbuilt function apne aap check karleta
                number = (number * 10) + (s[i] - '0');
            }

            // jab bhi koii opeartor milta iska matlab ek nuber form hogaye usse result mei add kardo with sign
            else if(s[i] == '+'){
                result = result + (sign * number);
                number = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                result = result + (sign * number);
                number = 0;
                sign = -1;
            }
            
            // agar opening bracket mila to matlab ek pura naaya expression calulate jarna hoga
            // to purani cheeze jaise last result aur brackets start hon se pheal sign stack mei store karlo
            else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                number = 0;
                result = 0;
                sign = 1; // bracket ke andar starting mei koii sign nahi hota isliya +
            }
            // agar closing mila matlab ek bracket wale expression ka result aane wala
            // usmei stack se sign multiply karke , stack mei jo result tha usmei add kardo
            else if(s[i] == ')'){
                result = result + (sign * number); // bracket ke last element ko bhi add kardo
                number = 0;

                int stack_sign = st.top();
                st.pop();

                int last_result = st.top();
                st.pop();

                result = result * stack_sign;
                result = result + last_result;
            }
        }

        // ek case bach jata jismei koii bracket na ho last mei bus ek number ho wo bach jata hai 
        // add karne ke liya usse bhi sign laga kar add kardo final result ke sath
        result = result + (sign * number);
        return result;
    }
};