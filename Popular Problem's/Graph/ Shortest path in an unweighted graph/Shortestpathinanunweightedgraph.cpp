vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// BFS
	// T.C = O(V + E)
	// S.C = O(V + E) + 3V
	
	// create adj list and use 0-based index
	vector<int> adj[n];
	for(int i=0;i<m;i++){
		adj[edges[i].first-1].push_back(edges[i].second-1);
		adj[edges[i].second-1].push_back(edges[i].first-1);
	}

	// decrement them as we are using 0th based indexing
	s--;
	t--;


	// to track parent of each node when visited through shortest path
	vector<int> parent(n, -1);
	// to track node visted or not
	vector<bool> visited(n, 0);

	// BFS
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();

		// look at all its neighbour
		for(int j=0;j<adj[node].size();j++){
			if(visited[adj[node][j]]){
				continue;
			}
			visited[adj[node][j]] = 1;
			q.push(adj[node][j]);

			parent[adj[node][j]] = node;
		}
	}

	// to get the path using parent array
	vector<int> path;

	while(t!=-1){
		path.push_back(t + 1); // as we want answer in 1 based indexing again
		t = parent[t];
	}

	// reverse the path we got
	reverse(path.begin(), path.end());

	return path;
}
