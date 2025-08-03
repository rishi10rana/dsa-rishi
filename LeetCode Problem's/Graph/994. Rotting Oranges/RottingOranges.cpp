class Solution {
public:

    int r;
    int c;

    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};

    bool valid(int i, int j){
        return (i>=0 && i<r) && (j>=0 && j<c);
    }

    // T.C = O(m * n) S.C = O(m * n)
    int orangesRotting(vector<vector<int>>& grid) {
        
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;

        

        // find karo rotten fruit and pass it in queue to perform bfs on it
        // to make its neighbour rotten
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }

        int timer = 0;
        while(!q.empty()){
            // we are already having first set of rotten fruits which will rot its adjacent
            timer++;
            int current_rotten = q.size();
            while(current_rotten--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                // rot its adjacent
                for(int k=0;k<4;k++){
                    if(valid(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]==1){ // fresh wala mila rot kardo
                        grid[i+row[k]][j+col[k]] = 2;
                        q.push(make_pair(i+row[k], j+col[k]));
                    }
                }
            }
        }

        // check karo koii fresh fruit to nahi bacha
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;  
                }
            }
        }

        if(timer==0){
            return 0; // means koii rotten fruit mila hi nahi 
        }
        return timer - 1;
    }
};