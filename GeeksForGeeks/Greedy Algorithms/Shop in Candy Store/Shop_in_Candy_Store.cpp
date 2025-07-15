class Solution {
  public:
    // T.C = O(n) S.C = O(1)
    vector<int> candyStore(vector<int>& candies, int K) {
        // Code here
        
        int n = candies.size();
        // sort the candies prices 
        sort(candies.begin(),candies.end());
    
        // now to get the min amount 
        // kam prices walo ko buy karo aur jyada price walo ko free me lo
        int min = 0;
        int buy = 0;
        int free = n-1;
        while(buy<=free){
            min = min + candies[buy];
            buy++;
            free = free - K;    // as getting k candies for free for buying 1 candy
        }    
        
        
        // to get max amount
        // jyada price walo ko buy karo aur kam price walo ko free mei loo
        int max = 0;
        buy = n-1;
        free = 0;
        while(free<=buy){
            max = max + candies[buy];
            buy--;
            free = free + K;
        }
        
        vector<int> result;
        result.push_back(min);
        result.push_back(max);
        return result;
    }
};