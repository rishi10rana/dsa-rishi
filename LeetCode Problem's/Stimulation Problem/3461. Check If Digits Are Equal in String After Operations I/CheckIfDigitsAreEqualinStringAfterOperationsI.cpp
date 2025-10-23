class Solution {
public:
    // stimulation problem - jo kaha hai problem mei wahi karna
    // T.C = O(n^2)    S.C = O(1)
    bool hasSameDigits(string s) {
        int n = s.length();

        while(n > 2){
            for(int i=0;i<n-1;i++){
                int digit1 = s[i] - '0';
                int digit2 = s[i+1] - '0';
                int newDigit = (digit1 + digit2) % 10;

                // re assign the new digit at ith position
                s[i] = newDigit + '0';
            }
            // decrement the size
            n--;
        }

        // check if both digit same in string
        return s[0] == s[1];
    }


    /*
    bool hasSameDigits(string s) {
        while(s.length()!=2){

            for(int i=0;i<s.length()-1;i++){
                int digit1 = s[i] - '0';
                int digit2 = s[i+1] - '0';
                int new_digit = (digit1 + digit2) % 10;
                s.replace(i, 1, to_string(new_digit));
            }
            // pop last char 
            s.pop_back();
        }

        // check if both the digit of the final string are same
        if((s[0]-'0') == (s[1]-'0')){
            return true;
        }
        return false;
    }
    */
};