class Solution {
public:
    // Method 1 - Simple Sorting
    // T.C = O(nlogn) + O(n) + O(m): worst case all box needed = O(nlogn)
    // S.C = O(1)
    /*
    // custom comparrator sort in descending order
    static bool comparator(int a, int b){
        return a > b;
    }

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        // sabse phela total apples nikal lo jinhe boxes mei store karna
        int total_apple = 0;
        for(int i=0;i<n;i++){
            total_apple = total_apple + apple[i];
        }

        // sort boxes taki boxes jinki capacity sabse jyada usmei apples store karde 
        // taki minimum no of box lage
        sort(capacity.begin(), capacity.end(), comparator);

        int count = 0; // count min boxes needed
        int sum = 0;
        for(int i=0;i<m;i++){
            sum = sum + capacity[i];
            count++;
            if(sum >= total_apple){ // box ki apple store kare ki capacity gar total apple ke equal
                // ya usse jyada hogayi means ab aur box nahi chahiye immedialty stop 
                break;
            }
        }

        return count;
    }
    */

    // Method 2 - using count sort
    // T.C = O(n) + O(n) + O(m) = O(n) linear time
    // S.C = O(m) + O(k+1) : due to count sort
    /*
    */
    void count_sort(vector<int>& capacity, int m){
        int k = INT_MIN;
        for(int i=0;i<m;i++){
            k = max(k, capacity[i]);
        }

        vector<int> count(k+1, 0);

        vector<int> b(m);

        // store in count[] array -  the no of times each element occur 
        for(int i=0;i<m;i++){
            count[capacity[i]]++;
        }

        // update the count array to store postion of elements 
        // as we need to sort in descending order we will strat from last
        for(int i=k-1;i>=0;i--){
            count[i] = count[i] + count[i+1];
        }

        // now store the elemetns in sorted order in b[] array 
        // using the positions we stored in count array
        // scan the original array from end
        for(int j=m-1;j>=0;j--){
            b[--count[capacity[j]]] = capacity[j];
        }

        // copy these sorted elements from b[] to original capacity array
        for(int i=0;i<m;i++){
            capacity[i] = b[i];
        }
    }

    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();

        int total_apple = 0;
        for(int num: apple){
            total_apple = total_apple + num;
        }

        // sort the capacity array using count sort (descending order)
        count_sort(capacity, m);

        // same approach total apple wala
        int count = 0;
        int i = 0;
        while(total_apple > 0){
            total_apple = total_apple - capacity[i];
            count++;
            i++;
        }

        return count;
    }
};