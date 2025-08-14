class Solution {
public:

    // Greedy Algorithm
    // T.C = O(m)
    // S.C = O(1)
    int leastInterval(vector<char>& tasks, int n) {
        
        // firs find the freq of all tasks
        vector<int> freq(26, 0);
        int count = 0; // store the highest freq we could get

        for(int i=0;i<tasks.size();i++){
            int index = tasks[i] - 'A';
            freq[index]++;
            // also keep updating the highest freq we can achive or get
            count = max(count, freq[index]);
        }

        // use fromula we derived
        int ans = (count-1) * (n+1);

        // ab jin task ke freq equal thi to count un task ki waajah se 1 add hoga in ans
        for(int i=0;i<26;i++){
            if(freq[i]==count){
                ans++;
            }
        }

        // dekho miimum cycles = "tasks.size()" itni cycle minimum to langenge hi par constarit ki wajah se kabhi kabhi badh jaati

        // par agar humaraa ans is minimm  se bhi kam aa raha tha to hume wahi minimum waala dena padega
        return ans>tasks.size()? ans : tasks.size();
    }
};