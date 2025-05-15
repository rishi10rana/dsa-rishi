class Solution {
public:
    // Simple function to convert uppercase to lowercase
    char toLower(char ch){
        if(ch>='a' && ch<='z' || ch>='0' && ch<='9'){
            return ch; 
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    // Simple function to tell which characters are accepted Only
    bool isValidCharacter(char ch){
        if(ch>='a' & ch<='z' || ch>='A' && ch<='Z' || ch>='0' && ch<='9'){
            return true;
        }
        else{
            return false;
        }
    }

    bool isPalindrome(string s) {
        // 2 Pointer Approach
        int start = 0;
        int end = s.length() - 1;

        while(start<=end){
            // check if start is poinitng to any special character or space , then skip it
            if(start<end && !isValidCharacter(s[start])){
                start++;
            }
            // check if end is poinitng to any special character or space , then skip it
            else if(start<end && !isValidCharacter(s[end])){
                end--;
            }
            // check if the element comparaed are not equal , then string is not pallindrome
            else if(toLower(s[start])!=toLower(s[end])){
                return false;
            }
            // if element equal then mobe for next
            else{
                start++;
                end--;
            }
        }
        return true; // if all elements till now are equal , means then string is pallindrome
    }
};