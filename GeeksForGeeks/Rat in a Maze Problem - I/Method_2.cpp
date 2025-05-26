class Solution {
  public:
    // fucntion to check ki iss new position mei move karna safe / sahi hai ki nahi
    bool isSafe(vector<vector<int>> maze,int newx,int newy,vector<vector<int>> visited){
        if((newx>=0 && newx<maze.size()) && (newy>=0 && newy<maze.size()) && visited[newx][newy] == 0 && maze[newx][newy] == 1){
            return true; // sarii condition fullfill matlab tum is new position par jaa sakta ho  
        }
        else{
            return false;
        }
    }
  
    void helper(vector<vector<int>> maze,string output,int srcx,int srcy,vector<string> &ans,vector<vector<int>> visited){
        // Base Case
        if(srcx == maze.size()-1 && srcy == maze.size()-1){
            ans.push_back(output); // pass the formed path in ans
            return; // You reached the Destination Stop Now
        }
        // function mei yaha tak enter kara matlab humne ye coordinate visit karliya
        visited[srcx][srcy] = 1;
        
        // Decide Next Move
        // Left
        int newx = srcx;
        int newy = srcy - 1;
        if(isSafe(maze,newx,newy,visited)){
            output.push_back('L'); // to output mei add kardena isse
            helper(maze,output,newx,newy,ans,visited); // aur call kardena is position mei visited karne ke liya
            output.pop_back(); // jab backtrac karke ke wapis aaoge to output mei se remove kardena
        }
        
        // Up
        newx = srcx - 1;
        newy = srcy;
        if(isSafe(maze,newx,newy,visited)){
            output.push_back('U'); // to output mei add kardena isse
            helper(maze,output,newx,newy,ans,visited); // aur call kardena is position mei visited karne ke liya
            output.pop_back(); // jab backtrac karke ke wapis aaoge to output mei se remove kardena
        }
        
        // Right
        newx = srcx;
        newy = srcy + 1;
        if(isSafe(maze,newx,newy,visited)){
            output.push_back('R'); // to output mei add kardena isse
            helper(maze,output,newx,newy,ans,visited); // aur call kardena is position mei visited karne ke liya
            output.pop_back(); // jab backtrac karke ke wapis aaoge to output mei se remove kardena
        }
        
        // Down
        newx = srcx + 1;
        newy = srcy;
        if(isSafe(maze,newx,newy,visited)){
            output.push_back('D'); // to output mei add kardena isse
            helper(maze,output,newx,newy,ans,visited); // aur call kardena is position mei visited karne ke liya
            output.pop_back(); // jab backtrac karke ke wapis aaoge to output mei se remove kardena
        }
        
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans; // to store all the paths 
        
        if(maze[0][0] == 0){
            return ans; // means src coordinate value is 0 means no path can be made
        }
        
        string output = ""; // help to store the formed path
        vector<vector<int>> visited = maze; // to maintain the locations we have visited
        
        // Initialize all values in visited 2D array to 0
        for(int i=0;i<visited.size();i++){
            for(int j=0;j<visited.size();j++){
                visited[i][j] = 0;
            }
        }
        
        // Coordinates of Src
        int srcx = 0;
        int srcy = 0;
        
        helper(maze,output,srcx,srcy,ans,visited);
        
        // To get answer in lexogrphically sorted order (sorted like in english dictionary)
        sort(ans.begin(),ans.end());
        return ans;
    }
};