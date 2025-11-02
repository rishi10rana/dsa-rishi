class Solution {
public:
    // Maths Based
    // T.C = O(n)   S.C = O(1)
    int totalMoney(int n) {
        
        int total = 0;
        int moneytoAdd = 1; // initially $1
        int firstMonday = 1;
        for(int i=1;i<=n;i++){
            if(i!=1 && i % 7 == 1){ // means came again on monday
                // reset
                moneytoAdd = firstMonday + 1;
                firstMonday++;
            }
            total = total + moneytoAdd;
            moneytoAdd++;
        }

        return total;
    }
};