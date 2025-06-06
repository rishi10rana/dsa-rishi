class Solution {
public:
    // Approach - 1 , T.C = O(n)
    /*
    bool wordPattern(string pattern, string s) {
        // first we nee to tokenize the input string "s"
        vector<string> words; // to store individual words

        stringstream ss(s); // oject of stringstream class
        string token; 
        int countWords = 0;

        // Tokenizing w.r.t. space ' ' using getlie function - O(n)
        while(getline(ss,token,' ')){
            words.push_back(token);
            countWords++;
        }

        int n = pattern.length();
        if(n != countWords){
            return false; // As the pattern is not followed
        }

        // to store mapping of a string to a word
        unordered_map<string, char> mp;
        // to keep track of what character are used
        set<char> used;

        // traverse at atime a word and a character from pattern using "i" - O(n)
        for(int i=0;i<n;i++){
            string word = words[i];
            char ch = pattern[i];

            // safe case - word not present in map , and ch not present in set.
            if(mp.find(word) == mp.end() && used.find(ch) == used.end()){
                // Simply ass them
                used.insert(ch);
                mp[word] = ch;
            }
            // means word is presnt in map , then check if it is mapped to 
            // correct ch , if not means pattern not followed but if 
            // yes means patterbn followed move to next word and character.
            else if(mp[word]!=ch){
                return false;
            }
        }
        // means everything went right pattern followed
        return true;
    }
    */

    // Approach 2 - using two maps , T.C = O(n)
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex; // to map a character of pattern to index
        unordered_map<string, int> stringToIndex; // to map a word to index

        stringstream ss(s);
        string token;
        
        // pointer to track the characters in pattern
        int i = 0;
        int countWords = 0;
        int n = pattern.length();

        // another wayto acssess individual words - tokenization
        while(ss >> token){
            countWords++;

            // first case - if pattern exhaust first but still tokens their --> means pattern not followed
            // second case - if for incoming character and word the indexes not match then means pattern not followed
            if(i == n || charToIndex[pattern[i]] != stringToIndex[token]){
                return false;
            }

            // store the key and the index
            // note - store the index as +1 because if akey is present in a map then it return 0 which can 
            // create problem for us.
            charToIndex[pattern[i]] = i + 1;
            stringToIndex[token] = i + 1;

            // check net character
            i++;
        }
        // pattern and no of words doesnt match - means pattern not followed
        if(n!=countWords){
            return false;
        }

        // tokens = dog cat
        // pattern = ababab
        // token exhaust but pattern still their
        // no nned of this case as above length matching will solve this problem
        // if(i!=n){
        //     return false;
        // }

        // means nothing goes wrong pattern is followed
        return true;
    }
};