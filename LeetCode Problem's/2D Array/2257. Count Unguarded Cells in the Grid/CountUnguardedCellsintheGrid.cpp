class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'u'));
        queue<pair<int, int>> q;

        for(int i=0;i<guards.size();i++){
            for(int j=0;j<2;j++){
                int x = guards[i][0];
                int y = guards[i][1];
                grid[x][y] = 'G';
                q.push({x, y});
            }
        }

        for(int i=0;i<walls.size();i++){
            for(int j=0;j<2;j++){
                int x = walls[i][0];
                int y = walls[i][1];
                grid[x][y] = 'W';
            }
        }

        while(!q.empty()){
            pair<int, int> cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;

            int newx = x+1;
            int newy = y;
            // down
            while(newx < m){
                if(grid[newx][newy] == 'G' || grid[newx][newy] == 'W'){
                    break;
                }
                grid[newx][newy] = 'g';
                newx++;
            }


            // up
            newx = x-1;
            newy = y;
            while(newx >= 0){
                if(grid[newx][newy] == 'G' || grid[newx][newy] == 'W'){
                    break;
                }
                grid[newx][newy] = 'g';
                newx--;
            }


            // left
            newx = x;
            newy = y-1;
            while(newy >= 0){
                if(grid[newx][newy] == 'G' || grid[newx][newy] == 'W'){
                    break;
                }
                grid[newx][newy] = 'g';
                newy--;
            }

            // right
            newx = x;
            newy = y+1;
            while(newy < n){
                if(grid[newx][newy] == 'G' || grid[newx][newy] == 'W'){
                    break;
                }
                grid[newx][newy] = 'g';
                newy++;
            }
        }


        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 'u'){
                    count++;
                }
            }
        }

        return count;
    }
};