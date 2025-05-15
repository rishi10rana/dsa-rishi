class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // an array whose index represent all letter in English and to 
        // store occurances of letters in I/P string
        int arr[26]={0};
        
        // To calculate and store occurances
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int number = 0;
            number = ch - 'a';
            arr[number]++;
        }
        
        // To find maximum occurance letter index in arr
        int maxii = -1 , ans = 0;
        for (int i=0;i<26;i++){
            if(maxii<arr[i]){
                ans = i;
                maxii = arr[i];
            }
        }
        
        // from thr index evaluate letter
        char finalAns = 'a'+ ans;
        return finalAns;
    }
};