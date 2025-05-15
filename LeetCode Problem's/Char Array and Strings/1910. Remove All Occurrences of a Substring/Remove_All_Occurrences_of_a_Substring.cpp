class Solution {
public:
    string removeOccurrences(string s, string part) {
        // stop loop if 's' length becomes 0 or unable to find any more substring sequenece in 's'
        while(s.length()!=0 && (s.find(part) < s.length())){
            // find function search for first occurance for sequence of character and if found 
            // returns the starting index / start position

            // erase function removes the sequence of character from start position given by "find" and we also 
            // tell how many character to remove
            s.erase(s.find(part),part.length());
        }

        return s;
    }
};