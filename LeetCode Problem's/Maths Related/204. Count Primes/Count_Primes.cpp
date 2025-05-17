class Solution {
public:
    // Sieve of Eratosthenes
    int countPrimes(int n) {
        // To store actual count of prime numbers
        int count = 0;

        // Create a vector of all numbers from 0-> to n and initially mark all them as true (means all prime)
        vector<bool> prime(n,true);

        // mark 0 and 1 not prime (false)
        if(n>0){
            prime[0] = false;
        }
        if(n>1){
            prime[1] = false;
        }

        // Now terate through each number from i:2 -> n and if "i" is prime increment "count" and mark false all 
        // multiples of that "i" as we know they cant me prime if they are multiples.
        for(int i=2;i<n;i++){
            if(prime[i]){
                count++;
                for(int j=2*i;j<n;j=j+i){
                    prime[j] = false; // mark multiples as non-prime
                }
            }
        }

        return count;
    }
};