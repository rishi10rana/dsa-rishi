class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // total rows and cols
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Maintain some index's
        int rowIndex = 0;
        int colIndex = cols - 1;

        // Run Binary Search
        while(rowIndex < rows && colIndex>=0){
            // mid ki jagah yaha ye nikalo bus
            int element = matrix[rowIndex][colIndex];

            // matlab target mil gaya
            if(element==target){
                return true;
            }

            // matlab target ab iss row me to nahi milega next row mei ho shayad
            else if(element<target){
                rowIndex++;
            }

            // matlab target abb is column mei to nahi ho sakta shyad ek column piche jana hoga
            else if(element>target){
                colIndex--;
            }
        }

        // target mila hi nahi
        return false;
    }
};