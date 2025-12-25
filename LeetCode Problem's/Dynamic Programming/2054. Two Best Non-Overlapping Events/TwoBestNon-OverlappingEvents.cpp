class Solution {
public:
    // Approach 1
    // Bruteforce
    // T.C = O(n^2)
    // S.C = O(1)
    /*
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        int maxsum = INT_MIN;
        for(int i=0;i<n;i++){ // pick 1st event
            int val = events[i][2];
            maxsum = max(maxsum, val); // necessary to update maxsum if only 1 event choosen
            for(int j=0;j<n;j++){ // pick 2nd event if possible
                if(i == j) continue; // skip same events
                if(!(events[j][0] > events[i][1] || events[j][1] < events[i][0])){ // skip overlapping events
                    continue;
                }
                maxsum = max(maxsum, val + events[j][2]);
            }
        }

        return maxsum;
    }
    */

    // simple recursion gives TLE
    // T.C = O(2^n)

    // Recursion + Memonize
    // T.C = O(nlogn) + O(n * 3)
    // S.C = O(n * 3) + O(recursion stack)
    int n;
    int dp[100001][3];   // n  // 0 1 2 count possible for event

    // binary search help to found upper bound here
    // upper bound here means previous event jo take kiya ab hume aisa event dundhna hoga
    // jiska starttime previous event ke endtime se just badha ho (closest event) to ensure no overlapping
    int binarySearch(vector<vector<int>>& events, int endtime){
        int l = 0;
        int r = n - 1;
        int result = n; // agar koii event nahi mila too nth index bhejdenga taki function call out of range
        // index ke liya jayee

        while(l <= r){
            int mid = l + (r - l)/2;
            if(events[mid][0] > endtime){ // psossible event found store index but lets see left mei shayad
            // aur closest matching event mil jayee
                result = mid;
                r = mid - 1;
            }
            else{ // not possible event mila
                // lets see on right (left mei to nahi milega )
                l = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& events, int i, int count){
        // base case
        if(count == 2 || i >= n){
            // agar already 2 eevent choose karliya hoo ya out of range ho gya index means cant choose more
            // events now so value 0
            return 0;
        }
        if(dp[i][count] != -1){
            return dp[i][count];
        }

        // har event ke paas two choice hai
        // take event or skip
        int skip = solve(events, i+1, count); // simple consider next event
        
        // taking this event means ab next pssobile event jo le sakte uska index binary search se 
        // dundh kar bhejna hoga
        int next_valid_index = binarySearch(events, events[i][1]);
        // taken event lets see next possible event
        int take = events[i][2] + solve(events, next_valid_index, count+1);

        return dp[i][count] = max(take, skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();

        // initialize dp
        memset(dp, -1, sizeof(dp));

        // sort the intervals events based on start time
        sort(events.begin(), events.end());

        return solve(events, 0, 0);
    }
};