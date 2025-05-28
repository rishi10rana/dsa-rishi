class Solution {
public:
    // Approach - 1 Brute Force , T.C = O(n^2) , S.C = O(1)
    // int maxArea(vector<int>& height) {
    //     // area = height * width
    //     // height = min(height[i],height[j])
    //     // width = height[j] - height[i]
    //     int maxArea = 0;

    //     // ek pillar ko choose karke aage saroo se compare karke area nikalte aur max area update karte
    //     for(int i=0;i<height.size();i++){
    //         for(int j=i+1;j<height.size();j++){
    //             int w = j - i;
    //             // do pillar jo select kiya humne unmei se humesha chota wala 
    //             //ki height conside karenga
    //             int h = min(height[i],height[j]); 
    //             int area = w * h;
    //             maxArea = max(maxArea,area);
    //         }
    //     }
    //     return maxArea;
    // }

    int maxArea(vector<int>& height) {
        // area = height * width
        // height = min(height[i],height[j])
        // width = height[j] - height[i]

        // Approach 2 : 2 Pointer , T.C = O(n) , S.C = O(1)
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0; // to store maximum area

        while(left<right){ 
            int h = min(height[left],height[right]); // height humesha equal hoti two pillar ka jo min wala hota
            int w = right - left; // find width
            int area = h * w;
            maxArea = max(maxArea,area); // update max area in it

            // Deciding which pointer to move
            if(height[left]<height[right]){
                // left ki height agar choti hai to left badha do taki area shayad badhsake
                left++;
            }
            else{
                // warna right chota hai to right badha do
                right--;
            }
        }
        return maxArea;   
    }
};