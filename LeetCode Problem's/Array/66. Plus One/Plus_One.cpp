class Solution {
public:
    // T.C = O(n) , S.C = O(1)
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> result; // To store the result array
        
        int carry = 1; // to handle carrys initially kept as we need to add 1 to our number
        for(int i=n-1;i>=0;i--){ // start from right
            int sum = digits[i] + carry; 
            carry = sum/10; // finds carry if possbile otherwise becomes 0
            sum = sum%10; // gives the required digit that need to be added to result
            result.push_back(sum);
        }
        // if any carry remians at last then add it also ex - 9 + 1 = 10
        if(carry!=0){
            result.push_back(carry);
        }

        // as answer will come in wrong order so reverse the result we got
        int i = 0;
        int j = result.size()-1;
        while(i<=j){
            swap(result[i],result[j]);
            i++;
            j--;
        }
        return result;
    }
};