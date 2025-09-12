class Solution {
  public:
    // T.C = (N * L) + V^2 + (V + E)
    string findOrder(vector<string> &words) {
        // code here
        
        // first form the adjacenecy list and indegree
        vector<vector<int>> adj(26);
        vector<int> indegree(26, 0);
        
        
        // keeps track of which letters exists in the given words
        vector<bool> exists(26, 0);
        for(int i = 0;i<words.size();i++){
            for(char c: words[i]){
                exists[c - 'a'] = 1;
            }
        }
        
        
        // for, the adjacency list and indegree
        for(int i=0;i<words.size()-1;i++){
            string str1 = words[i] , str2 = words[i+1];
            int j = 0; // to track str1
            int k= 0; // to track str2
            
            while(j<str1.size() && k<str2.size() && str1[j]==str2[k]){
                j++;
                k++;
            }
            
            
            if(j == str1.size()){
                continue;
            }
            // str2 is the prefix of str1 and is coming after it --> invalid case
            if(j < str1.size() && k == str2.size()){
                return "";
            }
            
            adj[str1[j]-'a'].push_back(str2[k]-'a');
            indegree[str2[k]-'a']++;
        }
        
        queue<int> q;
        
        // jinko indegree 0 hai adn wo exist karte hai unhe queue mei daalo
        for(int i=0;i<indegree.size();i++){
            if(exists[i] && indegree[i]==0){
                q.push(i);
            }
        }
        
        string ans = "";
        // apply kahns algo
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            char c = 'a' + node;
            ans = ans + c;
            
            // iske neigbhours ki indegree ko decremet karo
            for(int j=0;j<adj[node].size();j++){
                indegree[adj[node][j]]--;
                if(indegree[adj[node][j]]==0){
                    q.push(adj[node][j]);
                }
            }
        }
        
        // check koii indegree 1 to nahi reh gayi (means we cant get valid order)
        for(int i=0;i<26;i++){
            if(exists[i] && indegree[i] != 0){
                return "";
            }
        }
        
        // agar order valid / possible hai to return the order
        return ans;
        
    }
};