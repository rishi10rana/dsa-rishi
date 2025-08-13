bool comp(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    // Greedy Algorithm
    // T.C = O(nlogn + n) = O(nlogn)
    // S.C = O(1)
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // no of intervals
        int n = intervals.size();

        // sort the intervals based on their endtime ascending
        sort(intervals.begin(), intervals.end(), comp);

        int countToRemove = 0;
        int prevEnd = INT_MIN;

        for(int i=0;i<n;i++){
            if(prevEnd <= intervals[i][0]){ // means non overaping interval we can take it
                prevEnd = intervals[i][1];
                continue;
            }
            else{ // means overlapping we cant take it
                countToRemove++;
            }
        }

        return countToRemove;
    }
};