class Solution {
public:
    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool valid(int i,int j){
        return (i>=0 && i<r) && (j>=0 && j<c);
    }

    void solve(vector<vector<char>>& board) {
        r = board.size();
        c = board[0].size();


        // use boundary traversal
        // now apply bfs on the boundary nodes where 'O'is present
        // T.C = O(N * M) S.C = O(N*M)
        queue<pair<int, int>> q;
        // first row
        for(int j=0;j<c;j++){
            if(board[0][j]=='O'){
                board[0][j] = 'T';
                q.push(make_pair(0,j));
            }
        }

        // first col
        for(int i=1;i<r;i++){
            if(board[i][0]=='O'){
                board[i][0]='T';
                q.push(make_pair(i,0));
            }
        }

        // last row
        for(int j =1;j<c;j++){
            if(board[r-1][j]=='O'){
                board[r-1][j]='T';
                q.push(make_pair(r-1,j));
            }
        }

        // last col
        for(int i =1;i<r-1;i++){
            if(board[i][c-1]=='O'){
                board[i][c-1]='T';
                q.push(make_pair(i,c-1));
            }
        }

        // jo bhi nodes queue mei hai unpe bfs apply kardo
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            //move in all 4 directions
            for(int k=0;k<4;k++){
                if(valid(i+row[k],j+col[k]) && board[i+row[k]][j+col[k]]=='O'){
                    board[i+row[k]][j+col[k]] ='T';
                    q.push(make_pair(i+row[k],j+col[k]));
                }
            }
        }

        // ab jitna bhi O unhe X banado and jitna bhi T hai unhe O banado
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};