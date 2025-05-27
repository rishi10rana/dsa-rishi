class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Approach - 2 pointer , T.C = O(n)
        int i = 0;
        int j = numbers.size()-1;

        // To store index1 and index2 (i.e answer)
        vector<int> ans;

        while(i<j){
            int sum = numbers[i] + numbers[j]; // find sum
            if(sum==target){ // matlab index mil gaye jo answer denga to add them in vector
                ans.push_back(i+1);
                ans.push_back(j+1);
                break; // and stop loop
            }
            else if(sum>target){ // to right se kam karna padega ,tabhi sum reduce hoga todha
                j--;
            }
            else if(sum<target){ // to left side se badhana padega , tabhi sum increase hoga 
                i++;
            }
        }
        // final answer
        return ans;
    }
};