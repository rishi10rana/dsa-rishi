class Solution {
  public:
    // Function to return list of integers that form the boundary
    // traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> >& mat) {
        // code here
        // find total rows and cols
        int m = mat.size();
        int n = mat[0].size();
        
        // set some intitials
        int topRow = 0;
        int bottomRow = m - 1;
        int leftCol = 0;
        int rightCol = n - 1;
        
        // To store result
        vector<int> result;
        
        // print left to right (topRow)
        for(int i=leftCol;i<=rightCol;i++){
            result.push_back(mat[topRow][i]);
        }
        topRow++; // so that no duplicates should print 
        
        // print top to bottom (rightCol)
        for(int i=topRow;i<=bottomRow;i++){
            result.push_back(mat[i][rightCol]);
        }
        rightCol--;
        
        // print right to left (bottomRow)
        for(int i=rightCol;i>=leftCol;i--){
            result.push_back(mat[bottomRow][i]);
        }
        bottomRow--;
        
        // print bottom to top (leftCol)
        for(int i=bottomRow;i>=topRow;i--){
            result.push_back(mat[i][leftCol]);
        }
        leftCol++;
        
        // stop here dont print the remaining (inner) elements as we dont need them
        
        return result;
    }
};
