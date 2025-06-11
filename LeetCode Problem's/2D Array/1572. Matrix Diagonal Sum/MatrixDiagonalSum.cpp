class Solution {
public:
    // T.C = O(n) , S.C = O(1)
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();

        /*
        // calculate sum for primary diagonal
        int i=0, j = 0;
        while(i<n && j<n){
            sum += mat[i][j];
            i++;
            j++;
        }
        // calculate sum for secondary diagonal
        i=0;j=n-1;
        while(i<n && j>=0){
            sum += mat[i][j];
            i++;
            j--;
        }
        */

        // To do problem in single loop
        for(int i=0;i<n;i++){ // access rows as they always increase
            // for primary diagonal i==j 
            sum = sum + mat[i][i];
            // for secondary diagonal i==n-1-i
            sum = sum + mat[i][n-1-i];
        }

        if(n%2!=0){ // means odd subtract on element as it is being calculated twice
            sum = sum - mat[n/2][n/2];
        }

        return sum;
    }
};