class Solution {
public:
    // T.C = n * (3logn) = O(nlogn)
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();

        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            if(stone1 != stone2){
                int newStone = stone1 - stone2;
                if(newStone) pq.push(newStone);
            }
        }

        if(pq.size() == 1){
            return pq.top();
        }
        return 0;
    }
};