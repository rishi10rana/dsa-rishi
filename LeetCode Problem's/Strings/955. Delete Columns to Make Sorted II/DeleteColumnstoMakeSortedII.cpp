class Solution {
public:
    // bruteforce
    // T.C = O(len * n)
    // S.C = O(n - 1)
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();

        // an array to check that the strings orders is correctly determined by previous column
        vector<bool> alreadySorted(n-1, false);

        int answer = 0;
        for(int j=0;j<len;j++){ // for column
            bool deleted = false;  // checks we need to delete the row or not
            for(int i=0;i<n-1;i++){ // for row
                if(!alreadySorted[i] && strs[i][j] > strs[i+1][j]){
                    answer++; // means we need to delete the column
                    deleted = true;
                    break;
                }
            }
            if(!deleted){ // means column doesnt need to be deleted
            // so check kya characters in this column are able to identify order of strings
                for(int i=0;i<n-1;i++){
                    alreadySorted[i] = alreadySorted[i] || (strs[i][j] < strs[i+1][j]);
                }
            }              
        }

        return answer;
    }
};