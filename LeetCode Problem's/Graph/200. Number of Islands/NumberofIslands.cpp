class Solution {
public:

    int r;
    int c;

    int rows[4] = {-1,1,0,0};
    int cols[4] = {0,0,-1,1}; 

    bool valid(int i, int j){
        return (i>=0 && i<r) && (j>=0 && j<c);
    }

    int numIslands(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();

        queue<pair<int,int>> q;
        int count = 0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    q.push({i,j});
                    count++;
                    grid[i][j] = '0';

                    // BFS
                    while(!q.empty()){
                        int newi = q.front().first;
                        int newj = q.front().second;
                        q.pop();

                        // move in all 4 directions
                        for(int k=0;k<4;k++){
                            if(valid(newi+rows[k], newj+cols[k]) && grid[newi+rows[k]][newj+cols[k]] == '1'){
                                grid[newi+rows[k]][newj+cols[k]] = '0';
                                q.push({newi+rows[k], newj+cols[k]});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};