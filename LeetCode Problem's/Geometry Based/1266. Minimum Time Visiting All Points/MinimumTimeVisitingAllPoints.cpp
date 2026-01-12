class Solution {
public:
    // T.C = O(n)
    // S.C = O(1)
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();

        // 1 unit distance = 1 sec
        int steps = 0;
        // har points[i] and points[i+1] ke bich ka shortest distance nikal lo aur sum karte raho
        for(int i=0;i<n-1;i++){
            // (x1,y1)
            int x1 = points[i][0];
            int y1 = points[i][1];

            // (x2, y2)
            int x2 = points[i+1][0];
            int y2 = points[i+1][1];

            int dx = abs(x2 - x1);
            int dy = abs(y2 - y1);

            // shortest b/w two points (if diagonal movement allowed)
            // dx yaa dy jo chota hoga wo diagonally move karke cover hojata and rest we need to cover
            // by moving horizontally or vertically
            steps += min(dx, dy) + abs(dy - dx);
        }

        return steps;
    }
};