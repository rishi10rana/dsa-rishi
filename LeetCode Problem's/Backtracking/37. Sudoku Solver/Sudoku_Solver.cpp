class Solution {
public:
    // check it is safe to place a value in empty cell or not
    bool isSafe(vector<vector<char>> &board,int row,int col,int val){
        for(int i=0;i<9;i++){
            // Check in row val should not be their
            if(board[row][i]==val){
                return false; // phela se hai
            }

            // Check in col val should not be their
            if(board[i][col]==val){
                return false; // phela se hai
            }

            // check jis grid mei wo empty cell belong karta wha bhi val nahi hona chahiye
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        // yaha tak agaye matlab value place kar sakte
            return true;
    }

    bool solve(vector<vector<char>> &board){
        int n = board.size();

        // travers in the board through each cell to find any emty cell
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){ // check for empty cell
                    // try to place digits from 1-> 9
                    for(char val='1';val<='9';val++){
                        if(isSafe(board,row,col,val)){ // check karo safe hai kya place karna is value ko
                            board[row][col] = val;
                            // call the recusion for placing next value
                            bool aageSolutionTha = solve(board);
                            if(aageSolutionTha){
                                return true;
                            }
                            else{
                                // backtrack
                                board[row][col] = '.';
                            }
                        }
                    }
                    // means agar koii bhi lement place nahi kar paye to false return kardena
                    // jo hume bactrack karwa dega and jo value place kari thi usse remove kardega
                    return false;
                }
            }
        }
        // par maanlo search karne pe aage koii aur new empty cell nahi mila matlab 
        // ek valid solution mil gaya to return true and wo jisse nbaki saree function se bhi true
        // return karwa do taki recursion stop hojaye hume saree answeer nahi dudhne bas ek valid 
        // solution chahiye
        return true;
    }

    // T.C = O(9^m) , m = no of empty cell as on we can have 9 digit possibe 
    // so in worst case all possibilties run like when suduko cant be solved

    // S.C = O(1) - as fied max recusrive call -81  in worst case 
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};