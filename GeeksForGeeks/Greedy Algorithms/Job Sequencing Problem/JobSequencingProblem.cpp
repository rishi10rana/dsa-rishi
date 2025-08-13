
bool comp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

// help karta to find the slot jaha par place kars ssakte job ko
int find(int num, vector<int>& parent){
    // case
    if(num == parent[num]){
        return num;
    }
    
    return parent[num] = find(parent[num], parent);
}

class Solution {
  public:
  
    // Greedy Algorithm
    // T.C = O(NlogN) + O(N)
    // S.C = O(N)
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int N = deadline.size();
        
        vector<pair<int,int>> jobs;
        for(int i=0;i<N;i++){
            jobs.push_back(make_pair(deadline[i], profit[i]));
        }
        
        // sort the jobs based on profit (descending)
        sort(jobs.begin(), jobs.end(), comp);
        
        int maxDeadline = INT_MIN;
        for(int i=0;i<N;i++){
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        // ye array store karega kon kon se slots free hai jaha par jobs ko assgin kar sakte based on their deadline
        vector<int> parent(maxDeadline + 1);
     
        // initially saree slots khali honge to usi jagah par jobs aaign kar sakte
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        
        // ab ek ek job select karo aur find karo kaha unhe kin slot mei place kar sakte
        vector<int> ans(2, 0);
        
        for(int i=0;i<N;i++){
            
            int slot = find(jobs[i].first, parent);
            // agar slot 0 aaya matlab mei job ko nahi kar sakta
            if(slot > 0){ // means mei iss job ko karsakta 
                ans[0]++;
                ans[1]+= jobs[i].second;
                parent[slot] = parent[slot] - 1;
            }
        }
        
        return ans;
    }
};


/*
// TLE dega yeeeeeeeeeeeee
bool comp(pair<int,int> a, pair<int ,int> b){
    return a.second > b.second; // if not true then it will exchange both values
}

class Solution {
  public:
  
    // T.C = O(NlogN + N^2)
    // S.C = O(N)
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        
        int N = deadline.size();
        
        vector<pair<int ,int>> jobs;
        for(int i=0;i<N;i++){
            jobs.push_back(make_pair(deadline[i], profit[i]));
        }
        
        // sort jobs based on their profits (descending order)
        sort(jobs.begin(), jobs.end(), comp);
        
        // ek vector banao jisme jobs ko place karoge
        int maxDeadline = INT_MIN;
        for(int i=0;i<N;i++){
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        vector<bool> task(maxDeadline + 1, 0);
        vector<int> ans(2, 0); //stores the no of jobs and max profit
        
        for(int i=0;i<N;i++){
            
            for(int j=jobs[i].first; j>0; j--){
                if(!task[j]){
                    task[j] = 1;
                    ans[0]++;
                    ans[1]+= jobs[i].second;
                    break;
                }
            }
        }
        
        return ans;
    }
};
*/