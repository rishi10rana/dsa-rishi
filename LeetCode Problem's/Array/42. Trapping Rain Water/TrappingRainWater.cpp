class Solution {
public:
    // Approach 1 - Array Preprocessing - creating some new arrays to store some data
    // T.C = O(n) , S.C = O(n)
    // int trap(vector<int>& height) {
    //     int n = height.size();
    //     // an array to store the max height of pillar which is on left side of the ith index 
    //     int *left = new int[n]; 
    //     // an array to store the max height of pillar which is on right side of the ith index 
    //     int *right = new int[n];

    //     left[0] = height[0];
    //     for(int i=1;i<n;i++){ // find leftmost height  for each ith index
    //         left[i] = max(left[i-1],height[i]);
    //     }

    //     right[n-1] = height[n-1];
    //     for(int i=n-2;i>=0;i--){ // find rightmost height t for each ith index
    //         right[i] = max(right[i+1],height[i]);
    //     } 

    //     // traverse through each ith pillar in height[] array to calculate water each ith pillar can store
    //     // agar kisi "i"th index ke liya niklana hai kitna water store kar raha?
    //     // hume us "i"th index kke left aur right mei usse bade height hone chahiye 
    //     int totalWater = 0;
    //     for(int i=0;i<height.size();i++){
    //         totalWater = totalWater + (min(left[i],right[i]) - height[i]);
    //     }
        
    //     return totalWater;
    // }

    // Optimal Approach 2 - 2 Pointer , T.C = O(n) , S.C = O(1)
    int trap(vector<int>& height) {
        int i = 0;
        int j= height.size()-1;
        // Some Variables store left max height and right max
        int leftMost = 0;
        int rightMost = 0;
        int sum = 0;

        while(i<=j){
            // matlab left pillar chota hai , matlab is "i" ke liya right mei to bada pillar 
            // hai ye confirm hai
            if(height[i]<=height[j]){ 
                // ye check karta ki left mei bhi hai kya agar nahi to leftMost ko update kardo
                if(height[i]>=leftMost) leftMost = height[i]; 
                // agar left mei bhi bhi bada pillar hai to yaha water store kar sakte
                else sum+= leftMost - height[i];
                i++;
            }

            // matlab right pillar chota hai , matlab is "j" ke liya left mei to bada pillar 
            // hai ye confirm hai
            else{ // height[i]>height[j] now deal with right part
                // ye check karta ki right mei bhi hai kya agar nahi to rightMost ko update kardo
                if(height[j]>=rightMost) rightMost = height[j ];
                // agar right mei bhi bhi bada pillar hai to yaha water store kar sakte
                else sum+= rightMost - height[j];
                j--;
            }
        }
        return sum; 
    }
};