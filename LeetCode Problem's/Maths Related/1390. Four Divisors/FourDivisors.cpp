class Solution {
public:
    // Bruteforce - TLE
    /*
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int result = 0; // to store sum of all valid integers which have 4 divisors
        for(int i=0;i<n;i++){ // pick one integer
            int sum = 0;
            int count = 0;
            int value = nums[i];
            for(int j=1;j<=value;j++){ // check its divisor and track thier sum
                if(value % j == 0){
                    sum += j;
                    count++;
                }
            }
            if(count == 4){ // if the count of no of divisor of an integer exactly 4 then consider
                // that sum
                result = result + sum;
            }
        }
        return result;
    }
    */

    // Approach
    // T.C = O(n * sqrt(num))
    // S.C = O(1)
    int FourDivisorSum(int num){
        // factors (divisors) of a number always exists in pair
        // like 21 % 1 = 0 means 1 is divisor of 21 , also 21/1 which is 21 is a divisor.
        // also for number due this we are only need to search for divisor till sqrt(num)
        int divisorCount = 0;
        int sum = 0;
        for(int j=1;j<=sqrt(num);j++){
            if(num % j == 0){ // found a divisor 'j'
                int other = num/j; // other divsor 
                if(other == j){ // perfect square case consider only one divisor
                    divisorCount++;
                    sum += j; 
                }
                else{ // else consider both pair
                    divisorCount += 2;
                    sum += j + other;
                }
                if(divisorCount > 4){ 
                    // at point of time divisor count > 4 means dont consider this integer        
                    break;
                }
            }
        }
        if(divisorCount == 4){
            return sum;
        }
        return 0; // if more than or less than 4 divisor found
    }

    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();

        int result = 0; // total sum of divisors of integers who have exactly 4 divisors
        for(int i=0;i<n;i++){
            // this function will find sum of 4 divisors of a integer
            // if it has exactly 4 divisors other wise returns 0. 
            result = result + FourDivisorSum(nums[i]);
        }
        return result;
    }
};