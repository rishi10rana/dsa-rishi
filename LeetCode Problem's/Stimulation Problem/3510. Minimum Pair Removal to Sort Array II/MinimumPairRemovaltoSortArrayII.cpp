class Solution {
public:
    // T.C = O((n-1).logn)
    // S.C = O(n)
    typedef long long ll; // give a custom name to type long long
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        // {a, b, c, d} -> {a, b+c, d}
        vector<ll> temp(n); // sum of pair can go long long

        for(int i=0;i<n;i++)
            temp[i] = nums[i];

        set<pair<ll, int>> minPairSet;
        vector<int> prevIndex(n);
        vector<int> nextIndex(n);

        // update the next and prev index
        for(int i=0;i<n;i++){
            nextIndex[i] = i+1;
            prevIndex[i] = i-1;
        }

        int badPairs = 0;
        // also store the sum of adjacent pairs in set
        for(int i=0;i<n-1;i++){
            minPairSet.insert({temp[i] + temp[i+1], i});
            if(temp[i] > temp[i+1]){
                badPairs++;
            }
        }

        int operations = 0;
        // do the work till bad pairs exist
        while(badPairs > 0){
            // consider the pair with min sum
            int first = minPairSet.begin()->second;
            int second = nextIndex[first];

            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            // considered this pair
            minPairSet.erase(begin(minPairSet)); // logn

            // check if this removed pair was bad
            if(temp[first] > temp[second])
                badPairs--;

            // handle left pair (d, (a,b))
            if(first_left >= 0){
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]){
                    badPairs--;
                }
                else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]){
                    badPairs++;
                }
            }

            // handle right pair ((a,b), d)
            if(second_right < n){
                if(temp[second_right] < temp[second] && temp[second_right] >= temp[first] + temp[second]){
                    badPairs--;
                }
                else if(temp[second_right] >= temp[second] && temp[second_right] < temp[first] + temp[second]){
                    badPairs++;
                }
            }

            // remove and add new pairs
            if(first_left >= 0){
                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left}); // logn
            }

            if(second_right < n){
                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});
                prevIndex[second_right] = first;
            }

            // update index's and add the removed pair sum
            nextIndex[first] = second_right;
            temp[first] = temp[first] + temp[second];

            operations++;
        }

        return operations;
    }
};