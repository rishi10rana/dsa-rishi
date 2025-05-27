class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Use 2 Pointer but one extra
        int low = 0;
        int high = nums.size()-1;
        int mid = 0; // use this pointer for traversing in array

        while(mid<=high){
            // agar 0 encounter hua to swap kardo with left and mid aur low ko bada do
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            // agar 1 encounter hua to khuch mat karna
            else if(nums[mid]==1){
                mid++;
            }
            // agar 2 encounter hua to 2 ko high se swap kardo aur high ek kam kardo (kykuki high mei 
            // alraeady 2 hota hai kafi bar isliya mid na incremnet karo kyuki shayad mid mei 
            // wapis swap hokar 2 hi aaye to high decremnt kardo aur fhir check karo)
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};