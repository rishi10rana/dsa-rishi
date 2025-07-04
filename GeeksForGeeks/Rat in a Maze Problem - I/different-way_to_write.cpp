class Solution {
  public:
   // used to check that moving to newx,newy is safe or not
    bool isSafe(vector<vector<int>>& maze,int newx, int newy,vector<vector<bool>> visited){
        if(newx>=0 && newx<maze.size() && newy>=0 && newy<maze.size() && maze[newx][newy]==1 && visited[newx][newy]==0){
            return true;
        }
        else{
            return false;
        }
    }
  
    void helper(vector<vector<int>>& maze, string output, int srcx, int srcy, vector<vector<bool>> &visited,vector<string> &result){
        // Base Case
        if((srcx==maze.size()-1) && (srcy ==maze.size()-1)){
            result.push_back(output);
            return;
        }
        
        // Move Lexographically from start itself so that no need to sort the final list    
        // 4 Move - D , L , R , U
        
        
        // Done same task using for loop to shorten the code
        // arr - down, left, right, up  
        int arrx[] = {srcx+1,srcx,srcx,srcx-1};
        int arry[] = {srcy,srcy-1,srcy+1,srcy};
        string letter[] = {"D","L","R","U"};
        
        for(int i = 0;i<4;i++){
            if(isSafe(maze,arrx[i],arry[i],visited)){
                visited[srcx][srcy] = 1;
                helper(maze,output+letter[i],arrx[i],arry[i],visited,result);
                visited[srcx][srcy] = 0;
            }
        }
        
        
        /*
        visited[srcx][srcy] = 1; // means humne cuurent srcx srxy visit kar liya ab usse next move dekhrahe
        // Down
        if(isSafe(maze,srcx+1,srcy,visited)){
            // visited[srcx][srcy] = 1;
            helper(maze,output+"D",srcx+1,srcy,visited,result);
            // visited[srcx][srcy] = 0;
        }

        // Left
        if(isSafe(maze,srcx,srcy-1,visited)){
            helper(maze,output+"L",srcx,srcy-1,visited,result);
        }
        
        // Right
        if(isSafe(maze,srcx,srcy+1,visited)){
            helper(maze,output+"R",srcx,srcy+1,visited,result);
        }
        
        // Up
        if(isSafe(maze,srcx-1,srcy,visited)){
            helper(maze,output+"U",srcx-1,srcy,visited,result);
        visited[srcx][srcy] = 0; // means wapis aa rahe hum to jo visted kiya tha usse unvisit kardo
        */
    }   
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> result;
        string output = "";
        int srcx = 0, srcy = 0;
        
        if(maze[srcx][srcy]==0){ 
            return result;
            
        }
        
        vector<vector<bool>> visited(n,vector<bool>(n,0)); // intitially all 0
        
        helper(maze,output,srcx,srcy,visited,result);
        return result;
    }
};