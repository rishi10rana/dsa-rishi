class Solution {
  public:
    int r;
    int c;
    
    // made for 8 possible movements
    int row[8] = {-1,-1,-1,1,1,1,0,0};
    int col[8] = {-1,0,1,-1,0,1,-1,1};
  
    bool valid(int i, int j){
        return (i>=0 && i<r) && (j>=0 && j<c);
    }
  
    // BFS
    // T.C = O(M * N) S.C = O(M * N)
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        
        r = grid.size();
        c = grid[0].size();
        
        queue<pair<int,int>> q;
        int count = 0;
        // check for the unvisited 1
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='L'){ // 1
                    count++; // ek island mila
                    grid[i][j] = 'W'; // 0
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int newi = q.front().first;
                        int newj = q.front().second;
                        q.pop();
                        
                        // now for each selected node make all its adjacent 8 diretion node 0 if not
                        for(int k=0;k<8;k++){
                            if(valid(newi+row[k],newj+col[k]) && grid[newi+row[k]][newj+col[k]]=='L'){
                                grid[newi+row[k]][newj+col[k]] = 'W'; // 0
                                q.push(make_pair(newi+row[k],newj+col[k]));
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};