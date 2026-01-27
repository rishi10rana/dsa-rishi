class Solution {
public:
    // T.C = O(nlogn + n) = O(nlogn)
    // S.C = O(1)
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minAbsDiff = INT_MAX; // the min abs diff we found in array
        for(int i=1;i<n;i++){
            minAbsDiff = min(minAbsDiff, abs(arr[i] - arr[i-1]));
        }

        vector<vector<int>> result; // store all pairs we have the min abs diff
        for(int i=1;i<n;i++){
            vector<int> pair(2);
            int d = abs(arr[i] - arr[i-1]);
            if(d == minAbsDiff){
                pair[0] = arr[i-1];
                pair[1] = arr[i];
                result.push_back(pair);
            }
        }

        return result;
    }
};