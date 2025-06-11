class Solution {
public:
    // Approach - 1 Use Extra 2D array - T.C = O(n^2)  S.C = O(n) = O(mn)
    // as here matrix is (m x n) we cant transpose without extra space
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // store no. of rows and cols
        int m = matrix.size();
        int n = matrix[0].size();

        // To store the final result in a 2D array
        // awy to create a 2d vector by defining no of rows and cols and initial value at start
        // when we transpose a matrix (m x n) the no of rows (m) and cols(n) switches with each other so matrix becomes (n x m)
        vector<vector<int>> result(n, vector<int>(m,0));

        // to transpose , change row to column
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[j][i] = matrix[i][j];
            }
        }

        return result;
    }
};