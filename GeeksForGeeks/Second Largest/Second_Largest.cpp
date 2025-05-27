class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        // Time - O(n) , Space - O(1)
        int firstLargest = -1; // to store first largest
        int secondLargest = -1; // to store second largest
        for(int i: arr){ 
            if(i>firstLargest){ // aisa number aaye jo firstlargest se bada ho
                secondLargest = firstLargest;
                firstLargest = i;
            }
            // agar aisa number aaye jo first largest se to bada nahi par second 
            // largest se bada ho par first ke equla naa ho wo check karlena
            else if(i>secondLargest && i!=firstLargest){
                secondLargest = i;
            }
        }
        return secondLargest;
    }
};