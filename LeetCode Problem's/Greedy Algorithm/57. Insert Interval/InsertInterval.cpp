class Solution {
public:
    // Greedy Algorithm
    // T.C = O(n)
    // S.C = O(1)
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int n = intervals.size();
        vector<vector<int>> result;

        // sabse phela jo interval jo overlap nahi kar rahe unhe result mei daal deta
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        // edge case karte karte las ttak pahuch gaye
        if(i==n){
            result.push_back(newInterval);
            return result;
        }

        // merge the overlapping intervals
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);


        // jo non-overlappijg intervls bache unhe bhi daaldo
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};