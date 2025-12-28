class Solution {
public:
    // My Code
    /*
    static bool comparator(int a, int b){
        return a > b;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();

        sort(happiness.begin(), happiness.end(), comparator);

        int count = 0;
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(count == k){
                break;
            }
            if(!(happiness[i] - count < 0)) sum = sum + (happiness[i] - count);
            count++;
        }

        return sum;
    }
    */

    // Approach - Using Sorting
    // T.C = O(nlogn + n) = O(nlogn)
    // S.C = O(1)
    /*
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort happiness in desc order
        sort(happiness.begin(), happiness.end(), greater<int>());

        int count = 0; // no of children picked till now
        long long result = 0;
        // fill pick first k children which give max happy value
        for(int i=0;i<k;i++){
            // each time pick children minus the appropriate value (but dont minus if already happiness[i] value became 0)
            result = result + max(happiness[i] - count, 0);
            count++;
        }

        return result;
    }
    */

    // Approach - Using Max Heap
    // T.C = O(nlogn) + O(n)
    // S.C = O(n)
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // max heap (to always get max happy children at top)
        priority_queue<int> pq;

        // fill max heap
        for(int& num: happiness){
            pq.push(num);
        }

        int count = 0; // no of children picked till now
        long long result = 0;
        // fill pick first k children which give max happy value
        for(int i=0;i<k;i++){
            // each time pick children minus the appropriate value (but dont minus if already happiness[i] value became 0)
            result = result + max(pq.top() - count, 0);
            count++;
            pq.pop();
        }

        return result;
    }
};