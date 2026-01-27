class Solution {
public:
    // Problem - Binary search on answer (with precision)
    // T.C = O(log(high - low) * n)
    // S.C = O(1)
    bool check(vector<vector<int>>& squares, double mid_y, double total_area){

        double bottom_area = 0.00000;
        for(auto& square: squares){
            double y = square[1];
            double l = square[2];

            double bot_y = y; 
            double top_y = y + l;
            if(mid_y >= top_y){
                // means this whole sqaure is part of bottom area
                bottom_area += (l * l);
            }
            else if(mid_y > bot_y){
                // means mid_y intersects the square (means square only a part will come in bottom area)
                bottom_area += (l * (mid_y - bot_y));
            }
            // else case means the square is not part of the bottom area
        }

        return bottom_area >= total_area/2.0;
    }
    double separateSquares(vector<vector<int>>& squares) {
        
        double total_area = 0.00000;
        double low = INT_MAX; // min y coordinate 
        double high = INT_MIN;  // max y coordinate

        // find total_area of all squares and find range for searching y
        for(auto& square : squares){
            double x = square[0];
            double y = square[1];
            double l = square[2];

            total_area += (l*l);
            low = min(low, y);
            high = max(high, y+l);
        }

        // apply binary search to find y
        double result_y = 0.00000;

        while(high - low > 1e-5){
            double mid_y = low + (high-low)/2;
            result_y = mid_y;

            // if bottom_area >= total_area/2
            if(check(squares, mid_y, total_area)){
                // move dowm
                high = mid_y;
            }
            else{ // bottom area < total_area/2
                // up
                low = mid_y;
            }
        }

        return result_y;
    }
};