class Solution {
public:
    // T.C = O(n)
    int maxProfit(vector<int>& prices) {
        int lowestPrice = prices[0]; // ek lowest price phela se maintain rakho
        int maxProfit = 0; // to store max profit

        // traverse in array
        for(int i=1;i<prices.size();i++){
            // check karo agar koii bada number aaye than lowerstPrice , too profit nikal lo
            if(prices[i]>lowestPrice){
                int profit = prices[i] - lowestPrice;
                maxProfit = max(profit,maxProfit);
            }
            // har bar net price pe move karne se phela check karlo agar koii aur jyada low buying price
            // mil raha to lowest price update kardo
            lowestPrice = min(prices[i],lowestPrice); 
        }
        return maxProfit;
    }
};