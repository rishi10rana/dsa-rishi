class Solution {
public:
    // Greedy Algorithm
    // T.C = O(nlogn) + O(n * logn) = O(nlogn)
    // S.C = O(n)
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // no of tasks
        int n = tasks.size();

        // har ek task ke sath uska task no or index bhi attach kardo
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }

        // sort the tasks based on their enqueue time
        // by default the first value of each vector inside array will be used for sorting ascending
        sort(tasks.begin(), tasks.end());

        // initialze timer from the enqueue time of first task
        long long timer = tasks[0][0];

        // to track selected task
        int i = 0;

        // we used min heap as we want to get those job first whose processing time is less
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq ;
        vector<int> ans;

        while(!pq.empty() || i < n){
            // push all the tasks in the min heap whose enqueue time <= timer
            while(i<n && tasks[i][0] <= timer){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // if min heap is empty - direct next time par jump karajao
            if(pq.empty()){
                timer = tasks[i][0];
            }

            // min heap not empty
            else{
                ans.push_back(pq.top().second);
                timer = timer + pq.top().first;
                pq.pop();
            }
        }

        return ans;
    }
};