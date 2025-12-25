class Solution {
public:
    // DP Tabulation - Longest Incresing Subsequence (LIS)
    // T.C = O(len^2 * n)
    // S.C = O(1)
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();

        vector<int> dp(len, 1);

        for(int i=1;i<len;i++){
            for(int j=0;j<=i-1;j++){
                // to check ki saree strings LIS li condtion ko follow kare
                bool safe = true;

                for(int k=0;k<n;k++){
                    if(strs[k][j] <= strs[k][i]){
                        continue;
                    }
                    else safe = false;
                }
                // agar follow kar kar rahe saree strings condtiion tab hi iss LIS ko consider karo aur dp update karo
                if(safe == true){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        // scan dp array max LIS length nikalne ke liya
        int LISlen = INT_MIN;
        for(int i=0;i<len;i++){
            LISlen = max(LISlen, dp[i]);
        }

        // kitna cols delete karne pade
        int result = len - LISlen;
        return result;
    }
};