// User function Template for C++

class Solution {
  public:
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    int r;
    int c;
  
    bool valid(int i, int j){
        return (i>=0 && i<r) && (j>=0 && j<c);
    }
  
    // BFS
    // T.C = O(M*N) S.C = O(M*N)
    int helpaterp(vector<vector<int>> hospital) {
        // code here
        
        r = hospital.size();
        c = hospital[0].size();
        
        
        // initialy check if all wards are empty
        // it will take 0 time to spread covid
        bool check_all_zero = 1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]!=0){
                    check_all_zero = 0;
                }
            }
        }
        if(check_all_zero){
            return 0;
        }
        
        
        
        // as BFS 
        // store coordinate of room
        queue<pair<int,int>> q;
        
        // initailly jitna corona wale hai unhe q mei daalde
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==2){
                    q.push(make_pair(i,j));
                }
            }
        }
        int timer = 0;
        while(!q.empty()){
            timer++;
            int curr_patient = q.size();   // phela itna baakiyo ko spread karenga
            while(curr_patient--){
                // ab ye selected patient apne neighbours ko infect karega
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // check up , down, left ,right
                for(int k=0;k<4;k++){
                    
                    // uninfected patient mil gaya infect kardo usse
                    if(valid(i+row[k],j+col[k]) && hospital[i+row[k]][j+col[k]]==1){ 
                        hospital[i+row[k]][j+col[k]] = 2;
                        q.push(make_pair(i+row[k],j+col[k]));
                    }
                }
            }
        }
        
        // bahar aakar check karlo ki koii 1 to nahi bach gaya 2d hosptal mei
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(hospital[i][j]==1){
                    return -1;  // means sab infected nahi huee
                }
            }
        }
        
        // agar sad sahi to sab infected ho gaye time return kardo
        return timer-1;   // ek extra time hota usse remove kardo
    }
};
