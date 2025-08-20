class Solution {
public:

    // Greedy Algo
    // T.C = O(n) S.C = O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();

        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<n;i++){
            totalGas+= gas[i];
            totalCost+= cost[i];
        }

        //sabse phela check karlo ki koi valid solution nahi hai kya
        if(totalGas < totalCost){
            return -1; // matlab koii solution exist nahi karta
        }

        int currentFuel = 0;    
        int start = 0;
        for(int i=0;i<n;i++){
            currentFuel += gas[i] - cost[i];
            if(currentFuel < 0){ // matlab aage jaa hi nahi payenga
                // koii aur gas station dekh te ab
                start = i+1;
                currentFuel = 0;
            }
        }

        return start;
    }
};