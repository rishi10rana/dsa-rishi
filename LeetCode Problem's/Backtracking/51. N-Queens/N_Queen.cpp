class Solution {
public:
    map<int, bool> mp1; // to track on which rows queen placed
    map<int, bool> mp2; // to track on which above diagonals queen placed
    map<int, bool> mp3; // to track on which below diagonals rows queen placed
    
    // Apraoch - 2 Slightly Optimized by making isSafe() - O(1)
    // This adds the solution preent in board to the actual result
    void addSolution(vector<vector<char>> &board, vector<vector<string>> &result){
        int n = board.size();
        vector<string> temp;

        for(int row=0;row<n;row++){
            string str = "";
            for(int col=0;col<n;col++){
                str.push_back(board[row][col]);
            }
            temp.push_back(str);
        }

        result.push_back(temp);
    }

    // function to check that whetehr it is safe to place queen or not
    bool isSafe(vector<vector<char>> &board,int row,int col,int n){ // o(n)
        int x = row;
        int y = col;

        // check ki is puri row mei kahi bhi queen nahi honi chahiye gar hai to place nahi karsakte
        if(mp1[row]==1){
            return false;
        }

        // check ki diagonal 1 me to nahi naa
        if(mp2[row+col]==1){
            return false;
        }

        // check ki diagonal 2 me to nahi naa
        if(mp3[(n-1) + (col-row)]==1){
            return false;
        }

        return true;
    }

    void helper(vector<vector<char>> &board, int col, vector<vector<string>> &result, int n){
        if(col==n){ // base case stop when queen plaed in each column and add the solution in result
            addSolution(board,result);
            return;
        }

        // for ach column fixed traverse in eaceh row to check where can we place the queen safely
        for(int row = 0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]  = 'Q'; // means plave the queen
                // queen placed update the status in map to 1
                mp1[row] = 1;
                mp2[row+col] = 1;
                mp3[(n-1)+(col-row)] = 1;
                helper(board,col+1,result,n);
                // when come back update the status in map to 0 (unplaced now)
                mp1[row] = 0;
                mp2[row+col] = 0;
                mp3[(n-1)+(col-row)] = 0;
                board[row][col] = '.'; // when coming back no remove the queen which we placed
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) { // T.C = O(n!)  S.C = O(n x n)
        vector<vector<string>> result;


        // Board to place the queen
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(board,0,result,n);
        return result;
    }


    /*
    // Apraoch - 1
    // This adds the solution preent in board to the actual result
    void addSolution(vector<vector<char>> &board, vector<vector<string>> &result){
        int n = board.size();
        vector<string> temp;

        for(int row=0;row<n;row++){
            string str = "";
            for(int col=0;col<n;col++){
                str.push_back(board[row][col]);
            }
            temp.push_back(str);
        }

        result.push_back(temp);
    }

    // function to check that whetehr it is safe to place queen or not
    bool isSafe(vector<vector<char>> &board,int row,int col,int n){
        int x = row;
        int y = col;

        // check ki is puri row mei kahi bhi queen nahi honi chahiye gar hai to place nahi karsakte
        while(y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            y--;
        }

        // check ki diagonal 1 me to nahi naa
        int i = row;
        int j = col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }

        // check ki diagonal 2 me to nahi naa
        i = row;
        j = col;
        while(i<n && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void helper(vector<vector<char>> &board, int col, vector<vector<string>> &result, int n){
        if(col==n){ // base case stop when queen plaed in each column and add the solution in result
            addSolution(board,result);
            return;
        }

        // for ach column fixed traverse in eaceh row to check where can we place the queen safely
        for(int row = 0;row<n;row++){
            if(isSafe(board,row,col,n)){
                board[row][col]  = 'Q'; // means plave the queen
                helper(board,col+1,result,n);
                board[row][col] = '.'; // when coming back no remove the queen which we placed
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) { // T.C = O(n!)  S.C = O(n x n)
        vector<vector<string>> result;


        // Board to place the queen
        vector<vector<char>> board(n, vector<char>(n, '.'));
        helper(board,0,result,n);
        return result;
    }
    */
};