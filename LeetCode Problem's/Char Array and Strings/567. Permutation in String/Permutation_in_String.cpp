class Solution {
private:
    // Craete a function to check whether all corresponding elements of two arrays are equal or not
    bool checkEqual(int arr1[26], int arr2[26]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
        // To store count of occurances of letter in s1
        int count[26] = {0};

        for(int i=0;i<s1.length();i++){
            int index = s1[i] - 'a';
            count[index]++;
        }

        // Traverse s2 string in window of size "s1.length()" and compare
        int i = 0;
        int windowSize = s1.length();
        // To store count of occurances of letter in window selected for checking
        int count2[26] = {0};

        // Running For the First Window - traversing all letters inside a window also make sure 
        // "i" should always remain less than "s2" length otherwise we get index out of bound error in 
        // case s1 length is larger than s2.
        while(i < windowSize && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if(checkEqual(count,count2)){
            return 1;
        }

        // Run for aage waale windows now as when moving forward the window - we select one 
        // character and remove the count of one old (previous) character
        while(i < s2.length()){
            // For new selected character
            char newChar = s2[i];
            int index = newChar - 'a';
            count2[index]++;

            // For old character
            char oldChar = s2[i-windowSize];
            index = oldChar - 'a';
            count2[index]--;

            if(checkEqual(count,count2)){
                return 1;
            }
            i++;
        }
        return 0;
    }
};