class Solution {
public:
    // My Code
    /*
    bool check_magic_square(vector<vector<int>>& grid, int firstrow, int lastrow, int firstcol, int lastcol){
        vector<int> freq(16, 0);
        // freq of all numbers 3x3 grid
        for(int i=firstrow;i<=lastrow;i++){
            for(int j=firstcol;j<=lastcol;j++){
                // edge case agar grid ke andar koii bhi value greater than 9 huii so then not magic
                // yaa agar value 0 huii to wo bhi magic square nahi hai
                if(grid[i][j] > 9 || grid[i][j] == 0){
                    return false;
                }
                freq[grid[i][j]]++;
            }
        }

        for(int i=0;i<16;i++){
            if(freq[i] > 1){ // if freq of numbers not distinct then it is not magic square
                return false;
            }
        }

        // row sum
        int sum_first_row = grid[firstrow][firstcol] + grid[firstrow][firstcol + 1] + grid[firstrow][lastcol];
        int sum_second_row = grid[firstrow+1][firstcol] + grid[firstrow+1][firstcol + 1] + grid[firstrow+1][lastcol];
        int sum_third_row = grid[lastrow][firstcol] + grid[lastrow][firstcol + 1] + grid[lastrow][lastcol];

        // col sum
        int sum_first_col = grid[firstrow][firstcol] + grid[firstrow+1][firstcol] + grid[lastrow][firstcol];
        int sum_second_col = grid[firstrow][firstcol+1] + grid[firstrow+1][firstcol+1] + grid[lastrow][firstcol+1];
        int sum_third_col = grid[firstrow][lastcol] + grid[firstrow+1][lastcol] + grid[lastrow][lastcol];

        // diagonal sum
        int sum_diagonal1 = grid[firstrow][firstcol] + grid[firstrow+1][firstcol+1] + grid[lastrow][lastcol];
        int sum_diagonal2 = grid[firstrow][lastcol] + grid[firstrow+1][lastcol-1] + grid[lastrow][firstcol];


        // agar all equal means magic square
        if(sum_first_row == sum_second_row && sum_second_row == sum_third_row
            && sum_first_row == sum_first_col && sum_first_col == sum_second_col && sum_second_col == sum_third_col && sum_third_col == sum_diagonal1 && sum_diagonal1 == sum_diagonal2){
                return true;
        }
        return false;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows < 3 || cols < 3){
            // this grid cannot have a 3x3 magic square
            return 0;
        }

        int count = 0;
        // pick a 3*3 grid one by one
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<cols-2;j++){
                // check selected subgrid 3*3 is magic square 
                if(check_magic_square(grid, i, i+2, j, j+2)){
                    count++;
                }
            }
        }

        return count;
    }
    */

    
    // Same Approach - Implementation Based
    // T.C = O(row x col)
    // S.C = O(1) as unordered_Set max store 9 elements
    bool is_magic_square(vector<vector<int>>& grid, int r, int c){
        // the grid should have only numbers b/w 1 to 9 and all distinct
        unordered_set<int> st; // to track which nos covered in grid
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[r + i][c + j];
                if(num < 1 || num > 9 || st.count(num)){
                    // means gadbad hai grid mei so it cant be magic
                        return false;
                }
                else{
                    // consider this distinct no
                    st.insert(num);
                }
            }
        }

        // yaha tak agayae means check all individal rows, cols, and diagonals sum should be equal

        // verify row and cols sum
        int rsum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i=0;i<3;i++){
            // row sum check
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != rsum){
                // gadbad
                return false;
            }
            // col sum check
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != rsum){
                // gadbad
                return false;
            }
        }

        // diagonal sum check
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != rsum)
            return false; // gadbad

        // anti diagonal check
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != rsum)
            return false; // gadbad


        // reached here means all safe the 3x3 grid is a magic square
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        if(rows < 3 || cols < 3){
            // means our grid cannot have any magic square
            return 0;
        }

        // consider all the possible 3x3 subgrids and check are the magic square or not
        int count = 0;
        for(int i=0;i<rows-2;i++){
            for(int j=0;j<cols-2;j++){
                // check if a magic square or not
                if(is_magic_square(grid, i, j)){
                    count++;
                }
            }
        }

        return count;
    }
};