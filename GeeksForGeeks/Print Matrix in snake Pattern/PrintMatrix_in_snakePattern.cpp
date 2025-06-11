class Solution {
  public:
    // Function to return list of integers visited in snake pattern in matrix.
    // T.C = O(n^2) , S.C = O(n);
    vector<int> snakePattern(vector<vector<int> > matrix) {
        // code here
        // store rows and cols size (n x n)
        int n = matrix.size();
        
        // Maintain a pointer for row
        int row = 0;
        
        // to store result
        vector<int> result;
        
        // traverse in each row till condination false
        while(row<n){
            // Move left to right
            for(int j=0;j<=n-1 && row<n;j++){
                result.push_back(matrix[row][j]);
            }
            row++;
            
            // Move right to left
            for(int j=n-1;j>=0 && row<n;j--){
                result.push_back(matrix[row][j]);
            }
            row++;
        }
        
        return result;
    }
};