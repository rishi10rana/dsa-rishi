class Solution {
public:
    // Approach 1: sime traverse inside the selected square to check sum
    // T.C = O(m*n * min(m,n) * m*n)
    // S.C = O(1)
    /*
    int findSum(vector<vector<int>>& mat,int x1, int y1, int x2, int y2){

        int sum = 0;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                sum = sum + mat[i][j];
            }
        }
        return sum;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        int bestSide = 0;
        // try all points and find all possible squares we can take from their using offset
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int offset=0;offset<min(m-i,n-j);offset++){
                    // offset se current square ka oppsite point mil jaata
                    int r2 = i + offset;
                    int c2 = j + offset;

                    // square ka sum check karo
                    int val = findSum(mat, i, j, r2, c2);
                    if(val <= threshold){
                        bestSide = max(bestSide, offset + 1);
                    }
                    else{ // ab isse bada square check karne ka koii fayda nahi it will not pass condition
                        break;
                    }
                }
            }
        }
        return bestSide;
    }
    */

    // Approach 2: to find a sub grid sum of a matrix using 2D prefixsum array
    // T.C = O(m*n * min(m,n) * O(1)) + O(m*n)
    // S.C = O(m*n)
    /*
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        // 2d prefix array
        // prefixsum[i][j] matlab top left corner (0,0) se lekar (i,j) ke elements ka sum
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefixSum[i][j] = ((i > 0) ? prefixSum[i-1][j] : 0) 
                                + ((j > 0) ? prefixSum[i][j-1] : 0) 
                                - ((i > 0 && j > 0) ? prefixSum[i-1][j-1] : 0) 
                                + mat[i][j];
            }
        }

        // lambda funtion to find sum of sub grid
        auto findSum = [&](int i, int j, int r2, int c2){
            int sum = prefixSum[r2][c2];
            if(i > 0)
                sum = sum - prefixSum[i-1][c2];
            if(j > 0)
                sum = sum - prefixSum[r2][j-1];
            if(i > 0 && j > 0)
                sum = sum + prefixSum[i-1][j-1];

            return sum;
        };

        int bestSide = 0;
        // try all points and find all possible squares we can take from their using offset
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int offset=bestSide;offset<min(m-i,n-j);offset++){
                    // offset se current square ka oppsite point mil jaata
                    int r2 = i + offset;
                    int c2 = j + offset;

                    // square ka sum check karo
                    int val = findSum(i, j, r2, c2);
                    if(val <= threshold){
                        bestSide = max(bestSide, offset + 1);
                    }
                    else{ // ab isse bada square check karne ka koii fayda nahi it will not pass condition
                        break;
                    }
                }
            }
        }
        return bestSide;
    }
    */

    // Approach 3: use binary search to find best side
    // T.C = O(log(min(m,n)) * m*n * O(1)) + O(m*n)
    // S.C = O(m*n)
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        // 2d prefix array
        // prefixsum[i][j] matlab top left corner (0,0) se lekar (i,j) ke elements ka sum
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefixSum[i][j] = ((i > 0) ? prefixSum[i-1][j] : 0) 
                                + ((j > 0) ? prefixSum[i][j-1] : 0) 
                                - ((i > 0 && j > 0) ? prefixSum[i-1][j-1] : 0) 
                                + mat[i][j];
            }
        }

        // lambda funtion to find sum of sub grid
        auto findSum = [&](int i, int j, int r2, int c2){
            int sum = prefixSum[r2][c2];
            if(i > 0)
                sum = sum - prefixSum[i-1][c2];
            if(j > 0)
                sum = sum - prefixSum[r2][j-1];
            if(i > 0 && j > 0)
                sum = sum + prefixSum[i-1][j-1];

            return sum;
        };

        // check function to check kya koii valid sqaure given side ka mil paya kya
        auto check = [&](int side){
            // try all possible points jaha se side length ka square ban sakte
            for(int i=0;i + side - 1<m;i++){
                for(int j=0;j + side - 1<n;j++){
                    // opposite point
                    int r2 = i + (side - 1);
                    int c2 = j + (side - 1);
                    if(findSum(i, j, r2, c2) <= threshold){
                        return true; // found a valid square of length "side"
                    }
                }
            }
            return false;
        };

        // use binary search to decide side
        int low = 1;
        int high = min(m, n);
        int result = 0;    // best side
        while(low <= high){
            int mid = low + (high - low)/ 2;
            if(check(mid)){ // valid square
                result = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return result;
    }
};