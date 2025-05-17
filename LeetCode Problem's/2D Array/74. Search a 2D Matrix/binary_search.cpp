class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows*cols - 1;
        int mid = start + (end-start)/2;

        // Apply Same Binary search like linear array
        while(start<=end){
            // just in 2D array to get mid element we require row and col index specifically
            int element = matrix[mid/cols][mid%cols];

            if(element==target){
                return true;
            }
            else if(element<target){
                start = mid + 1;
            }
            else if(element>target){
                end = mid - 1;
            }

            mid = start + (end-start)/2;
        }
        return false;
    }
};