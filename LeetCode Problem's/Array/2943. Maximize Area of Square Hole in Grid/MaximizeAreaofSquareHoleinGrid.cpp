class Solution {
public:
    // T.C = O(NlogN + MlogM + N + M)
    // N = no of bars in hBars
    // M = no of bars in vBars
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        // sort the hbars and vbars input
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        // length of longest consecutive hBars and vBars we can remove
        int maxConsecutiveHBars = 1;
        int maxConsecutiveVBars = 1;

        // find the length of longest consecutive horizontal bars we can remove
        int currConsecutiveHBars = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1){
                currConsecutiveHBars++;
            }
            else{
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBars = max(maxConsecutiveHBars, currConsecutiveHBars);
        }

        // find the length of longest consecutive vertical bars we can remove
        int currConsecutiveVBars = 1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i] - vBars[i-1] == 1){
                currConsecutiveVBars++;
            }
            else{
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBars = max(maxConsecutiveVBars, currConsecutiveVBars);
        }

        // we remove x bars then we can get x+1 width or height
        // we will consider the minimum of  maxConsecutive Hbar and Vbar
        // as square width and height should be same
        //  we can reduce the larger one to match the smaller one
        int side = min(maxConsecutiveHBars, maxConsecutiveVBars) + 1;
        return side*side;
    }
};