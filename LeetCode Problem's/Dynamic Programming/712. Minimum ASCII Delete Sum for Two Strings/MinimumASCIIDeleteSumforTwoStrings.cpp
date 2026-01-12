class Solution {
public:
    // Recursion
    // T.C = O(2^m . 2^n)
    /*
    int m;
    int n;
    int solve(string& s1,string& s2, int i, int j){
        // base case dono string equal kardi humne kisi tarah deletion se so now nothing remains to check
        if(i >= m && j >= n){
            return 0;
        }
        // other cases
        if(i >= m){ // agar s1 exhaust hogayi par s2 bacchi to means s2 ke saree chracters ko delete karo
            return s2[j] + solve(s1, s2, i, j+1);
        }
        if(j >= n){ // agar s3 exhaust hogayi par s1 bacchi to means s1 ke saree chracters ko delete karo
            return s1[i] + solve(s1, s2, i+1, j);
        }
        if(s1[i] == s2[j]){
            return solve(s1, s2, i+1, j+1); // agar bother charcter same so no delete aage bad jaoo
        }

        // 2 choices
        int delete_s1_i = s1[i] + solve(s1, s2, i+1, j);
        int delete_s2_j = s2[j] + solve(s1, s2, i, j+1);

        return min(delete_s1_i, delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        // i, j
        return solve(s1, s2, 0, 0);
    }
    */

    // Recursion + Memonize
    // T.C = O(m X n)
    int m;
    int n;
    int dp[1001][1001];
    int solve(string& s1,string& s2, int i, int j){
        // base case dono string equal kardi humne kisi tarah deletion se so now nothing remains to check
        if(i >= m && j >= n){
            return 0;
        }

        // check
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // other cases
        if(i >= m){ // agar s1 exhaust hogayi par s2 bacchi to means s2 ke saree chracters ko delete karo
            return dp[i][j] = s2[j] + solve(s1, s2, i, j+1);
        }
        if(j >= n){ // agar s3 exhaust hogayi par s1 bacchi to means s1 ke saree chracters ko delete karo
            return dp[i][j] = s1[i] + solve(s1, s2, i+1, j);
        }
        if(s1[i] == s2[j]){
            return solve(s1, s2, i+1, j+1); // agar bother charcter same so no delete aage bad jaoo
        }

        // 2 choices
        int delete_s1_i = s1[i] + solve(s1, s2, i+1, j);
        int delete_s2_j = s2[j] + solve(s1, s2, i, j+1);

        return dp[i][j] = min(delete_s1_i, delete_s2_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();

        memset(dp, -1, sizeof(dp));

        // i, j
        return solve(s1, s2, 0, 0);
    }
};