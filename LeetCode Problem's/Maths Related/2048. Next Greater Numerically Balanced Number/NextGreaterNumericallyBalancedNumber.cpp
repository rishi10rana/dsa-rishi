class Solution {
public:
    // Approach 1: Bruteforce approach - O(nlogn)
    bool checkBalanced(int num){
        vector<int> freq(10, 0);
        string s = to_string(num);

        for(char &c: s){
            freq[c - '0']++;
            // 0 agar aagaya number mei means wo number 
            // not balanced hi hai
            if(c == '0'){
                return false;
            }
        }

        for(int i=1;i<=9;i++){
            if(freq[i] > 0 && freq[i]!=i){
                // not a balanced number
                return false;
            }
        }

        // means all correct
        return true;
    }

    int nextBeautifulNumber(int n) {
        const int maxValue = 1224444; // ye answer max value of n ke liya hai isse jyada nahi ho sakte ans
        for(int i=n+1;i<=maxValue;i++){ // O(n)
            if(checkBalanced(i)){ // O(log n)
                return i;
            }
        }
        return -1;
    }
};