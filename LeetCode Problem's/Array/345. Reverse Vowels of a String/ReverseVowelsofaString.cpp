class Solution {
public:
    // function to check a character is vowel or not
    bool isVowel(char ch){
        string vowels = "aeiouAEIOU";
        return (vowels.find(ch) < vowels.length()) ? true : false; 
    }
    string reverseVowels(string s) {
        // 2 Pointer
        int left = 0;
        int right = s.length()-1;

        while(left<=right){
            // koii ek condition hi chalegi at a time
            if(!isVowel(s[left])){ // agar current "left" index mei vowel nahi to aage move kardo
                left++;
            }
            else if(!isVowel(s[right])){ // agar current "right" index mei vowel nahi ek decrementt move kardo
                right--;
            }
            else{ // matlab finally dono side mei vowel hai to swap kardo
                swap(s[left],s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};