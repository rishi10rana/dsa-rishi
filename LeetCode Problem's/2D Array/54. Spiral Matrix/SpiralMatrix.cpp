class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // To store result
        vector<int> ans;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Setting Index's
        int startingRow = 0;
        int endingRow = rows - 1;
        int startingCol = 0;
        int endingCol = cols - 1;

        int count = 0;
        int total = rows * cols;

        while(count < total){
            // print starting row
            for(int index = startingCol;index<=endingCol && count < total;index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            // print ending col
            for(int index = startingRow;index<=endingRow && count < total;index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            // print ending row
            for(int index = endingCol;index>=startingCol && count < total;index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            // print starting col
            for(int index = endingRow; index>=startingRow && count < total;index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;  
    }
};