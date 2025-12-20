class Solution {
public:
    // T.C = O(n) S.C = O(1)
    long long getDescentPeriods(vector<int>& prices) {
        long long count = 1; // count of contiguous decreseing element we found till now
        long long result = 1;
        long long n = prices.size();

        for(int i=1; i<n; i++){
            if(prices[i-1] - prices[i] == 1){
                count++;
            }
            else{
                count = 1; // reset
            }
            result = result + count;
        }

        return result;
    }
};