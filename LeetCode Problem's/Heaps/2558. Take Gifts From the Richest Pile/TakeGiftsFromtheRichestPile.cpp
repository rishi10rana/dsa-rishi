class Solution {
public:
    // T.C = O(k * 2logn) = O(klogn)
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n = gifts.size();

        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(gifts[i]);
        }

        int time = 1;
        while(time <= k){
            int gift = pq.top();
            pq.pop();

            int newGift = floor(sqrt(gift));
            pq.push(newGift);
            time++;
        }

        long long total = 0;
        while(!pq.empty()){
            total = total + pq.top();
            pq.pop();
        }

        return total;
    }
};