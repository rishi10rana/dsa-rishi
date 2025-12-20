class Solution {
public:
    // bruteforce
    // T.C = O(len * n)
    // S.C = O(1)
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();

        int count = 0; // to store cols to delete
        // assume all string arranged in new line (like grid)
        for(int i=0;i<len;i++){ // for each col
            bool flag = 0;
            for(int j=0;j<n-1;j++){ // for each row(select string)
                if(strs[j][i] > strs[j+1][i]){
                    flag = 1;
                }
            }
            if(flag == 1){
                count++;
            }
        }

        return count;
    }
};