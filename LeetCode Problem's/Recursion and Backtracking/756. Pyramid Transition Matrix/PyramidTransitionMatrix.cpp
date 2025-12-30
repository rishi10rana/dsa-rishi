class Solution {
public:
    // Approach: Recursion + Backtracking
    // T.C = O(L^n) exponential time   , L means consider each pair have L poosible ways to make pattern
    // n means pyramid bottom row total blocks
    /*
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string next){
        // base case
        if(curr.length() == 1){
            return true; // means pyramid ban gaya hai hum pyramid ke top mei aagaye
        }
        // pyramid ki ek row mei jitna pair the sab cover hogaye 
        if(idx == curr.length() - 1){
            // means call for the next above row for building pyramid
            return solve(next, mp, 0, "");
        }

        // ab curr row mei jis index mei hu waha se pair choose karte
        string pair = curr.substr(idx, 2);
        
        // check karo kya ye pair map mei hai agar nahi hai means koii pattern exist nahi karta
        // means iss pair se aage pyraid formation nahi ho sakti
        if(!mp.count(pair)){
            return false; // means cant make pyramid from here
        }

        // yaha tak aagye means pair ke liya pattern's hai
        // try all possible patterns for that pair
        for(char &ch: mp[pair]){
            next.push_back(ch); // TRY
            if(solve(curr, mp, idx+1, next)){ // EXPLORE
                return true; // agar iss way ko explore karete wakt answer milgaya to true return kardo
            }
            // agar is way se answer nahi mila (backtrack karke hum upar aayenga wapis)
            next.pop_back(); // UNDO
        }

        // agar yaha aagye means koii way nahi mila abhi tak to
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // to store patterns for easy search (using pair)
        unordered_map<string, vector<char>> mp;
        for(string &pattern: allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }

        // curr pyrmaid row, map, start index, initially next pyramid row 
        return solve(bottom, mp, 0, "");
    }
    */


    // Approach: Recursion + Backtracking + Memonization
    // T.C = O(L^n) exponential time   , L means consider each pair have L poosible ways to make pattern
    // n means pyramid bottom row total blocks
    // T.C will reduce as some results will be already stored so less time
    unordered_map<string , bool> dp;
    bool solve(string curr, unordered_map<string, vector<char>>& mp, int idx, string next){
        // base case
        if(curr.length() == 1){
            return true; // means pyramid ban gaya hai hum pyramid ke top mei aagaye
        }

        string key = curr + "_" + to_string(idx) + "_" + next;
        if(dp.count(key)){
            return dp[key];
        }

        // pyramid ki ek row mei jitna pair the sab cover hogaye 
        if(idx == curr.length() - 1){
            // means call for the next above row for building pyramid
            return dp[key] = solve(next, mp, 0, "");
        }

        // ab curr row mei jis index mei hu waha se pair choose karte
        string pair = curr.substr(idx, 2);
        
        // check karo kya ye pair map mei hai agar nahi hai means koii pattern exist nahi karta
        // means iss pair se aage pyraid formation nahi ho sakti
        if(!mp.count(pair)){
            return dp[key] = false; // means cant make pyramid from here
        }

        // yaha tak aagye means pair ke liya pattern's hai
        // try all possible patterns for that pair
        for(char &ch: mp[pair]){
            next.push_back(ch); // TRY
            if(solve(curr, mp, idx+1, next)){ // EXPLORE
                return dp[key] = true; // agar iss way ko explore karete wakt answer milgaya to true return kardo
            }
            // agar is way se answer nahi mila (backtrack karke hum upar aayenga wapis)
            next.pop_back(); // UNDO
        }

        // agar yaha aagye means koii way nahi mila abhi tak to
        return dp[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // to store patterns for easy search (using pair)
        unordered_map<string, vector<char>> mp;
        for(string &pattern: allowed){
            mp[pattern.substr(0,2)].push_back(pattern[2]);
        }

        // curr pyrmaid row, map, start index, initially next pyramid row 
        return solve(bottom, mp, 0, "");
    }
};