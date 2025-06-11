class Solution {
public:
    // T.C = O(n^2 + m + n) = O(n^2) , S.C = O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        // Dynamically create 2 arrays 
        // row array store - which rows should be made all zero
        // col array store - which cols should be made all zero
        bool* row = new bool[m];
        bool* col = new bool[n];

        // initialize the values both array to 0 (fasle) at first
        for(int i=0;i<m;i++){
            row[i] = false;
        }
        for(int j=0;j<n;j++){
            col[j] = false;
        }

        // traverse in original array and mark what rows and cols need to be 0.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i] = true; // this row need to be zero so mark it true 
                    col[j] = true; // this col need to be zero so mark it true 
                }
            }
        }

        // travese again in original array and check each element indices if it their
        // indices include any i or j which is marked true then -> it is needed to be marked 0
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }

        // free dynamically alloacted memory
        delete[] row;
        delete[] col;
        // to avoid dangling pointer
        row = nullptr;
        col = nullptr;
    }
};