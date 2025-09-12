class Solution {
public:
    // Approach Bruteforce
    // T.C = O(n^2)  S.C = O(3) set can have atmost 3 elements
    /*
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int maxlen = 0;
        // generate possible subarrays
        for(int i=0;i<n;i++){
            set<int> s; // to keep track of the no of differrent types of fruit i picked shoud not exceed 2;
            for(int j=i;j<n;j++){
                s.insert(fruits[j]);

                // check kahi type of fruits pick 2 se jayda to nahi 
                //hogaye kyuki agar hogaye to stop kardo hum aur pick nahi kar sakte
                if(s.size() > 2){
                    break;
                }

                // agar sab safe hai to
                int len = j - i + 1;
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
    */

    // Approach Sliding Window
    // T.C = O(n) + O(n) = O(2n)      S.C = O(3) set can have atmost 3 elements
    /*
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0, maxlen = 0;
        map<int, int> mp;   // (type of fruit, freq)
        while(r < n){
            mp[fruits[r]]++;
            // check karo kahi window mei condition violate to nahi ho rahi
            if(mp.size() > 2){
                // shrinking the window to makie it valid
                while(mp.size() > 2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0){
                        mp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            // gar sab sahi hai
            if(mp.size()<=2){
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }

        return maxlen;
    }
    */

    // Better Sliding Window
    // T.C = O(n)    S.C = O(4) set can have atmost 3 or 4 elements
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0, maxlen = 0;
        map<int, int> mp;   // (type of fruit, freq)
        while(r < n){
            mp[fruits[r]]++;
            // check karo kahi window mei condition violate to nahi ho rahi
            if(mp.size() > 2){
                // shrink kardo window ko by only 1 move at a time
               mp[fruits[l]]--;
               if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
               }
               l++;
            }
            // gar sab sahi hai
            if(mp.size()<=2){
                int len = r - l + 1;
                maxlen = max(maxlen, len);
            }
            r++;
        }

        return maxlen;
    }
};