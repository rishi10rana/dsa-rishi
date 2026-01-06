class Solution {
public:
    // T.C = O(n * n)
    // S.C = O(1)
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int smallest = INT_MAX; // to store smallest abs value number 
        int count = 0; // to store count of negative number
        long long abs_sum = 0; // store abs sum of all elements 
        for(int i=0;i<n;i++){   
            for(int j=0;j<n;j++){
                abs_sum = abs_sum + abs(matrix[i][j]); 
                if(matrix[i][j] < 0){ // means -ve no.
                    count++;
                }
                smallest = min(smallest, abs(matrix[i][j]));
            }
        }

        // if grid has total even no of -ve then all those -ve can be made postive 
        // easily by mulitplying adjacent no by -1
        // so the answer will be directly the abs_sum
        if(count % 2 == 0)
            return abs_sum;

        // but if the grid has total odd -ve nos then always 1 element will remain that has to be --ve
        // so we will transfer the -ve symbol to smallest positive no in matrix taki kam se kam minus ho
        // remoce already added smallest no then minus it 
        long long ans = abs_sum - 2 * smallest; 
        return ans;
    }
};