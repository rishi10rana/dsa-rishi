class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Some Information
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Step 1 - Transpose the matrix
        for(int i=0;i<rows;i++){
            for(int j=0;j<=i;j++){
                if(i!=j){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }

        // Step 2 - Flip the matrix - means reverse the elemenets in each row
        for(int i=0;i<rows;i++){
            int start = 0;
            int end = cols - 1;
            while(start<=end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
    }
};