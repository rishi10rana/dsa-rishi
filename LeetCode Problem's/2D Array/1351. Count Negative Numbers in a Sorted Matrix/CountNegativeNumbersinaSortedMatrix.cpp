class Solution {
public:
    // Approach 1- Bruteforce
    // T.C = O(m * n)
    // S.C = O(1)
    /*
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] < 0){
                    count++;
                }
            }
        }

        return count;
    }
    */

    // Approach 1 : using Binary Search 
    // T.C = O(m * logn)
    // S.C = O(1)
    // binary search is used to find the first negative number (index) which occurs in row 
    /*
    int binary_search(vector<int>& arr, int n){
        int low = 0;
        int high = n-1;
        int index = n;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] < 0){
                high = mid - 1;
                index = mid;
            }
            else{ // +ve number
                low = mid + 1;
            }
        }

        return index;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        for(int i=0;i<m;i++){ // traverse each row (array) to find total -ve no. in each row
            int negIndex = binary_search(grid[i], n); // first -ve no index in row
            count = count + (n - negIndex); // total -ve in this row added to result
        }
        return count;
    }
    */

    // Approach 1: using upper bound function (prebuilt)
    // same use binary search
    // T.C = O(m * logn)
    // S.C = O(1)
    /*
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0; // stores total -ve nos
        for(auto &row: grid){ // ek ek row ko pakdo
            int negidx = upper_bound(begin(row), end(row), 0, greater<int>()) - begin(row); // first negative element index in row 
            count = count + (n - negidx);
        }

        return count;
    }
    */

    // Optimal Approach
    // using knowledge of row and col soted in desc
    // T.C = O(m + n)
    // S.C = O(1)
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0; // count of -ve nos
        // start from lower left most cell/ element
        int row = m-1;
        int col = 0;
        while(row >= 0 && col < n){
            if(grid[row][col] >= 0){
                col++; // means ye element +ve means isse upar ke elemets bhi +ve means skip this col
            }
            else{ // means -ve no so iss row me jitna -ve nos who count karlo
                count = count + (n - col);
                row--; // then move one row above
            }
        }

        return count;
    }
};