class Solution {
public:
    // Colouring method
    // Method 1 - BFS , T.C = O(V + E) , S.C = O(V)
    /*
    bool BFS(int node, vector<vector<int>>& adj, vector<int>& colour){
        
        queue<int> q;
        q.push(node);
        // start from 0 so give it a colour 0
        colour[node] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            // check its neighbours
            for(int j=0;j<adj[node].size();j++){
                // color not assigned to it
                if(colour[adj[node][j]]==-1){
                    colour[adj[node][j]] = (colour[node] + 1) % 2;
                    q.push(adj[node][j]);
                }
                // color assigned to it
                else{
                    // node colour and neighbour ka colour same hogaya matlab not bipartite graph
                    if(colour[node] == colour[adj[node][j]]){
                        return 0; // not bipartite
                    }
                }
            }
        }
        // yaha tak aagaye matlab koii dikat nahi aayi boch mei matlab graph is bipartite
        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> colour(V,-1); // -1 menas no colour assigned till now   

        // check color assigned to all nodes - case of disconnected graph
        for(int i=0;i<V;i++){
            if(colour[i]==-1){ // not assigned
                colour[i] = 0;
                if(!BFS(i, graph, colour)){ // check karega is node ki wajah se bipartite hai ki nahi
                    return 0; // dont check further agar ek ki wajah se bhi not bipartite
                }
            }
        }

        // yaha tak aagye matlab all safe
        return 1;
    }
    */


    // Colouring method
    // Method 1 - DFS , T.C = O(V + E) , S.C = O(V)
    bool DFS(int node, vector<vector<int>>& adj, vector<int>& colour){
        
        // check its neighnour
        for(int j=0;j<adj[node].size();j++){
            // colour not assigned 
            if(colour[adj[node][j]]==-1){
                colour[adj[node][j]] = (colour[node] + 1) % 2;
                // call for it now
                if(!DFS(adj[node][j], adj, colour)){ 
                    // agar 1 ddia to koii dikat nahi aage check karte par 0 return kiya 
                    // matlab diret not bipartite bol do

                    return 0;
                }
            }

            // colour assigned
            else{
                // node ka aur neighbour ka colour same - to not bipartite
                if(colour[node]==colour[adj[node][j]]){
                    return 0;
                }

                // else dono ka colour different koii dikkat nahi aage badho
            }
        }

        // kisi node pe aagaye aur uske saree neighbours checked or koii dikat nahi to maltab sahi ha
        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> colour(V,-1); // -1 menas no colour assigned till now  


        // check color assigned to all nodes - case of disconnected graph
        for(int i=0;i<V;i++){
            if(colour[i]==-1){ // not assigned
                colour[i] = 0;
                if(!DFS(i, graph, colour)){ // check karega is node ki wajah se bipartite hai ki nahi
                     // dont check further agar ek ki wajah se bhi not bipartite

                    return 0;
                }
            }
        }

        // yaha tak aagye matlab all safe
        return 1;
    }
};