class Solution {
  public:
    void helper(vector<vector<int>> maze, string output, int row, int col, vector<string> &ans){
        // Base Case
        if(row == maze.size()-1 && col == maze.size()-1){
            ans.push_back(output);
            return; // stop
        }
    
        // Processing
        if((row < 0 || col < 0) || row >= maze.size() || col >= maze.size()){
            output.pop_back();
            return;
        }
        else{   
            if(maze[row][col]==0){
                output.pop_back();
                return;
            }
            else{
                maze[row][col] = 0;
            }
        }
        
        helper(maze,output+"L",row,col-1,ans); // Left
        helper(maze,output+"U",row-1,col,ans); // Up
        helper(maze,output+"R",row,col+1,ans); // Right
        helper(maze,output+"D",row+1,col,ans); // Down
    }

    vector<string> ratInMaze(vector<vector<int>> &maze){
        // code here
        vector<string> ans;                  // To store all possible paths
        string output = "";                  // To store a single path
        int row = 0, col = 0;                // To maintain start and current position
        helper(maze, output, row, col, ans); // Function to calculate all paths
        sort(ans.begin(),ans.end());
        return ans;
    }
};