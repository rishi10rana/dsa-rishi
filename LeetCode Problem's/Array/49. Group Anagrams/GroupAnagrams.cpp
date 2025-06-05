class Solution {
public:
    // function to check whetehr a word is anagram ny comparing it with a word from smallList
    /*
    bool isAnagram(string first, string second){
        if(first.length()!=second.length()){ // cant be an anagram if lengths not equal
            return false;
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());

        // compare function returns 0 if two string are equal
        if(first.compare(second)==0){
            return true;
        }
        return false;
    }

    // Approach - 1: Bruteforce T.C = O(n^2 * nlogn)
    vector<vector<string>> groupAnagramsBS(vector<string>& strs) {
        // To store answer
        vector<vector<string>> bigList;

        // access each word individually
        for(string word: strs){
            bool added = false;
            // ckeckoing whether that word is anagram to any group of words(i.e smallList) 
            // previously in bigList 
            for(vector<string> &smallList: bigList){ 
                if(isAnagram(smallList.at(0),word)){
                    // if yes the word is anagram then add it to that group of words(i.e smallList)
                    smallList.push_back(word);
                    added = true;
                    break;
                }
            }
            // if element was not added means it was not anagram so add it as separate group
            if(!added){ 
                vector<string> newSmallList;
                newSmallList.push_back(word);
                bigList.push_back(newSmallList);
            }
        }
        return bigList;
    }
    */

    // Approach 2 - categorize by sorting - hashing (using map)
    // T.C - O(n * k.logk)
    /*
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // To store the anagrams
        vector<vector<string>> bigList;

        // map to store key = sorted string , value = vector of words which forms anagram
        map<string,vector<string>> mymap;

        // map<string,vector<string>>::iterator itr;

        // taverse eeah word
        for(string word: strs){
            // store a copy of original word as we will sort it.
            string temp = word;
            sort(temp.begin(),temp.end());

            // Way 1 : find if the key present or not if present then at that location using iterator add the word 
            // in the value part , if not presnt create a whole new spearate vector with word in it and add 
            // that vector 
            // itr = mymap.find(temp);
            // if(itr!=mymap.end()){
            //     itr->second.push_back(word);
            // }
            // else{
            //     vector<string> value;
            //     value.push_back(word);
            //     mymap[temp] = value;
            // }

            // prefered way
            // Way 2: directly aadd the key and word as map will itself handle present or not present case
            mymap[temp].push_back(word);
        }
        // to store value (i.e group of anagrams) to give final answer
        for(auto i: mymap){
            bigList.push_back(i.second);
        }
        return bigList;
    }
    */

    // Approach 3 - Categorize by freq - hashing (using map)
    // T.C = O(nk) , n=no of strings , k=length of largest string 
    // for freqCount
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // To store the group of anagrams
        vector<vector<string>> bigList;

        // to store the key = frequency string and the value = list of words (i.e anagrams)
        unordered_map<string,vector<string>> mp;

        // traverse through each word
        for(string word: strs){
            // form the freq string for each word
            string hashString = "";
            // used to find count of each letter
            vector<int> freqCount(26,0);
            for(char ch: word){
                int index = ch - 'a';
                freqCount[index]++;
            }
            //  ofrm the freq string also called hash string ex - (a1b2..)
            for(int i=0;i<26;i++){
                hashString.push_back('a'+i);
                hashString = hashString + to_string(freqCount[i]);
            }
            // this will add the hashString key to the map if not present but if present it will at that 
            // key , add a new word to the value which is a vector  
            mp[hashString].push_back(word);
        }

        // to store value (i.e group of anagrams) to give final answer
        for(auto [key,vectOfStrings] : mp){
            bigList.push_back(vectOfStrings);
        }
        return bigList;
    }
};